// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/AimShootMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/aim_shoot_msg_pc2_board__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_AimShootMsgPC2Board_enemy_id
{
public:
  explicit Init_AimShootMsgPC2Board_enemy_id(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::AimShootMsgPC2Board enemy_id(::my_interfaces::msg::AimShootMsgPC2Board::_enemy_id_type arg)
  {
    msg_.enemy_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_shoot_id
{
public:
  explicit Init_AimShootMsgPC2Board_shoot_id(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgPC2Board_enemy_id shoot_id(::my_interfaces::msg::AimShootMsgPC2Board::_shoot_id_type arg)
  {
    msg_.shoot_id = std::move(arg);
    return Init_AimShootMsgPC2Board_enemy_id(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_shoot_flag
{
public:
  explicit Init_AimShootMsgPC2Board_shoot_flag(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgPC2Board_shoot_id shoot_flag(::my_interfaces::msg::AimShootMsgPC2Board::_shoot_flag_type arg)
  {
    msg_.shoot_flag = std::move(arg);
    return Init_AimShootMsgPC2Board_shoot_id(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_dist
{
public:
  explicit Init_AimShootMsgPC2Board_dist(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgPC2Board_shoot_flag dist(::my_interfaces::msg::AimShootMsgPC2Board::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return Init_AimShootMsgPC2Board_shoot_flag(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_pitch_speed
{
public:
  explicit Init_AimShootMsgPC2Board_pitch_speed(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgPC2Board_dist pitch_speed(::my_interfaces::msg::AimShootMsgPC2Board::_pitch_speed_type arg)
  {
    msg_.pitch_speed = std::move(arg);
    return Init_AimShootMsgPC2Board_dist(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_yaw_speed
{
public:
  explicit Init_AimShootMsgPC2Board_yaw_speed(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgPC2Board_pitch_speed yaw_speed(::my_interfaces::msg::AimShootMsgPC2Board::_yaw_speed_type arg)
  {
    msg_.yaw_speed = std::move(arg);
    return Init_AimShootMsgPC2Board_pitch_speed(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_pitch_angle
{
public:
  explicit Init_AimShootMsgPC2Board_pitch_angle(::my_interfaces::msg::AimShootMsgPC2Board & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgPC2Board_yaw_speed pitch_angle(::my_interfaces::msg::AimShootMsgPC2Board::_pitch_angle_type arg)
  {
    msg_.pitch_angle = std::move(arg);
    return Init_AimShootMsgPC2Board_yaw_speed(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

class Init_AimShootMsgPC2Board_yaw_angle
{
public:
  Init_AimShootMsgPC2Board_yaw_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AimShootMsgPC2Board_pitch_angle yaw_angle(::my_interfaces::msg::AimShootMsgPC2Board::_yaw_angle_type arg)
  {
    msg_.yaw_angle = std::move(arg);
    return Init_AimShootMsgPC2Board_pitch_angle(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgPC2Board msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::AimShootMsgPC2Board>()
{
  return my_interfaces::msg::builder::Init_AimShootMsgPC2Board_yaw_angle();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__BUILDER_HPP_
