// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/RobotCmd.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/robot_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotCmd_end
{
public:
  explicit Init_RobotCmd_end(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::RobotCmd end(::my_interfaces::msg::RobotCmd::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_lock_yaw
{
public:
  explicit Init_RobotCmd_lock_yaw(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_end lock_yaw(::my_interfaces::msg::RobotCmd::_lock_yaw_type arg)
  {
    msg_.lock_yaw = std::move(arg);
    return Init_RobotCmd_end(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_lrc
{
public:
  explicit Init_RobotCmd_lrc(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_lock_yaw lrc(::my_interfaces::msg::RobotCmd::_lrc_type arg)
  {
    msg_.lrc = std::move(arg);
    return Init_RobotCmd_lock_yaw(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_period
{
public:
  explicit Init_RobotCmd_period(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_lrc period(::my_interfaces::msg::RobotCmd::_period_type arg)
  {
    msg_.period = std::move(arg);
    return Init_RobotCmd_lrc(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_shoot
{
public:
  explicit Init_RobotCmd_shoot(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_period shoot(::my_interfaces::msg::RobotCmd::_shoot_type arg)
  {
    msg_.shoot = std::move(arg);
    return Init_RobotCmd_period(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_dist
{
public:
  explicit Init_RobotCmd_dist(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_shoot dist(::my_interfaces::msg::RobotCmd::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return Init_RobotCmd_shoot(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_pithc_v
{
public:
  explicit Init_RobotCmd_pithc_v(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_dist pithc_v(::my_interfaces::msg::RobotCmd::_pithc_v_type arg)
  {
    msg_.pithc_v = std::move(arg);
    return Init_RobotCmd_dist(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_yaw_v
{
public:
  explicit Init_RobotCmd_yaw_v(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_pithc_v yaw_v(::my_interfaces::msg::RobotCmd::_yaw_v_type arg)
  {
    msg_.yaw_v = std::move(arg);
    return Init_RobotCmd_pithc_v(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_pitch
{
public:
  explicit Init_RobotCmd_pitch(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_yaw_v pitch(::my_interfaces::msg::RobotCmd::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_RobotCmd_yaw_v(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_yaw
{
public:
  explicit Init_RobotCmd_yaw(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_pitch yaw(::my_interfaces::msg::RobotCmd::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_RobotCmd_pitch(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_detection_info
{
public:
  explicit Init_RobotCmd_detection_info(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_yaw detection_info(::my_interfaces::msg::RobotCmd::_detection_info_type arg)
  {
    msg_.detection_info = std::move(arg);
    return Init_RobotCmd_yaw(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_car_id
{
public:
  explicit Init_RobotCmd_car_id(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_detection_info car_id(::my_interfaces::msg::RobotCmd::_car_id_type arg)
  {
    msg_.car_id = std::move(arg);
    return Init_RobotCmd_detection_info(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_aim_id
{
public:
  explicit Init_RobotCmd_aim_id(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_car_id aim_id(::my_interfaces::msg::RobotCmd::_aim_id_type arg)
  {
    msg_.aim_id = std::move(arg);
    return Init_RobotCmd_car_id(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_seq_id
{
public:
  explicit Init_RobotCmd_seq_id(::my_interfaces::msg::RobotCmd & msg)
  : msg_(msg)
  {}
  Init_RobotCmd_aim_id seq_id(::my_interfaces::msg::RobotCmd::_seq_id_type arg)
  {
    msg_.seq_id = std::move(arg);
    return Init_RobotCmd_aim_id(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

class Init_RobotCmd_start
{
public:
  Init_RobotCmd_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCmd_seq_id start(::my_interfaces::msg::RobotCmd::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_RobotCmd_seq_id(msg_);
  }

private:
  ::my_interfaces::msg::RobotCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::RobotCmd>()
{
  return my_interfaces::msg::builder::Init_RobotCmd_start();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__BUILDER_HPP_
