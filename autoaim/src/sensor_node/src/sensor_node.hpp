#ifndef SENSOR_NODE_H
#define SENSOR_NODE_H

#include "../ExtImu/ExtImu.hpp"
#include "../hikSDK/include/MvCameraControl.h"
// ROS
#include <camera_info_manager/camera_info_manager.hpp>
#include <image_transport/image_transport.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include "std_msgs/msg/string.hpp"

// namespace hik_camera
namespace sensor {
class SensorNode: public rclcpp::Node {
public:
    explicit SensorNode(const rclcpp::NodeOptions& options);
    ~SensorNode() override;

private:
    //初始化
    void init_cam_device();
    void init_imu_device();
    void init_node();
    void init_cam_param();
    void load_cam_info();
    //线程循环
    void capture_thread_loop();
    void imu_thread_loop();
    //启动线程
    void start_camera();
    void start_imu();
    //退出清理
    void close_camera();
    void close_imu();

    //参数回调函数，有参数修改时会被触发
    rcl_interfaces::msg::SetParametersResult
    parameters_callback(const std::vector<rclcpp::Parameter>& parameters);
    //参数回调句柄
    OnSetParametersCallbackHandle::SharedPtr params_callback_handle_;

    //相机相关变量
    sensor_msgs::msg::Image image_msg_; //stores camera image
    image_transport::CameraPublisher camera_pub_; //ros2 topic publisher
    int fail_conut_ = 0; //错误计数
    int nRet = MV_OK; //camera status code from hiSDk
    void* camera_handle_; // ptr to camera
    MV_IMAGE_BASIC_INFO img_info_; //info of image
    MV_CC_PIXEL_CONVERT_PARAM convert_param_; //camera conversion param
    std::string camera_name_;
    std::string camera_cfg_name_;
    std::unique_ptr<camera_info_manager::CameraInfoManager> camera_info_manager_;
    sensor_msgs::msg::CameraInfo camera_info_msg_;

    //imu相关变量
    ExtImu imu;
    sensor_msgs::msg::Imu imu_msg_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
    
    //该节点的线程
    std::thread capture_thread_; //相机线程
    std::thread imu_thread_; //imu线程
    int cam_interval;
    int sync_period_ms = 10;
    bool capture_run_flag_ = true;
    bool imu_run_flag_ = true;
};
} // namespace sensor

#endif // SENSOR_NODE_H