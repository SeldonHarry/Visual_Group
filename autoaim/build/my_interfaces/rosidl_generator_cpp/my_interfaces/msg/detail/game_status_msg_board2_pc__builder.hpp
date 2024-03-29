// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/GameStatusMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GAME_STATUS_MSG_BOARD2_PC__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__GAME_STATUS_MSG_BOARD2_PC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/game_status_msg_board2_pc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_GameStatusMsgBoard2PC_blue_base_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_base_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::GameStatusMsgBoard2PC blue_base_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_base_hp_type arg)
  {
    msg_.blue_base_hp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_outpost_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_outpost_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_base_hp blue_outpost_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_outpost_hp_type arg)
  {
    msg_.blue_outpost_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_base_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_7_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_7_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_outpost_hp blue_7_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_7_robot_hp_type arg)
  {
    msg_.blue_7_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_outpost_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_5_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_5_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_7_robot_hp blue_5_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_5_robot_hp_type arg)
  {
    msg_.blue_5_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_7_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_4_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_4_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_5_robot_hp blue_4_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_4_robot_hp_type arg)
  {
    msg_.blue_4_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_5_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_3_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_3_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_4_robot_hp blue_3_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_3_robot_hp_type arg)
  {
    msg_.blue_3_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_4_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_2_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_2_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_3_robot_hp blue_2_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_2_robot_hp_type arg)
  {
    msg_.blue_2_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_3_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_blue_1_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_blue_1_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_2_robot_hp blue_1_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_blue_1_robot_hp_type arg)
  {
    msg_.blue_1_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_2_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_base_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_base_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_blue_1_robot_hp red_base_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_base_hp_type arg)
  {
    msg_.red_base_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_blue_1_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_outpost_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_outpost_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_base_hp red_outpost_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_outpost_hp_type arg)
  {
    msg_.red_outpost_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_base_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_7_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_7_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_outpost_hp red_7_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_7_robot_hp_type arg)
  {
    msg_.red_7_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_outpost_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_5_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_5_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_7_robot_hp red_5_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_5_robot_hp_type arg)
  {
    msg_.red_5_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_7_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_4_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_4_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_5_robot_hp red_4_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_4_robot_hp_type arg)
  {
    msg_.red_4_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_5_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_3_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_3_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_4_robot_hp red_3_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_3_robot_hp_type arg)
  {
    msg_.red_3_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_4_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_2_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_2_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_3_robot_hp red_2_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_2_robot_hp_type arg)
  {
    msg_.red_2_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_3_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_red_1_robot_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_red_1_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_2_robot_hp red_1_robot_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_red_1_robot_hp_type arg)
  {
    msg_.red_1_robot_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_2_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_max_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_max_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_red_1_robot_hp max_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_max_hp_type arg)
  {
    msg_.max_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_red_1_robot_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_remain_hp
{
public:
  explicit Init_GameStatusMsgBoard2PC_remain_hp(::my_interfaces::msg::GameStatusMsgBoard2PC & msg)
  : msg_(msg)
  {}
  Init_GameStatusMsgBoard2PC_max_hp remain_hp(::my_interfaces::msg::GameStatusMsgBoard2PC::_remain_hp_type arg)
  {
    msg_.remain_hp = std::move(arg);
    return Init_GameStatusMsgBoard2PC_max_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

class Init_GameStatusMsgBoard2PC_robot_id
{
public:
  Init_GameStatusMsgBoard2PC_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameStatusMsgBoard2PC_remain_hp robot_id(::my_interfaces::msg::GameStatusMsgBoard2PC::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_GameStatusMsgBoard2PC_remain_hp(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusMsgBoard2PC msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::GameStatusMsgBoard2PC>()
{
  return my_interfaces::msg::builder::Init_GameStatusMsgBoard2PC_robot_id();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GAME_STATUS_MSG_BOARD2_PC__BUILDER_HPP_
