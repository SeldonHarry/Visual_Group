#include "calib_node.hpp"
#include "../include/toml.hpp"
#include <rclcpp/logging.hpp>

calibrate::CalibNode::CalibNode(const rclcpp::NodeOptions& options): Node("calib", options) {
    getdata_from_toml();
    init_subscribe();
    cam_thread_ = std::thread(&CalibNode::save_cam_data, this);
    imu_thread_ = std::thread(&CalibNode::save_imu_data, this);
    init_obj();
    //init_data_test();
    calculate_thread_ = std::thread(&CalibNode::calculate, this);
    find_pix();
    cal_cam_param();
    cal_cam2imu_pose();
}

void calibrate::CalibNode::getdata_from_toml() {
    toml::table data;
    try {
        data = toml::parse_file(toml_path);
    } catch (const toml::parse_error& err) {
        RCLCPP_ERROR_STREAM(this->get_logger(), "Parsing failed:: " << err);
    }
    w = data["calibrate"]["chessboard-width"].value<int>().value();
    h = data["calibrate"]["chessboard-height"].value<int>().value();
    d = data["calibrate"]["chessboard-cell-size-cm"].value<double>().value();
    RCLCPP_INFO_STREAM(this->get_logger(), "chessboard-width=" << w);
    RCLCPP_INFO_STREAM(this->get_logger(), "chessboard-height=" << h);
    RCLCPP_INFO(this->get_logger(), "chessboard-cell-size-cm=%.2f", d);
}

void calibrate::CalibNode::init_subscribe() {
    // 目前没加入同时启动的功能
    // sub中，不要用sleep，速度应由pub自己控制
    RCLCPP_INFO(this->get_logger(), "Cam Sub created!");
    cam_sub_ = image_transport::create_camera_subscription(
        this,
        "image_raw",
        [this](
            const sensor_msgs::msg::Image::ConstSharedPtr& image,
            const sensor_msgs::msg::CameraInfo::ConstSharedPtr& cam_info
            //cam_info以后可能用到，先留着
        ) {
            RCLCPP_INFO_ONCE(this->get_logger(), "Collecting Cam data(sub)...");
            this->img_input = cv_bridge::toCvShare(image, "bgr8")->image;
            this->timestamp = (image->header.stamp).nanosec / 1e6;
            this->size.width = img.cols;
            this->size.height = img.rows;
            this->cam_bt = true;
        },
        "raw"
    );

    RCLCPP_INFO(this->get_logger(), "Imu Sub created!");
    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "imu_data",
        10,
        [this](const sensor_msgs::msg::Imu::ConstSharedPtr imu_data) {
            RCLCPP_INFO_ONCE(this->get_logger(), "Collecting Imu data(sub)...");
            this->q_input[0] = imu_data->orientation.x;
            this->q_input[1] = imu_data->orientation.y;
            this->q_input[2] = imu_data->orientation.z;
            this->q_input[3] = imu_data->orientation.w;
            this->imu_bt = true;
        }
    );
}

void calibrate::CalibNode::init_obj() {
    // 初始化obj，计算世界坐标系中，棋盘格上角点的位置
    obj.resize(w * h);
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            obj[j * w + i] = cv::Point3f(d * i, d * j, 0);
        }
    }
}

void calibrate::CalibNode::save_cam_data() {
    //校验并存储cam原始数据
    RCLCPP_INFO(this->get_logger(), "Cam thread created!");
    while (rclcpp::ok() && cam_cnt < max_cnt) {
        RCLCPP_INFO_ONCE(this->get_logger(), "Waiting for Cam data(thread)!");
        rclcpp::sleep_for(std::chrono::milliseconds(interval));
        if (cam_bt) {
            if (img_input.empty()) {
                RCLCPP_INFO(this->get_logger(), "Empty Img!");
            } else {
                RCLCPP_INFO_ONCE(this->get_logger(), "Saving Cam data...");
                image_seq.emplace_back(img_input);
                timestamp_seq.emplace_back(timestamp);
                cam_cnt++;
            }
        }
        if (cam_cnt > max_cnt || cam_cnt == max_cnt) {
            RCLCPP_INFO(this->get_logger(), "Finish saving Cam data!");
            RCLCPP_INFO_STREAM(this->get_logger(), "Cam cnt=" << imu_cnt);
            cam_finished = true;
        }
    }
}

void calibrate::CalibNode::save_imu_data() {
    //校验并存储imu原始数据
    RCLCPP_INFO(this->get_logger(), "Imu thread created!");
    while (rclcpp::ok() && imu_cnt < max_cnt) {
        RCLCPP_INFO_ONCE(this->get_logger(), "Waiting for Imu data(thread)!");
        rclcpp::sleep_for(std::chrono::milliseconds(interval));
        if (imu_bt) {
            if ((q_input[0] == 0) && (q_input[1] == 0) && (q_input[2] == 0) && (q_input[3] == 0)) {
                RCLCPP_INFO(this->get_logger(), "Empty Quaternion!");
            } else {
                RCLCPP_INFO_ONCE(this->get_logger(), "Saving Imu data...");
                Eigen::Quaternionf q(q_input[0], q_input[1], q_input[2], q_input[3]);
                q_backup = q.matrix().transpose();
                imu_seq.emplace_back(q_backup);
                imu_cnt++;
            }
        }
        if (imu_cnt > max_cnt || imu_cnt == max_cnt) {
            RCLCPP_INFO(this->get_logger(), "Finish saving Imu data!");
            RCLCPP_INFO_STREAM(this->get_logger(), "Imu cnt=" << imu_cnt);
            imu_finished = true;
        }
    }
}

void calibrate::CalibNode::calculate() {
    bool begin = true;
    RCLCPP_INFO(this->get_logger(), "Cal thread created!");
    while (rclcpp::ok() && begin) {
        if (cam_finished && imu_finished) {
            RCLCPP_INFO(this->get_logger(), "Begin calculating!");
            find_pix();
            cal_cam_param();
            cal_cam2imu_pose();
            begin = false;
        }
    }
    RCLCPP_INFO(this->get_logger(), "Calculation finished!");
}

void calibrate::CalibNode::find_pix() {
    RCLCPP_INFO(this->get_logger(), "Start finding pixel!");
    int cnt = 0;
    bool found;
    while (true) {
        cnt++; //限制运行次数
        if (cnt > int(image_seq.size())) {
            break;
        }
        img = image_seq[cnt - 1];
        // 转换为灰度图像
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        // 棋盘角点检测
        corners_curr.clear();
        // 将找到的角点存储在corners_curr中
        found = cv::findChessboardCorners(gray, { w, h }, corners_curr);
        if (found) {
            RCLCPP_INFO(this->get_logger(), "Corners found!");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Corners not found!");
            rclcpp::shutdown();
        }
        // 指定亚像素计算迭代标注
        cv::TermCriteria criteria =
            cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 40, 0.01);
        // 亚像素计算
        cv::cornerSubPix(gray, corners_curr, { 5, 5 }, { -1, -1 }, criteria);
        // 显示检测到的棋盘角点
        cv::drawChessboardCorners(img, { w, h }, corners_curr, found);
        cv::resize(img, im2show, { 960, 576 });
        //cv::imshow("find_pix", im2show);
        //cv::waitKey(100);
        // 保存数据
        corners_seq.emplace_back(corners_curr);
        obj_seq.emplace_back(obj); //目前obj在不同的img中都是相同的，因此在该循环中进行拷贝
    }
}

void calibrate::CalibNode::cal_cam_param() {
    RCLCPP_INFO(this->get_logger(), "Start calculating CamParam!");
    // 使用cv::calibrateCamera计算相机内外参和畸变系数，err是返回的误差值
    auto err = cv::calibrateCamera(obj_seq, corners_seq, size, mtx, coff, rvecs, tvecs);
    //最好用ros2的logger，直接用cout可能会导致线程相关的问题
    RCLCPP_INFO_STREAM(this->get_logger(), "相机参数计算误差: " << err);
    RCLCPP_INFO_STREAM(this->get_logger(), "相机内参矩阵mtx: " << std::endl << mtx);
    RCLCPP_INFO_STREAM(this->get_logger(), "相机的畸变系数coff: " << coff);
}

void calibrate::CalibNode::cal_cam2imu_pose() {
    RCLCPP_INFO(this->get_logger(), "Start calculating cam2imu pose!");
    Eigen::Matrix3f U = Eigen::Matrix3f::Zero();
    for (size_t i = 0; i < obj_seq.size(); i++) {
        Eigen::Vector3f g;
        cv::Mat R_Mat;
        cv::Rodrigues(rvecs[i], R_Mat);
        Eigen::Matrix3f R_C;
        cv::cv2eigen(R_Mat, R_C);
        g << 0, 0, 1;
        Eigen::Vector3f camera_gravity = R_C * g;
        //imu数据，调试时没有该数据，因此暂时构造了测试集
        Eigen::Matrix3f R_I = imu_seq[i];
        g << 0, 0, -1;
        Eigen::Vector3f imu_gravity = R_I * g;
        U += imu_gravity * camera_gravity.transpose();
    }
    RCLCPP_INFO(this->get_logger(), "初始化矩阵数据完成");

    Eigen::Matrix4f N;
    const int x = 0, y = 1, z = 2;
    N(0, 0) = U(x, x) + U(y, y) + U(z, z);
    N(0, 1) = U(y, z) - U(z, y);
    N(0, 2) = U(z, x) - U(x, z);
    N(0, 3) = U(x, y) - U(y, x);

    N(1, 0) = U(y, z) - U(z, y);
    N(1, 1) = U(x, x) - U(y, y) - U(z, z);
    N(1, 2) = U(x, y) + U(y, x);
    N(1, 3) = U(z, x) + U(x, z);

    N(2, 0) = U(z, x) - U(x, z);
    N(2, 1) = U(x, y) + U(y, x);
    N(2, 2) = -U(x, x) + U(y, y) - U(z, z);
    N(2, 3) = U(y, z) + U(z, y);

    N(3, 0) = U(x, y) - U(y, x);
    N(3, 1) = U(z, x) + U(x, z);
    N(3, 2) = U(y, z) + U(z, y);
    N(3, 3) = -U(x, x) - U(y, y) + U(z, z);

    // 计算N的特征值和特征向量
    RCLCPP_INFO(this->get_logger(), "开始计算N的特征值和特征向量");
    Eigen::EigenSolver<Eigen::Matrix4f> es(N);
    Eigen::Matrix4f D = es.pseudoEigenvalueMatrix();
    Eigen::Matrix4f V = es.pseudoEigenvectors();
    int col_index, row_index;
    D.maxCoeff(&row_index, &col_index);
    Eigen::Vector4f q_vec = V.col(col_index);
    Eigen::Quaternionf q { q_vec(0, 0), q_vec(1, 0), q_vec(2, 0), q_vec(3, 0) };
    Eigen::Matrix3f R_CI = q.matrix();

    float err_q = 0;
    for (size_t i = 0; i < obj_seq.size(); i++) {
        Eigen::Vector3f g;
        Eigen::Vector3f axis;
        cv::cv2eigen(rvecs[i], axis);
        float angle = axis.norm();
        axis /= angle;
        Eigen::AngleAxisf rvec(angle, axis);
        Eigen::Matrix3f R_C = rvec.matrix();
        g << 0, 0, 1;
        Eigen::Vector3f camera_gravity = R_C * g;

        Eigen::Matrix3f R_I = imu_seq[i];
        g << 0, 0, -1;
        Eigen::Vector3f imu_gravity = R_I * g;
        Eigen::Vector3f camera_gravity_from_imu = q * imu_gravity;
        err_q += (camera_gravity - camera_gravity_from_imu).norm();
    }
    err_q /= obj_seq.size();

    RCLCPP_INFO_STREAM(this->get_logger(), "imu-camera error: " << err_q);
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "相机-IMU相对姿态四元数q: " << q_vec[0] << " " << q_vec[1] << " " << q_vec[2] << " "
                                    << q_vec[3]
    );

    cv::FileStorage fout(result_path, cv::FileStorage::WRITE);
    fout << "F" << mtx;
    fout << "C" << coff;
    cv::Mat R_CI_CV;
    cv::eigen2cv(R_CI, R_CI_CV);
    fout << "R_CI" << R_CI_CV;
}

void calibrate::CalibNode::init_data_test() {
    RCLCPP_INFO(this->get_logger(), "(test) Start initiating data!");
    int n = 3;
    for (int i = 0; i < n; i++) {
        //在哪里运行ros2 launch，哪里就是根目录
        std::string file_name = "calib_node/src/chesstest/" + std::to_string(i).append(".jpg");
        std::cout << file_name << std::endl;
        cv::Mat img_tmp = cv::imread(file_name);
        if (img_tmp.empty()) {
            std::cout << "读取文件失败" << std::endl;
            break;
        } else {
            std::cout << "读取文件成功" << std::endl;
            size.width = img_tmp.cols;
            size.height = img_tmp.rows;
            image_seq.emplace_back(img_tmp);
            //cv::imshow("test", img_tmp);
            //cv::waitKey(100);
        }
    }
    //调试时随机生成的imu数据
    q_seq = {
        { 0.92388, 0.382683, 0, 0 },
        { 0, 0.707107, 0, 0.707107 },
        { 0, 0, 0.258819, 0.965926 },
    };
    std::vector<double> q_tmp;
    for (int i = 0; i < n; i++) {
        q_tmp = q_seq[i];
        Eigen::Quaternionf q(q_tmp[0], q_tmp[1], q_tmp[2], q_tmp[3]);
        q_backup = q.matrix().transpose();
        imu_seq.emplace_back(q_backup);
    }
}

calibrate::CalibNode::~CalibNode() {
    if (cam_thread_.joinable()) {
        cam_thread_.join();
    }
    if (imu_thread_.joinable()) {
        imu_thread_.join();
    }
    if (calculate_thread_.joinable()) {
        calculate_thread_.join();
    }
}

#include <rclcpp_components/register_node_macro.hpp> //这个头文件一定要放在最后引入，顺序不能变
//register the node to workspace
RCLCPP_COMPONENTS_REGISTER_NODE(calibrate::CalibNode)
