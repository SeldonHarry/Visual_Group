// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/ReloadFlag.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/reload_flag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_ReloadFlag_flag
{
public:
  Init_ReloadFlag_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::ReloadFlag flag(::my_interfaces::msg::ReloadFlag::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::ReloadFlag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::ReloadFlag>()
{
  return my_interfaces::msg::builder::Init_ReloadFlag_flag();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__BUILDER_HPP_
