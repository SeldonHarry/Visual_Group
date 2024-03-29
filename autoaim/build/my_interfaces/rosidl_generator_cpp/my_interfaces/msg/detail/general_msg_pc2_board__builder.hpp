// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/GeneralMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/general_msg_pc2_board__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_GeneralMsgPC2Board_mode_fdb
{
public:
  Init_GeneralMsgPC2Board_mode_fdb()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::GeneralMsgPC2Board mode_fdb(::my_interfaces::msg::GeneralMsgPC2Board::_mode_fdb_type arg)
  {
    msg_.mode_fdb = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::GeneralMsgPC2Board msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::GeneralMsgPC2Board>()
{
  return my_interfaces::msg::builder::Init_GeneralMsgPC2Board_mode_fdb();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__BUILDER_HPP_
