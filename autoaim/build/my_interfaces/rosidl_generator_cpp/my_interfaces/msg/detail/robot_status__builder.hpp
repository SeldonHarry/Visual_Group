// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_lrc
{
public:
  explicit Init_RobotStatus_lrc(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::RobotStatus lrc(::my_interfaces::msg::RobotStatus::_lrc_type arg)
  {
    msg_.lrc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_laser_distance
{
public:
  explicit Init_RobotStatus_laser_distance(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_lrc laser_distance(::my_interfaces::msg::RobotStatus::_laser_distance_type arg)
  {
    msg_.laser_distance = std::move(arg);
    return Init_RobotStatus_lrc(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_last_shoot_aim_id
{
public:
  explicit Init_RobotStatus_last_shoot_aim_id(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_laser_distance last_shoot_aim_id(::my_interfaces::msg::RobotStatus::_last_shoot_aim_id_type arg)
  {
    msg_.last_shoot_aim_id = std::move(arg);
    return Init_RobotStatus_laser_distance(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_latency_cmd_to_fire
{
public:
  explicit Init_RobotStatus_latency_cmd_to_fire(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_last_shoot_aim_id latency_cmd_to_fire(::my_interfaces::msg::RobotStatus::_latency_cmd_to_fire_type arg)
  {
    msg_.latency_cmd_to_fire = std::move(arg);
    return Init_RobotStatus_last_shoot_aim_id(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_program_mode
{
public:
  explicit Init_RobotStatus_program_mode(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_latency_cmd_to_fire program_mode(::my_interfaces::msg::RobotStatus::_program_mode_type arg)
  {
    msg_.program_mode = std::move(arg);
    return Init_RobotStatus_latency_cmd_to_fire(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_is_big_energy
{
public:
  explicit Init_RobotStatus_is_big_energy(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_program_mode is_big_energy(::my_interfaces::msg::RobotStatus::_is_big_energy_type arg)
  {
    msg_.is_big_energy = std::move(arg);
    return Init_RobotStatus_program_mode(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_enemy_color
{
public:
  explicit Init_RobotStatus_enemy_color(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_is_big_energy enemy_color(::my_interfaces::msg::RobotStatus::_enemy_color_type arg)
  {
    msg_.enemy_color = std::move(arg);
    return Init_RobotStatus_is_big_energy(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_pitch_compensate
{
public:
  explicit Init_RobotStatus_pitch_compensate(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_enemy_color pitch_compensate(::my_interfaces::msg::RobotStatus::_pitch_compensate_type arg)
  {
    msg_.pitch_compensate = std::move(arg);
    return Init_RobotStatus_enemy_color(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_yaw_compensate
{
public:
  explicit Init_RobotStatus_yaw_compensate(::my_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_pitch_compensate yaw_compensate(::my_interfaces::msg::RobotStatus::_yaw_compensate_type arg)
  {
    msg_.yaw_compensate = std::move(arg);
    return Init_RobotStatus_pitch_compensate(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_bullet_speed
{
public:
  Init_RobotStatus_bullet_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_yaw_compensate bullet_speed(::my_interfaces::msg::RobotStatus::_bullet_speed_type arg)
  {
    msg_.bullet_speed = std::move(arg);
    return Init_RobotStatus_yaw_compensate(msg_);
  }

private:
  ::my_interfaces::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::RobotStatus>()
{
  return my_interfaces::msg::builder::Init_RobotStatus_bullet_speed();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
