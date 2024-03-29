// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/aim_shoot_msg_board2_pc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_AimShootMsgBoard2PC_chassis_vy
{
public:
  explicit Init_AimShootMsgBoard2PC_chassis_vy(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::AimShootMsgBoard2PC chassis_vy(::my_interfaces::msg::AimShootMsgBoard2PC::_chassis_vy_type arg)
  {
    msg_.chassis_vy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_chassis_vx
{
public:
  explicit Init_AimShootMsgBoard2PC_chassis_vx(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_chassis_vy chassis_vx(::my_interfaces::msg::AimShootMsgBoard2PC::_chassis_vx_type arg)
  {
    msg_.chassis_vx = std::move(arg);
    return Init_AimShootMsgBoard2PC_chassis_vy(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_is_big_energy
{
public:
  explicit Init_AimShootMsgBoard2PC_is_big_energy(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_chassis_vx is_big_energy(::my_interfaces::msg::AimShootMsgBoard2PC::_is_big_energy_type arg)
  {
    msg_.is_big_energy = std::move(arg);
    return Init_AimShootMsgBoard2PC_chassis_vx(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_shoot_id_fdb
{
public:
  explicit Init_AimShootMsgBoard2PC_shoot_id_fdb(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_is_big_energy shoot_id_fdb(::my_interfaces::msg::AimShootMsgBoard2PC::_shoot_id_fdb_type arg)
  {
    msg_.shoot_id_fdb = std::move(arg);
    return Init_AimShootMsgBoard2PC_is_big_energy(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_shoot_delay
{
public:
  explicit Init_AimShootMsgBoard2PC_shoot_delay(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_shoot_id_fdb shoot_delay(::my_interfaces::msg::AimShootMsgBoard2PC::_shoot_delay_type arg)
  {
    msg_.shoot_delay = std::move(arg);
    return Init_AimShootMsgBoard2PC_shoot_id_fdb(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_shoot_speed
{
public:
  explicit Init_AimShootMsgBoard2PC_shoot_speed(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_shoot_delay shoot_speed(::my_interfaces::msg::AimShootMsgBoard2PC::_shoot_speed_type arg)
  {
    msg_.shoot_speed = std::move(arg);
    return Init_AimShootMsgBoard2PC_shoot_delay(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_dist
{
public:
  explicit Init_AimShootMsgBoard2PC_dist(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_shoot_speed dist(::my_interfaces::msg::AimShootMsgBoard2PC::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return Init_AimShootMsgBoard2PC_shoot_speed(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_pitch_offset
{
public:
  explicit Init_AimShootMsgBoard2PC_pitch_offset(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_dist pitch_offset(::my_interfaces::msg::AimShootMsgBoard2PC::_pitch_offset_type arg)
  {
    msg_.pitch_offset = std::move(arg);
    return Init_AimShootMsgBoard2PC_dist(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_yaw_offset
{
public:
  explicit Init_AimShootMsgBoard2PC_yaw_offset(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_pitch_offset yaw_offset(::my_interfaces::msg::AimShootMsgBoard2PC::_yaw_offset_type arg)
  {
    msg_.yaw_offset = std::move(arg);
    return Init_AimShootMsgBoard2PC_pitch_offset(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_pitch_speed
{
public:
  explicit Init_AimShootMsgBoard2PC_pitch_speed(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_yaw_offset pitch_speed(::my_interfaces::msg::AimShootMsgBoard2PC::_pitch_speed_type arg)
  {
    msg_.pitch_speed = std::move(arg);
    return Init_AimShootMsgBoard2PC_yaw_offset(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_yaw_speed
{
public:
  explicit Init_AimShootMsgBoard2PC_yaw_speed(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_pitch_speed yaw_speed(::my_interfaces::msg::AimShootMsgBoard2PC::_yaw_speed_type arg)
  {
    msg_.yaw_speed = std::move(arg);
    return Init_AimShootMsgBoard2PC_pitch_speed(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_pitch_angle
{
public:
  explicit Init_AimShootMsgBoard2PC_pitch_angle(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_yaw_speed pitch_angle(::my_interfaces::msg::AimShootMsgBoard2PC::_pitch_angle_type arg)
  {
    msg_.pitch_angle = std::move(arg);
    return Init_AimShootMsgBoard2PC_yaw_speed(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_yaw_angle
{
public:
  explicit Init_AimShootMsgBoard2PC_yaw_angle(::my_interfaces::msg::AimShootMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_AimShootMsgBoard2PC_pitch_angle yaw_angle(::my_interfaces::msg::AimShootMsgBoard2PC::_yaw_angle_type arg)
  {
    msg_.yaw_angle = std::move(arg);
    return Init_AimShootMsgBoard2PC_pitch_angle(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

class Init_AimShootMsgBoard2PC_self_id
{
public:
  Init_AimShootMsgBoard2PC_self_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AimShootMsgBoard2PC_yaw_angle self_id(::my_interfaces::msg::AimShootMsgBoard2PC::_self_id_type arg)
  {
    msg_.self_id = std::move(arg);
    return Init_AimShootMsgBoard2PC_yaw_angle(msg_);
  }

private:
  ::my_interfaces::msg::AimShootMsgBoard2PC msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::AimShootMsgBoard2PC>()
{
  return my_interfaces::msg::builder::Init_AimShootMsgBoard2PC_self_id();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__BUILDER_HPP_
