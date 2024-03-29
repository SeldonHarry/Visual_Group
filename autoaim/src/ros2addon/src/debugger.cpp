#include "debugger.hpp"
#include <chrono>
#include <cv_bridge/cv_bridge.h>
#include <rclcpp/logging.hpp>
#include <rclcpp/utilities.hpp>
namespace ros2addon::debug {
void ProcessTimer::process_begin() {
    this->begin_time = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch());
}

void ProcessTimer::print_process_time(const char* str) const {
    std::chrono::microseconds cur = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch());
    std::cout << str << ": " << cur.count() - this->begin_time.count() << " micros.\n";
}

double ProcessTimer::get_process_time() const {
    std::chrono::microseconds cur = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch());
    return (cur.count() - this->begin_time.count()) / 1e6;
}

Debugger::Debugger(const rclcpp::Node::SharedPtr ros_node,const param::ParamVisitor & param_visitor): CvDrawer(param_visitor) {
    ros_node_ = ros_node;
    client_ = ros_node_->create_client<my_interfaces::srv::DebugInfo>("web_debug");
    if (client_->wait_for_service(std::chrono::seconds(1))) {
        RCLCPP_INFO(ros_node_->get_logger(),
                    "debugger successfully connect to web_debugger service");
    } else {
        RCLCPP_ERROR(ros_node_->get_logger(), "web_debugger service timeout error");
    }
}

void Debugger::send_to_webpage(const std::string& key, const std::string& value) {
    auto request = std::make_shared<my_interfaces::srv::DebugInfo::Request>();
    request->key = key;
    request->value = value;
    auto response = client_->async_send_request(request);
    // if (response.wait_for(std::chrono::milliseconds(100)) == std::future_status::ready) {
    //     if (response.get()->ok) {
    //         RCLCPP_INFO(ros_node_->get_logger(),
    //                     "send {%s} to web_debugger successfully",
    //                     key.c_str());
    //     } else {
    //         RCLCPP_INFO(ros_node_->get_logger(), "send {%s} to web_debugger failed", key.c_str());
    //     }
    // } else {
    //     RCLCPP_ERROR(ros_node_->get_logger(),
    //                  "time out error when send {%s} to web_debugger",
    //                  key.c_str());
    // }
}

void Debugger::print_duration(const std::string& name) {
    auto start_end_time = this->get_and_register(name);
    std::string value = fmt::format("{}_到_{}_耗时", start_end_time.start, start_end_time.end)
        + fmt::format("{} 微秒", start_end_time.time);
    this->send_to_webpage("预测器效率", value);
}

template<typename... Args>
void Debugger::print_on_screen(LogLevel log_level,
                               const std::string& content,
                               const Args&... args) {
    switch (log_level) {
        case LogLevel::INFO:
            RCLCPP_INFO(ros_node_->get_logger(), content, args...);
            break;
        case LogLevel::WARNING:
            RCLCPP_INFO(ros_node_->get_logger(), content, args...);
            break;
        case LogLevel::ERROR:
            RCLCPP_ERROR(ros_node_->get_logger(), content, args...);
            break;
        case LogLevel::FATAL:
            RCLCPP_FATAL(ros_node_->get_logger(), content, args...);
    }
}
} // namespace ros2addon::debug