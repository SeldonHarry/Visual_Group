#ifndef PREDICTOR_NODE_H
#define PREDICTOR_NODE_H

//ROS2
#include "my_interfaces/msg/detection_result.hpp"
#include "my_interfaces/msg/robot_cmd.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "type_convert.hpp"
#include <chrono>
#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/parameter.hpp>
#include <rclcpp/parameter_client.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/utilities.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
//predictor
#include "debugger.hpp"
#include "defs.hpp"
#include "enemy_predictor/enemy_predictor.hpp"
#include "param/param.hpp"
#include "robot.hpp"

namespace predictor {
class PredictorNode: public rclcpp::Node, public ros2addon::TypeConvert {
public:
    explicit PredictorNode(const rclcpp::NodeOptions& options);
    ~PredictorNode() override;

private:
    //预测节点原数据类型
    aimer::DetectionResult detect_result_;
    ::RobotStatus robot_status_;
    RobotCmd predict_result_;
    //ROS2节点数据和ROS2消息类型
    rclcpp::Subscription<my_interfaces::msg::DetectionResult>::SharedPtr detect_sub_;
    rclcpp::Subscription<my_interfaces::msg::RobotStatus>::SharedPtr robot_status_sub_;
    rclcpp::Publisher<my_interfaces::msg::RobotCmd>::SharedPtr robot_cmd_pub_;
    my_interfaces::msg::RobotCmd robot_cmd_msg_;
    const std::string param_node_name = "/param_manager";
    rclcpp::Publisher<sensor_msgs::msg::CompressedImage>::SharedPtr debug_img_aim_pub_;
    // rclcpp::Publisher<sensor_msgs::msg::CompressedImage>::SharedPtr debug_img_map_pub_;
    //线程相关
    std::shared_ptr<::RobotStatus> robot_status_ptr;
    std::unique_ptr<aimer::EnemyPredictor> enemy_predictor_;
    std::shared_ptr<ros2addon::debug::Debugger> debugger;
    std::chrono::time_point<std::chrono::system_clock> t1;
    std::function<void(const std::string&, param::Param&)> param_visitor;
    void visit_param(const std::string & name, param::Param& param);
    void publish_debug_image();
    void run_predictor_once();
    int fps = 0, fps_count = 0;
};
} // namespace predictor

#endif