// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/DetectedArmor.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/detected_armor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectedArmor_conf_class
{
public:
  explicit Init_DetectedArmor_conf_class(::my_interfaces::msg::DetectedArmor & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::DetectedArmor conf_class(::my_interfaces::msg::DetectedArmor::_conf_class_type arg)
  {
    msg_.conf_class = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::DetectedArmor msg_;
};

class Init_DetectedArmor_conf
{
public:
  explicit Init_DetectedArmor_conf(::my_interfaces::msg::DetectedArmor & msg)
  : msg_(msg)
  {}
  Init_DetectedArmor_conf_class conf(::my_interfaces::msg::DetectedArmor::_conf_type arg)
  {
    msg_.conf = std::move(arg);
    return Init_DetectedArmor_conf_class(msg_);
  }

private:
  ::my_interfaces::msg::DetectedArmor msg_;
};

class Init_DetectedArmor_number
{
public:
  explicit Init_DetectedArmor_number(::my_interfaces::msg::DetectedArmor & msg)
  : msg_(msg)
  {}
  Init_DetectedArmor_conf number(::my_interfaces::msg::DetectedArmor::_number_type arg)
  {
    msg_.number = std::move(arg);
    return Init_DetectedArmor_conf(msg_);
  }

private:
  ::my_interfaces::msg::DetectedArmor msg_;
};

class Init_DetectedArmor_color
{
public:
  explicit Init_DetectedArmor_color(::my_interfaces::msg::DetectedArmor & msg)
  : msg_(msg)
  {}
  Init_DetectedArmor_number color(::my_interfaces::msg::DetectedArmor::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_DetectedArmor_number(msg_);
  }

private:
  ::my_interfaces::msg::DetectedArmor msg_;
};

class Init_DetectedArmor_pts
{
public:
  Init_DetectedArmor_pts()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedArmor_color pts(::my_interfaces::msg::DetectedArmor::_pts_type arg)
  {
    msg_.pts = std::move(arg);
    return Init_DetectedArmor_color(msg_);
  }

private:
  ::my_interfaces::msg::DetectedArmor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::DetectedArmor>()
{
  return my_interfaces::msg::builder::Init_DetectedArmor_pts();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__BUILDER_HPP_
