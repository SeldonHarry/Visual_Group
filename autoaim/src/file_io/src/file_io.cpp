// todo : load param
#include <camera_info_manager/camera_info_manager.hpp>
#include <chrono>
#include <deque>
#include <fstream>
#include <functional>
#include <image_transport/image_transport.hpp>
#include <iostream>
#include <memory>
#include <mutex>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <thread>

#include "minipc_comm/robot.hpp" // todo 剔除多余的头文件

#include "image_transport/camera_publisher.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"

#define DETAIL_LOGGER

using namespace std::chrono_literals;

const auto continuous_read_interval = 20ms;
const std::string CAMERA_NAME = ""; // todo 把相机名称加载放入launchfile中去
const std::string ROBOT_PUBLISH_TOPIC = "fileio_topic";
const std::string CAMERA_PUBLISH_TOPIC = "camera_topic";
const std::string IMU_PUBLISH_TOPIC = "imu_data";
const std::string VIDEO_FILE_PATH = "";
const std::string IMU_FILE_PATH = "";
const std::string SENSOR_PARAM_FILE_PATH = ""; // 之前相机节点的参数是如何读取和以什么结构发布的
const int MAX_QUEUE_SIZE = 2;
const auto START_DELAY = 500ms;

// 在namespace中加入错误类
namespace fileio {
class FileIONode: public rclcpp::Node {
public:
    explicit FileIONode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    ~FileIONode() override;

private:
    void init_node();
    // 读取相机文件和时间戳并模拟时间戳发布
    void img_pub_loop();
    void imu_pub_loop();
    // 获取相机和陀螺仪的参数
    void get_param();
    // 读取文件中的时间等数据
    template<typename T>
    bool read_value(std::shared_ptr<std::ifstream> fin, T& v);

private:
    rclcpp::Publisher<my_interfaces::msg::RobotStatus>::SharedPtr robot_publisher_;
    image_transport::CameraPublisher camera_publihser_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_publisher_;
    std::thread img_io_thread_;
    std::thread imu_io_thread_;

    std::unique_ptr<camera_info_manager::CameraInfoManager> camera_info_manager_;
    sensor_msgs::msg::CameraInfo camera_info_msg_; // 用来读取yaml文件中的相机参数

    std::shared_ptr<RobotStatus> status_;
    std::deque<cv::Mat> img_queue_;
    std::deque<double> stamp_queue_;

    std::shared_ptr<std::ifstream> pfin_stamp_;
    std::shared_ptr<cv::VideoCapture> pRead_;

    static long double computer_origin_; // 存储计算机开始放松第一帧的时间
    static long double analog_origin_; // 存储相机第一帧记录的时间

    std::mutex g_mutex_;
};
} // namespace fileio

fileio::FileIONode::FileIONode(const rclcpp::NodeOptions& options):
    rclcpp::Node("fileio_node", options) {
    RCLCPP_INFO(this->get_logger(), "Statring ROS2 Node.");
    init_node();

    get_param();
}

template<typename T>
bool fileio::FileIONode::read_value(std::shared_ptr<std::ifstream> fin, T& v) {
    char cache = 0;
    while (!fin->eof()) {
        fin->get(cache);
        if (std::isdigit(cache) || cache == '-') {
            // 数、负数,小数作为时间是合理的，所有小数开头都必须有数，所以可以读入小数
            break;
        }
    }
    if (fin->eof()) {
        return false;
    }
    fin->putback(cache); // 放回读到的字符
    *fin >> v; // check if this is right
    return true;
}

void fileio::FileIONode::init_node() {
    robot_publisher_ = this->create_publisher<my_interfaces::msg::RobotStatus>(
        ROBOT_PUBLISH_TOPIC,
        rclcpp::QoS(10)
    );
    camera_publihser_ =
        image_transport::create_camera_publisher(this, CAMERA_PUBLISH_TOPIC); // 未写qos
    imu_publisher_ =
        this->create_publisher<sensor_msgs::msg::Imu>(IMU_PUBLISH_TOPIC, rclcpp::QoS(10));

    RCLCPP_INFO(this->get_logger(), "Created Publishers");
    pRead_ = std::make_shared<cv::VideoCapture>(VIDEO_FILE_PATH);
    const std::string time_stamp_path = VIDEO_FILE_PATH[0, VIDEO_FILE_PATH.size() - 4] + ".txt";
    pfin_stamp_ = std::make_shared<std::ifstream>(time_stamp_path, std::ios::in);
    // 检查文件是否打开
    int err_code = 0;
    try {
        if (!pRead_->isOpened()) {
            throw err_code |= 1;
        } else if (!pfin_stamp_->is_open()) {
            throw err_code |= 2;
        }
    } catch (const int& e) {
        if (e == 1) {
            RCLCPP_ERROR(this->get_logger(), "[ERROR] FAILED TO OPEN VIDEO FILE.");
        }
        if (e == 2) {
            RCLCPP_ERROR(this->get_logger(), "[ERROR] FAILED TO OPEN TIME STAMP.");
        }

        RCLCPP_WARN(
            this->get_logger(),
            "[WARN] Fatal eeror: file path error, check and restart the node. Terminating."
        );
        rclcpp::shutdown();
    }

    RCLCPP_INFO(this->get_logger(), "Node initialized.");
}

void fileio::FileIONode::get_param() {
    // 载入相机参数
    camera_info_manager_ =
        std::make_unique<camera_info_manager::CameraInfoManager>(this, CAMERA_NAME);
    std::string camera_info_url =
        "package://sensor/config/camera_info.yaml"; // 这是相机参数文件的储存位置，实际上是读取的sensor包下面的，这个包的config只做备份
    if (camera_info_manager_->validateURL(camera_info_url)) {
        camera_info_manager_->loadCameraInfo(camera_info_url);
        camera_info_msg_ = camera_info_manager_->getCameraInfo();
    } else {
        RCLCPP_ERROR(this->get_logger(), "Invalid camera info URL: %s", camera_info_url.c_str());
        rclcpp::shutdown();
    }
    RCLCPP_INFO(this->get_logger(), "Load camera info.");
    // todo imu
}

// 按原来的时间间隔发送，但是时间戳用的当前的时间
void fileio::FileIONode::img_pub_loop() {
    // 先读满队列，初始化原点,向imu 发布开始命令 ，0.5 s后开始线程.
    cv::Mat frame;
    long double stamp, next_interval; // next interval以毫秒记，保留一位小数点
    long frame_cnt, idx = 0;
    long double start_delay = START_DELAY.count();
    int eof_flag = 0;
    while (img_queue_.size() < MAX_QUEUE_SIZE) {
        *pRead_ >> frame;
        img_queue_.push_back(frame);
    }
    while (stamp_queue_.size() < MAX_QUEUE_SIZE) {
        read_value(pfin_stamp_, stamp); // 保证stamp的数据格式合理
        read_value(pfin_stamp_, frame_cnt);
        stamp_queue_.push_back(stamp);
    }
    analog_origin_ = stamp_queue_.front(); // 单位是秒
    computer_origin_ = std::chrono::steady_clock::now().time_since_epoch().count(
    ); // 计算机线程先休息delay后再开始
    // 向imu放送信号
    std::this_thread::sleep_for(START_DELAY);

    while (rclcpp::ok()) {
        auto t1 = std::chrono::steady_clock::now();
        sensor_msgs::msg::Image msg;
        long double a;
        // 先发送再读取
        a = stamp_queue_.front();
        stamp_queue_.pop_front();
        next_interval = (stamp_queue_.front() - a) * 1e3; //ms
        // 图片处理
        frame = img_queue_.front();
        msg.header.stamp = this->now();
        msg.height = frame.rows;
        msg.header.frame_id = std::__cxx11::to_string(++idx);
        msg.width = frame.cols;
        msg.encoding = "bgr8";
        msg.step = frame.cols * 3; // 注意这里留3的原因
        msg.data.resize(frame.total() * 3);
        memcpy(&msg.data[0], frame.data, msg.data.size());
        camera_info_msg_.header = msg.header;
        // 图片格式转换完成

        camera_publihser_.publish(msg, camera_info_msg_);
        img_queue_.pop_front();
        // 重新读取
        if (!eof_flag) {
            while (img_queue_.size() < MAX_QUEUE_SIZE) {
                *pRead_ >> frame;
                img_queue_.push_back(frame);
            }
            while (stamp_queue_.size() < MAX_QUEUE_SIZE) {
                read_value(pfin_stamp_, stamp); // 保证stamp的数据格式合理
                eof_flag |= 1 ^ read_value(pfin_stamp_, frame_cnt);
                stamp_queue_.push_back(stamp);
            }
        }
        assert(img_queue_.size() == stamp_queue_.size());
        // 完成
        auto t2 = std::chrono::steady_clock::now();
        long double delay = (t2 - t1).count() * 1e3; //ms
        std::this_thread::sleep_for(
            std::chrono::duration<long double, std::milli>(next_interval - delay)
        ); // in ms
    }

    rclcpp::shutdown();
    return;
}