// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/GeneralMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/general_msg_board2_pc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_GeneralMsgBoard2PC_mode
{
public:
  Init_GeneralMsgBoard2PC_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::GeneralMsgBoard2PC mode(::my_interfaces::msg::GeneralMsgBoard2PC::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::GeneralMsgBoard2PC msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::GeneralMsgBoard2PC>()
{
  return my_interfaces::msg::builder::Init_GeneralMsgBoard2PC_mode();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__BUILDER_HPP_
