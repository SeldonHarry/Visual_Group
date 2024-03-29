#ifndef TYPE_CONVERT_HPP
#define TYPE_CONVERT_HPP
#include <geometry_msgs/msg/point32.hpp>
#include <geometry_msgs/msg/detail/point32__struct.hpp>

#include <sensor_msgs/msg/image.hpp>
#include "my_interfaces/msg/detection_result.hpp"
#include "my_interfaces/msg/detected_armor.hpp"
#include "my_interfaces/msg/robot_status.hpp"
#include "my_interfaces/msg/robot_cmd.hpp"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "defs.hpp"
#include "robot.hpp"

namespace ros2addon
{
class TypeConvert{
public:
    //ros msg and cv
    void cv_point2f_to_ros_point32(geometry_msgs::msg::Point32 & des,const cv::Point2f & src);
    void ros_point32_to_cv_point2f(cv::Point2f & des,const geometry_msgs::msg::Point32 & src);
    void ros_msg_to_detection_result(aimer::DetectionResult & des,const my_interfaces::msg::DetectionResult::ConstSharedPtr& src);
    void ros_msg_to_robot_status(RobotStatus & des,const my_interfaces::msg::RobotStatus::ConstSharedPtr& src);
    void robot_cmd_to_ros_msg(my_interfaces::msg::RobotCmd & des,const RobotCmd & src);
}
;
}
#endif