// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/PCWorkMode.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/pc_work_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_PCWorkMode_mode
{
public:
  Init_PCWorkMode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::PCWorkMode mode(::my_interfaces::msg::PCWorkMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::PCWorkMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::PCWorkMode>()
{
  return my_interfaces::msg::builder::Init_PCWorkMode_mode();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__BUILDER_HPP_
