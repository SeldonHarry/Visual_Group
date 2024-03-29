// this is a fake file io for it ignores the validity of time stamp
// since it is utilized as a tool to debug predictor node
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <my_interfaces/msg/detail/robot_status__struct.hpp>
#include <string>
#include <thread>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "minipc_comm/robot.hpp"

#include "camera_info_manager/camera_info_manager.hpp"
#include "image_transport/camera_publisher.hpp"
#include "image_transport/image_transport.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"

#define DETAIL_LOGGER_FAKEIO

using namespace std::chrono_literals;

auto CONTINUOUS_PUB_INTV = 20ms; //param1
std::string VIDEO_PATH =
    "/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/assets/blue_pr2.mp4"; // param2
std::string IMU_PATH =
    "/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/assets/blue.txt"; // param3
std::string CAM_NAME =
    "camera_right"; // this should be in accord with that in camera.yaml file param4
const std::string CAMERA_PUBLISH_TOPIC = "image_raw";
const std::string ROBOT_PUBLISH_TOPIC = "minipc_topic";
const std::string IMU_PUBLISH_TOPIC = "imu_data";

template<typename T>
inline bool read_value(std::fstream& fin, T& v) {
    char cache = 0;
    while (!fin.eof()) {
        fin.get(cache);
        if (std::isdigit(int(cache)) || cache == '-' || cache == '.' || cache == '+') {
            break;
        }
    }
    if (fin.eof())
        return false;
    fin.putback(cache);
    fin >> v;
    return true;
}

namespace fakeio {

class FakeioNode: public rclcpp::Node {
public:
    explicit FakeioNode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    ~FakeioNode() override;

private:
    void init_node();
    void pub_loop();
    void get_param();
    void convert_img(const cv::Mat& src, sensor_msgs::msg::Image& dst);
    void StatusMsg_gen(const RobotStatus& src, my_interfaces::msg::RobotStatus& dst);
    void imu_analyzer();
    void file_path_check(const std::string& file_path);
    template<typename T>
    friend bool read_value(std::fstream& fin, T& v);

private:
    image_transport::CameraPublisher camera_publisher_;
    std::unique_ptr<camera_info_manager::CameraInfoManager> camera_info_manager_;
    std::deque<sensor_msgs::msg::Imu> imu_dq_;
    sensor_msgs::msg::CameraInfo camera_info_;
    rclcpp::Publisher<my_interfaces::msg::RobotStatus>::SharedPtr robot_publisher_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_publisher_;
    std::shared_ptr<RobotStatus> status_;
    std::shared_ptr<cv::VideoCapture> pRead_;
    std::thread pub_thread_;
    std::fstream fin_;
    int cnt_ = 0; // frameid
};

} // namespace fakeio
fakeio::FakeioNode::FakeioNode(const rclcpp::NodeOptions& options):
    rclcpp::Node("fakeio_node", options) {
    RCLCPP_INFO(this->get_logger(), "Starting Node.");
    init_node();
    RCLCPP_INFO(this->get_logger(), "Finishing Initialize Node!");
    pub_loop();
}

fakeio::FakeioNode::~FakeioNode() {
    rclcpp::shutdown();
    if (pub_thread_.joinable()) {
        pub_thread_.join();
    }
    RCLCPP_INFO(this->get_logger(), "Node Destructed.");
}

void fakeio::FakeioNode::init_node() {
    get_param();
    robot_publisher_ = this->create_publisher<my_interfaces::msg::RobotStatus>(ROBOT_PUBLISH_TOPIC,
                                                                               rclcpp::QoS(10));
    imu_publisher_ =
        this->create_publisher<sensor_msgs::msg::Imu>(IMU_PUBLISH_TOPIC, rclcpp::QoS(10));
    camera_publisher_ = image_transport::create_camera_publisher(this, CAMERA_PUBLISH_TOPIC);
    pRead_ = std::make_shared<cv::VideoCapture>(VIDEO_PATH);
    // todo errcode
    status_ = std::make_shared<RobotStatus>(); // use default value
    status_->program_mode = ::ProgramMode::AUTOAIM;
#ifdef DETAIL_LOGGER_FAKEIO
    RCLCPP_INFO(this->get_logger(), "%f", status_->bullet_speed);
#endif
    fin_ = std::fstream(IMU_PATH, std::ios::in);
    imu_analyzer();
    return;
}

void fakeio::FakeioNode::pub_loop() {
    cv::Mat frame;
    sensor_msgs::msg::Image msg;
    *pRead_ >> frame;
    auto robot_msg = my_interfaces::msg::RobotStatus();
    while (rclcpp::ok()) {
        convert_img(frame, msg);
        //*pRead_>>frame;
        camera_publisher_.publish(msg, camera_info_);
        StatusMsg_gen(*status_, robot_msg); //这一步sharedPrt是否安全？
        robot_publisher_->publish(robot_msg);
        imu_publisher_->publish(imu_dq_.front());
        imu_dq_.pop_front();

        if (!pRead_->read(frame) || imu_dq_.empty()) {
            pRead_->release();
            rclcpp::shutdown();
            RCLCPP_INFO(this->get_logger(), "Finished Read Video, Exiting.");
        }
#ifdef DETAIL_LOGGER_FAKEIO
        RCLCPP_INFO(this->get_logger(), "Publishing msg.");
#endif
        std::this_thread::sleep_for(CONTINUOUS_PUB_INTV);
    }
}

void fakeio::FakeioNode::get_param() {
    this->declare_parameter<int>("pub_interval", 20);
    this->declare_parameter("camera_name", "");
    this->declare_parameter("imu_path", "");
    this->declare_parameter("video_path", "");
    std::string camera_name, imu_path, video_path;
    int pub_interval;
    this->get_parameter("pub_interval", pub_interval);
    this->get_parameter("camera_name", camera_name);
    this->get_parameter("imu_path", imu_path);
    this->get_parameter("video_path", video_path);
    if (camera_name.empty() || imu_path.empty() || video_path.empty()) {
        RCLCPP_WARN(this->get_logger(),
                    "One or More empty phrases as parameter. Check parameter again!");
        RCLCPP_INFO(this->get_logger(), "Use default params");
    } else {
        CONTINUOUS_PUB_INTV = std::chrono::milliseconds(pub_interval);
        IMU_PATH = imu_path;
        VIDEO_PATH = video_path;
        CAM_NAME = camera_name;
    }
    try {
        file_path_check(imu_path);
        file_path_check(video_path);
    } catch (std::string& e) {
        RCLCPP_ERROR(this->get_logger(), "File check fails. Info: %s .", e.c_str());
        RCLCPP_WARN(this->get_logger(), "Exiting Node. Check your param again.");
        rclcpp::shutdown();
        //return;
    }
    RCLCPP_INFO(this->get_logger(),
                "Params: pub_interval: %d . Imu Path: %s . Video Path: %s . camera name: %s .",
                pub_interval,
                imu_path.c_str(),
                video_path.c_str(),
                camera_name.c_str());

    camera_info_manager_ = std::make_unique<camera_info_manager::CameraInfoManager>(this, CAM_NAME);
    std::string camera_info_url = "package://sensor/config/camera_info.yaml";
    // 这个地址对应着哪里的文件？
    if (camera_info_manager_->validateURL(camera_info_url)) {
        camera_info_manager_->loadCameraInfo(camera_info_url);
        camera_info_ = camera_info_manager_->getCameraInfo();
    } else {
        RCLCPP_ERROR(this->get_logger(),
                     "[ERROR] Invalid camera info URL: %s",
                     camera_info_url.c_str());
        rclcpp::shutdown();
        RCLCPP_INFO(this->get_logger(), "Node Destructed.");
    }
    RCLCPP_INFO(this->get_logger(), "Cam Info Loaded.");
    return;
}

void fakeio::FakeioNode::convert_img(const cv::Mat& src, sensor_msgs::msg::Image& dst) {
    dst.header.stamp = this->now();
    dst.height = src.rows;
    dst.width = src.cols;
    dst.header.frame_id = std::__cxx11::to_string(++cnt_);
    dst.encoding = "bgr8";
    dst.step = 3 * src.cols;
    dst.data.resize(src.total() * 3);
    memcpy(&dst.data[0], src.data, dst.data.size());
    camera_info_.header = dst.header;
    return;
}

void fakeio::FakeioNode::StatusMsg_gen(const RobotStatus& src,
                                       my_interfaces::msg::RobotStatus& dst) {
    dst.bullet_speed = src.bullet_speed;
    dst.yaw_compensate = src.yaw_compensate;
    dst.pitch_compensate = src.pitch_compensate;
    dst.enemy_color = (uint8_t)src.enemy_color; // in old protocol this only takes up 1 bit
    dst.is_big_energy = (uint8_t)src.is_big_energy;
    dst.program_mode = (uint8_t)src.program_mode;
    dst.latency_cmd_to_fire = src.latency_cmd_to_fire;
    dst.last_shoot_aim_id = src.last_shoot_aim_id;
    dst.laser_distance = src.laser_distance;
    return;
}
void fakeio::FakeioNode::imu_analyzer() {
    int count = 0;
    while (true) {
        sensor_msgs::msg::Imu imu;
        int idx;
        float q;
        float t;
        if (read_value(fin_, idx)) {
            imu.header.frame_id = std::__cxx11::to_string(idx);
            imu.header.stamp = this->now();
            read_value(fin_, q);
            imu.orientation.y = q;
            read_value(fin_, q);
            imu.orientation.z = q;
            read_value(fin_, q);
            imu.orientation.w = q;
            read_value(fin_, q);
            imu.orientation.x = q; // raw -> imu 是3012顺序吗？
            read_value(fin_, t); //读当时的时间戳
            imu_dq_.push_back(imu);
            count++;
        } else {
            RCLCPP_INFO(this->get_logger(), "Finished loading imu data. Totoaling: %d", count);
            break;
        }
    }
    return;
}

void fakeio::FakeioNode::file_path_check(const std::string& file_path) {
    std::filesystem::path f_str(file_path);
    if (!std::filesystem::exists(f_str))
        throw std::string("given path do not exsists!");

    return;
}

RCLCPP_COMPONENTS_REGISTER_NODE(fakeio::FakeioNode)