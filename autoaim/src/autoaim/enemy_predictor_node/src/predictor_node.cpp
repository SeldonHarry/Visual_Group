#include "predictor_node.hpp"
#include "defs.hpp"
#include "enemy_predictor/enemy_predictor.hpp"
#include "robot.hpp"
#include <bits/stdint-intn.h>
#include <chrono>
#include <cstddef>
#include <cv_bridge/cv_bridge.h>
#include <memory>
#include <rclcpp/logging.hpp>
#include <rclcpp/parameter.hpp>
#include <rclcpp/parameter_client.hpp>
#include <rclcpp/qos.hpp>
#include <rclcpp/utilities.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <type_traits>

predictor::PredictorNode::PredictorNode(const rclcpp::NodeOptions& options):
    Node("enemy_predictor", options) {
    detect_sub_ = this->create_subscription<my_interfaces::msg::DetectionResult>(
        "detection",
        10,
        [this](const my_interfaces::msg::DetectionResult::ConstSharedPtr detect) {
            this->ros_msg_to_detection_result(this->detect_result_, detect);
            if (this->detect_result_.img.empty()) {
                RCLCPP_WARN(this->get_logger(), "In subscription: img empty");
            } else {
                //RCLCPP_WARN(this->get_logger(),"In subscription: image has content");
            }
            run_predictor_once();
        });
    RCLCPP_INFO(this->get_logger(), "detection result topic subscription created!");
    robot_status_sub_ = this->create_subscription<my_interfaces::msg::RobotStatus>(
        "minipc_topic",
        10,
        [this](const my_interfaces::msg::RobotStatus::ConstSharedPtr rbt_status_msg) {
            this->ros_msg_to_robot_status(this->robot_status_, rbt_status_msg);
        });
    //RCLCPP_WARN(this->get_logger(), "minipc_topic receive");
    robot_cmd_pub_ = this->create_publisher<my_interfaces::msg::RobotCmd>("robot_cmd", 10);
    RCLCPP_INFO(this->get_logger(), "robot command publisher created!");
    debug_img_aim_pub_ =
        this->create_publisher<sensor_msgs::msg::CompressedImage>("debug_img_aim", 10);
    RCLCPP_INFO(this->get_logger(), "predictor thread started!");
    param_visitor = [this](std::string name, param::Param& param) {
        // RCLCPP_INFO(this->get_logger(), "try to get parameter: %s", name.c_str());
        // std::replace(name.begin(), name.end(), '.', '/');
        this->visit_param(name, param);
    };
    RCLCPP_INFO(this->get_logger(), "param visitor created!");
    t1 = std::chrono::system_clock::now();
    RCLCPP_INFO(this->get_logger(), "predictor node init finished!");
}

void predictor::PredictorNode::run_predictor_once() {
    if (!debugger) {
        debugger =
            std::make_shared<ros2addon::debug::Debugger>(this->shared_from_this(), param_visitor);
        RCLCPP_INFO(this->get_logger(), "debugger created!");
    }
    if (!robot_status_ptr) {
        robot_status_ptr = std::make_shared<::RobotStatus>(robot_status_);
        RCLCPP_INFO(this->get_logger(), "robot status ptr created!");
    }
    if (!enemy_predictor_) {
        enemy_predictor_ =
            std::make_unique<aimer::EnemyPredictor>(robot_status_ptr, param_visitor, debugger);
        RCLCPP_INFO(this->get_logger(), "Enemy predictor created!");
    }
    if (robot_status_.program_mode == ::ProgramMode::ENERGY_HIT
        || robot_status_.program_mode == ::ProgramMode::ENERGY_DISTURB)
    {
        // MANUAL: 计算但不动枪口且不发射（可发信号来给 UI 反馈）
        // ENERGY相关: 停止计算进程，给能量机关计算
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        RCLCPP_INFO(this->get_logger(), "stop shooting");
        return;
    }
    predict_result_ = enemy_predictor_->predict(detect_result_);
    if (std::isnan(predict_result_.yaw) || std::isnan(predict_result_.pitch)
        || std::isinf(predict_result_.yaw) || std::isinf(predict_result_.pitch))
    {
        enemy_predictor_ = nullptr; // 删除
        enemy_predictor_ =
            std::make_unique<aimer::EnemyPredictor>(robot_status_ptr, param_visitor, debugger);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        RCLCPP_WARN(this->get_logger(), "abnormal predict result, enemy predictor aborted");
        return;
    }
    predict_result_.seq_id++;
    this->robot_cmd_to_ros_msg(robot_cmd_msg_, predict_result_);
    robot_cmd_pub_->publish(robot_cmd_msg_);

    if (!detect_result_.img.empty()) {
        publish_debug_image();
        //RCLCPP_INFO(this->get_logger(),"send picture to debugger node successfully!");
    }

    fps_count++;
    auto t2 = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() >= 1000) {
        fps = fps_count;
        fps_count = 0;
        t1 = t2;
        RCLCPP_INFO(this->get_logger(), "predict frame successfully in the last 1s! fps: %d", fps);
    }
}

void predictor::PredictorNode::publish_debug_image() {
    cv_bridge::CvImage img_bridge;
    cv::Mat im2show { enemy_predictor_->draw_aim(detect_result_.img, detect_result_) };
    cv::putText(im2show,
                fmt::format("fps={}", fps),
                { 10, 25 },
                cv::FONT_HERSHEY_SIMPLEX,
                1,
                { 0, 0, 255 });
    img_bridge.image = im2show;
    img_bridge.encoding = sensor_msgs::image_encodings::BGR8;
    sensor_msgs::msg::CompressedImage debug_img_aim;
    img_bridge.toCompressedImageMsg(debug_img_aim);
    debug_img_aim_pub_->publish(debug_img_aim);
}

void predictor::PredictorNode::visit_param(const std::string& name, param::Param& param) {
    auto visitor = [this, &param, &name](auto&& arg) -> void {
        using T = std::decay_t<decltype(arg)>;
        rclcpp::Parameter ros_param;
        if constexpr (std::is_same_v<T, int64_t>) {
            if (!this->has_parameter(name)) {
                this->declare_parameter(name, 0);
            }
            ros_param = this->get_parameter(name);
            param = ros_param.as_int();
            //RCLCPP_INFO(this->get_logger(),"successfully get parameter[INT] %s: %d",name.c_str(),ros_param.as_int());
        } else if constexpr (std::is_same_v<T, double>) {
            if (!this->has_parameter(name)) {
                this->declare_parameter(name, 0.0);
            }
            ros_param = this->get_parameter(name);
            param = ros_param.as_double();
            //RCLCPP_INFO(this->get_logger(),"successfully get parameter[DOUBLE] %s: %f",name.c_str(),ros_param.as_double());
        } else if constexpr (std::is_same_v<T, std::string>) {
            if (!this->has_parameter(name)) {
                this->declare_parameter(name, " ");
            }
            ros_param = this->get_parameter(name);
            param = ros_param.as_string();
            //RCLCPP_INFO(this->get_logger(),"successfully get parameter[DOUBLE] %s: %s",name.c_str(),ros_param.as_string().c_str());
        } else if constexpr (std::is_same_v<T, bool>) {
            if (!this->has_parameter(name)) {
                this->declare_parameter(name, false);
            }
            ros_param = this->get_parameter(name);
            param = ros_param.as_bool();
            //RCLCPP_INFO(this->get_logger(),"successfully get parameter[BOOL] %s: %d",name.c_str(),ros_param.as_bool());
        } else if constexpr (std::is_same_v<T, std::vector<int64_t>>) {
            if (!this->has_parameter(name)) {
                this->declare_parameter(name, std::vector<int64_t>(1, 0));
            }
            ros_param = this->get_parameter(name);
            param = ros_param.as_integer_array();
            //RCLCPP_INFO(this->get_logger(),"successfully get parameter[INT_ARRAY]: %s",name.c_str());
        }
    };
    try {
        std::visit(visitor, param);
    } catch (const rclcpp::exceptions::RCLError& e) {
        RCLCPP_ERROR(this->get_logger(),
                     "parameter type error: %s, detial:%s",
                     name.c_str(),
                     e.what());
    }
}

predictor::PredictorNode::~PredictorNode() = default;

#include <rclcpp_components/register_node_macro.hpp> //这个头文件一定要放在最后引入，顺序不能变
//register the node to workspace
RCLCPP_COMPONENTS_REGISTER_NODE(predictor::PredictorNode)