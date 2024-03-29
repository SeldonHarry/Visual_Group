#ifndef DETECTOR_NODE_H
#define DETECTOR_NODE_H

#include "defs.hpp"
//ROS
#include "TRTModule.hpp"
#include "my_interfaces/msg/detected_armor.hpp"
#include "my_interfaces/msg/detection_result.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "robot.hpp"
#include "type_convert.hpp"
#include <Eigen/Dense>
#include <camera_info_manager/camera_info_manager.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/camera_subscriber.hpp>
#include <image_transport/image_transport.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>

namespace detector {
class DetectorNode: public rclcpp::Node, ros2addon::TypeConvert {
public:
    explicit DetectorNode(const rclcpp::NodeOptions& options);
    ~DetectorNode() override;

private:
    cv::Mat img_frame;
    image_transport::CameraSubscriber cam_sub_;
    std::vector<my_interfaces::msg::DetectedArmor> detected_armor_;
    my_interfaces::msg::DetectionResult detected_frame_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::Publisher<my_interfaces::msg::DetectionResult>::SharedPtr detect_pub_;
    rclcpp::Subscription<my_interfaces::msg::RobotStatus>::SharedPtr robot_status_sub_;
    ::RobotStatus robot_status_;
    float thres_partiel[10] = { 0.3f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.7f, 0.45f, 0.45f, 0.0f };
    std::shared_ptr<TRTModule> module;
    void run_detector_once();
    int cnt = -1;
    std::vector<bbox_t> last_outputs;
    std::chrono::time_point<std::chrono::system_clock> t1;
    int fps = 0, fps_count = 0;
    bool cmp_armor_center(my_interfaces::msg::DetectedArmor a1,
                          my_interfaces::msg::DetectedArmor a2);
};
} // namespace detector

#endif