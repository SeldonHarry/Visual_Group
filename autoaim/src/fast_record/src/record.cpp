// featrue: 定时长录制
// imu-frame配对
// 使用deque
#include <Eigen/Core>
#include <Eigen/Dense>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <opencv2/core/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <string>
#include <thread>
#include <utility>

#include "cv_bridge/cv_bridge.h"
#include "image_transport/camera_subscriber.hpp"
#include "image_transport/image_transport.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"
#define mp make_pair
#define ft first
#define sd second
using namespace std::chrono_literals;
const auto frame_size = cv::Size(1280, 768);
auto RECORD_DURATION = 100s; //param1
const std::string IMU_SUB_TOPIC = "imu_data";
const std::string CAM_SUB_TOPIC = "camera_topic";
const std::string MINIPC_SUB_TOPIC = "minipc_topic";
std::string STORAGE_PATH =
    "/home/seldon/Documents/gitrepo/rm.cv.std.ros2_transplant/local_storage/"; // default storage 位置 最终由launchfile决定，不在此处做修改.使用相对路径
// Note:./表示install的位置，应该是在build文件夹下的so文件。 // param2
typedef std::pair<cv::Mat, sensor_msgs::msg::Imu> pfi;
namespace recorder {
class RecorderNode: public rclcpp::Node {
public:
    explicit RecorderNode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    ~RecorderNode() override;

private:
    std::string generate_filename(const std::string& storage_directory);
    void init_node();
    void img_subcallback(const sensor_msgs::msg::Image::ConstSharedPtr img,
                         const sensor_msgs::msg::CameraInfo::ConstSharedPtr cam_info);
    void imu_subcallback(const sensor_msgs::msg::Imu::ConstSharedPtr imu_data);
    // void init_recorder(); // check initialize error
    void timer_callback(); // 实现定时录制的功能
    void write();

private:
    image_transport::CameraSubscriber camera_subscriber_; // QOS use sensor data qos?
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr
        imu_subscriber_; // 现在的时间戳只有imu的有效，不能保证robot的有效
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<cv::VideoWriter> pwriter_;
    // std::shared_ptr<std::ofstream> p_camf_;
    std::shared_ptr<std::ofstream> pimuf_;
    sensor_msgs::msg::Imu imu_now_;
    std::deque<pfi> dq_;
    std::thread wirte_thread_;
    int imu_frame_cnt_ = 0;
    int img_frame_cnt_ = 0;
};
} // namespace recorder

recorder::RecorderNode::RecorderNode(const rclcpp::NodeOptions& options):
    rclcpp::Node("fast_record", options) {
    RCLCPP_INFO(this->get_logger(), "Entering Node.");
    init_node();
    RCLCPP_INFO(this->get_logger(), "ROS2 Node inited.");
    RCLCPP_INFO(this->get_logger(), "ROS2 Node Starting.\n========= Video Writer ========\n");
}

recorder::RecorderNode::~RecorderNode() {
    pimuf_->close();
    pwriter_->release();
    //camera_subscriber_.shutdown();
    rclcpp::shutdown();
    RCLCPP_WARN(this->get_logger(), "Node Destruceted Successfully.");
}

void recorder::RecorderNode::init_node() {
    std::string storage_path;
    int record_interval;
    this->declare_parameter("storage_path","");
    this->declare_parameter<int>("record_interval", 0);
    // 判断这个param到底空不空
    // RCLCPP_INFO(this->get_logger(), "d1"); //debug
    this->get_parameter("storage_path",storage_path);
    this->get_parameter("record_interval",record_interval);
    // RCLCPP_INFO(this->get_logger(), "record: %d",record_interval); // debug
    if (!storage_path.empty())
        STORAGE_PATH = storage_path;
    if (record_interval > 0 && record_interval < 1e3)
        RECORD_DURATION = std::chrono::duration<int>(record_interval);
    else {
        RCLCPP_ERROR(this->get_logger(), "[ERR] Record duration invalid: %d .", record_interval);
        RCLCPP_WARN(this->get_logger(), "Use dafault duraiton: %d .", RECORD_DURATION);
    }
    RCLCPP_INFO(this->get_logger(), "Storage Path: %s", STORAGE_PATH.c_str());

    std::string video_path, imu_path;
    try {
        std::string store_path = STORAGE_PATH;
        std::string fname = generate_filename(STORAGE_PATH);
        if (store_path.at(store_path.size() - 1) != '/')
            store_path.append("/");
        video_path = STORAGE_PATH + fname + ".mp4";
        imu_path = STORAGE_PATH + fname + ".txt";
    } catch (const std::string& e) {
        RCLCPP_ERROR(this->get_logger(), "[ERR] STORAGE PATH INVALID. INFO: %s", e.c_str());
        RCLCPP_ERROR(this->get_logger(), "SHUT DOWN THIS NODE. Modify your path and launch again.");
        rclcpp::shutdown();
    }
    camera_subscriber_ =
        image_transport::create_camera_subscription(this,
                                                    CAM_SUB_TOPIC,
                                                    std::bind(&RecorderNode::img_subcallback,
                                                              this,
                                                              std::placeholders::_1,
                                                              std::placeholders::_2),
                                                    "raw");
    imu_subscriber_ = this->create_subscription<sensor_msgs::msg::Imu>(
        IMU_SUB_TOPIC,
        rclcpp::QoS(10),
        std::bind(&RecorderNode::imu_subcallback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "Subscriber created.");
    pwriter_ = std::make_shared<cv::VideoWriter>(
        video_path,
        cv::VideoWriter::fourcc('m', 'p', '4', 'v'), // 改成小写.... crucial
        20.0,
        frame_size);
    pimuf_ = std::make_shared<std::ofstream>(imu_path, std::ios::out);
    RCLCPP_INFO(this->get_logger(), "File created.");
    timer_ =
        this->create_wall_timer(RECORD_DURATION, std::bind(&RecorderNode::timer_callback, this));
    return;
}

void recorder::RecorderNode::timer_callback() {
    camera_subscriber_.shutdown();
    imu_subscriber_.reset();
    RCLCPP_INFO(this->get_logger(), "Reached Set Interval. Subscription Hault.");
    // write
    write();
    RCLCPP_INFO(this->get_logger(), "Exiting.");
    rclcpp::shutdown(); // 必须在推出前的那一个位置写shutdown？ crucial test!
    return;
}

void recorder::RecorderNode::img_subcallback(
    const sensor_msgs::msg::Image::ConstSharedPtr img,
    const sensor_msgs::msg::CameraInfo::ConstSharedPtr cam_info) {
    cv_bridge::CvImageConstPtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception& e) {
        RCLCPP_ERROR(this->get_logger(), "[ERR] CV_BRIDGE ERROR. INFO: %s", e.what());
        return;
    }
    pfi temp = std::mp(cv_ptr->image, imu_now_);
    dq_.push_back(temp);
    img_frame_cnt_++;
    if (dq_.size() % 5 == 0)
        RCLCPP_INFO(this->get_logger(), "Entering dq_.");

    return;
}

void recorder::RecorderNode::imu_subcallback(const sensor_msgs::msg::Imu::ConstSharedPtr imu_data) {
    imu_frame_cnt_++;
    imu_now_ = *imu_data; //mutex here?
    return;
}

// void recorder::RecorderNode::init_recorder() {}

void recorder::RecorderNode::write() {
    RCLCPP_INFO(this->get_logger(), "Finished Recording. Starting file writer.");
    pfi t;
    int cnt = 0;
    while (rclcpp::ok() && !dq_.empty()) {
        t = dq_.front();
        dq_.pop_front();
        pwriter_->write(t.ft);
        // imuf
        Eigen::Vector4d q { (double)t.sd.orientation.x,
                            (double)t.sd.orientation.y,
                            (double)t.sd.orientation.z,
                            (double)t.sd.orientation.w };
        *pimuf_ << "[frame num] " << ++cnt << std::endl;
        *pimuf_ << "[imu] " << q << std::endl;
        std::string nano_str = std::__cxx11::to_string(t.sd.header.stamp.nanosec);
        if (nano_str.size() < 9) {
            while (nano_str.size() < 9)
                nano_str.insert(0, 1, '0');
        }
        *pimuf_ << "[time] " << t.sd.header.stamp.sec << "." << nano_str.c_str()
                << std::endl;
        *pimuf_ << std::endl;
        // RCLCPP_INFO(this->get_logger(),"%d",cnt); //DEBUG
    }
    RCLCPP_INFO(this->get_logger(),
                "%d cnt1\t %d cnt2 %ld",
                img_frame_cnt_,
                cnt,
                dq_.size()); // DEBUG
    // assert(img_frame_cnt_ == cnt);
    RCLCPP_INFO(this->get_logger(), "Finished file writer.");
    //rclcpp::shutdown();
    return;
}

std::string recorder::RecorderNode::generate_filename(const std::string& storage_directory) {
    char now[64];
    std::time_t tt;
    struct tm* ttime;
    tt = time(nullptr);
    ttime = localtime(&tt);
    strftime(now, 64, "%Y-%m-%d_%H_%M_%S", ttime);
    std::string now_string(now); // 使用时间作为文件名

    // dir check
    std::filesystem::path p_str(storage_directory);
    if (!std::filesystem::exists(p_str)) {
        throw std::string("directory \"" + storage_directory + "\" does not exist."); // 错误抛出
    } // no dir
    std::filesystem::directory_entry entry(p_str);
    if (entry.status().type() != std::filesystem::file_type::directory) {
        throw std::string("\"" + storage_directory + "\" is not a directory");
    } // not a dir

    std::filesystem::directory_iterator ls(p_str); // 得到一个列表
    std::set<std::string> filename_ls;
    int idx = 0;
    for (auto& file: ls) {
        filename_ls.insert(file.path().stem().string()); // 因为不会有同名文件所以用set
    }
    if (filename_ls.find(now_string) != filename_ls.end()) {
        const std::string nowstr_cpy = now_string;
        do {
            now_string = nowstr_cpy + std::to_string(++idx); // 从1开始对file命名
        } while (filename_ls.find(now_string)
                 != filename_ls.end()); // 直到这个文件名是新的为止停下来
    }
    RCLCPP_INFO(this->get_logger(),
                "Created File Name: %s at path: %s .",
                now_string.c_str(),
                p_str.string().c_str());
    return now_string;
}

RCLCPP_COMPONENTS_REGISTER_NODE(recorder::RecorderNode)
