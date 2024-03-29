#include <camera_info_manager/camera_info_manager.hpp>
#include <chrono> //时间相关的库
#include <cv_bridge/cv_bridge.h>
#include <eigen3/Eigen/Dense>
#include <image_transport/camera_subscriber.hpp>
#include <image_transport/image_transport.hpp>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/core/persistence.hpp>
//用于支持持久性操作，包括读取和写入配置文件
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>
#include <thread>
#include <vector>

namespace calibrate {
class CalibNode: public rclcpp::Node {
public:
    explicit CalibNode(const rclcpp::NodeOptions& options);
    ~CalibNode() override;

private:
    // ros2通信部分
    void init_subscribe(); //初始化订阅者和回调函数
    // 声明订阅者，从sensor获取图像和imu信息
    image_transport::CameraSubscriber cam_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    int interval = 1000; // 获取信息的频率间隔，即sleep的时间长度，目前单位使用毫秒
    int max_cnt = 10;
    bool cam_bt = false;
    bool imu_bt = false;
    bool run_bt = true;
    int cam_cnt = 0;
    int imu_cnt = 0;
    void save_cam_data();
    void save_imu_data();
    bool cam_finished = false;
    bool imu_finished = false;
    std::thread cam_thread_;
    std::thread imu_thread_;

    //数据处理部分
    void getdata_from_toml();
    //注意，文件路径参数需要根据情况自行更改
    std::string toml_path = "src/param/assets/base.param.toml";
    std::string result_path = "assets/cam_calib_res.yml";
    void calculate();
    std::thread calculate_thread_;
    void init_data_test(); // 初始化与解析参数(本地调试用)
    void find_pix(); // 寻找图像角点，并进行亚像素精细化
    void cal_cam_param(); // 计算内外参与畸变系数
    void cal_cam2imu_pose(); // 计算相机与imu的相对位姿

    // 棋盘格
    // 这三个参数原本都从toml中调用，以后可能从param节点服务器调用
    // 目前就从toml文件调用，赋上默认值防止出错
    int w = 9; // 棋盘宽(pixel)
    int h = 6; // 棋盘高(pixel)
    double d = 2.0; // 棋盘网格大小 (cm)
    // 棋盘的世界坐标点
    // 这里不能在内部声明大小w*h，obj()括号内部的不知道为什么会被识别为类型
    std::vector<cv::Point3f> obj;
    void init_obj();
    // 棋盘的世界坐标点序列
    std::vector<std::vector<cv::Point3f>> obj_seq;
    // 棋盘的角点序列
    std::vector<std::vector<cv::Point2f>> corners_seq;
    // 当前角点，curr即current
    std::vector<cv::Point2f> corners_curr;
    /* toml文件内容
    [calibrate]
    chessboard-width = 11
    chessboard-height = 8
    chessboard-cell-size-cm = 2.0
    */

    // 相机
    cv::Size size; // 图像大小
    cv::Mat img_input;
    cv::Mat img;
    double timestamp; //相机时间戳
    std::vector<double> timestamp_seq; // 时间戳序列
    std::vector<cv::Mat> image_seq; // 图像序列
    cv::Mat im2show;
    cv::Mat gray;
    cv::Mat mtx, coff; // 相机内参矩阵和畸变参数
    std::vector<cv::Mat> rvecs, tvecs; //相机外参矩阵（旋转和平移）

    // 陀螺仪
    float q_input[4]; // 似乎精度就是float
    std::vector<std::vector<double>> q_seq;
    Eigen::Matrix3f q_backup; // 陀螺仪姿态备份，用于将临时变量全部存储
    std::vector<Eigen::Matrix3f> imu_seq; // 陀螺仪姿态序列

    // 老代码部分
    // 网页端名称，需要在网页端写好后修改
    const std::string web_page = "calibrate";

    // 运行模式是捕获还是决策,默认是捕获(老代码)
    enum class RunMode : int { CAPTURE = 0, DECISION = 1 };
    RunMode mode = RunMode::CAPTURE;

    // 尝试修改button(老代码)
    enum class Button : int { CAPTURE_BT = 0, ACCEPT_BT = 1, DECLINE_BT = 2, FINISH_BT = 3 };
};
} // namespace calibrate