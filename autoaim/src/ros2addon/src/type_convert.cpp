#include "type_convert.hpp"
#include "defs.hpp"
#include "robot.hpp"
#include <bits/stdint-uintn.h>
#include <sys/types.h>

namespace ros2addon {
void TypeConvert::cv_point2f_to_ros_point32(geometry_msgs::msg::Point32& des,
                                            const cv::Point2f& src) {
    des.x = src.x;
    des.y = src.y;
}
void TypeConvert::ros_point32_to_cv_point2f(cv::Point2f& des,
                                            const geometry_msgs::msg::Point32& src) {
    des.x = src.x;
    des.y = src.y;
}
void TypeConvert::ros_msg_to_detection_result(
    aimer::DetectionResult& des,
    const my_interfaces::msg::DetectionResult::ConstSharedPtr& src) {
    des.img = cv_bridge::toCvCopy(src->img, "bgr8")->image;
    des.q.x() = src->q.x;
    des.q.y() = src->q.y;
    des.q.z() = src->q.z;
    des.q.w() = src->q.w;
    des.timestamp = src->img.header.stamp.sec  + src->img.header.stamp.nanosec / 1e9;
    des.armors.clear();
    aimer::DetectedArmor a_tmp;
    for (const auto& armor: src->armors) {
        a_tmp.color = armor.color;
        a_tmp.number = armor.number;
        a_tmp.conf = armor.conf;
        a_tmp.conf_class = armor.conf_class;
        for (int i = 0; i < 4; i++) {
            ros_point32_to_cv_point2f(a_tmp.pts[i], armor.pts[i]);
        }
        des.armors.emplace_back(a_tmp);
    }
}
void TypeConvert::ros_msg_to_robot_status(RobotStatus & des,const my_interfaces::msg::RobotStatus::ConstSharedPtr& src)
{
    des.bullet_speed = src->bullet_speed;
    des.yaw_compensate = src->yaw_compensate;
    des.pitch_compensate = src->pitch_compensate;
    des.enemy_color = static_cast<EnemyColor>(src->enemy_color);
    des.is_big_energy = src->is_big_energy;
    des.program_mode = static_cast<ProgramMode>(src->program_mode);
    des.latency_cmd_to_fire = src->latency_cmd_to_fire;
    des.last_shoot_aim_id = src->last_shoot_aim_id;
    des.laser_distance = src->laser_distance;
}
void TypeConvert::robot_cmd_to_ros_msg(my_interfaces::msg::RobotCmd& des, const RobotCmd& src) {
    des.seq_id = src.seq_id;
    des.aim_id = src.aim_id;
    des.car_id = src.car_id;
    des.detection_info = src.detection_info;
    des.yaw = src.yaw;
    des.pitch = src.pitch;
    des.yaw_v = src.yaw_v;
    des.pithc_v = src.pitch_v;
    des.dist = src.dist;
    des.shoot = static_cast<uint8_t>(src.shoot);
    des.period = src.period;
    // des.lrc = src.lrc;
    des.lock_yaw = src.lock_yaw;
}
} // namespace ros2addon
