// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectionResult_armors
{
public:
  explicit Init_DetectionResult_armors(::my_interfaces::msg::DetectionResult & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::DetectionResult armors(::my_interfaces::msg::DetectionResult::_armors_type arg)
  {
    msg_.armors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::DetectionResult msg_;
};

class Init_DetectionResult_q
{
public:
  explicit Init_DetectionResult_q(::my_interfaces::msg::DetectionResult & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_armors q(::my_interfaces::msg::DetectionResult::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_DetectionResult_armors(msg_);
  }

private:
  ::my_interfaces::msg::DetectionResult msg_;
};

class Init_DetectionResult_img
{
public:
  Init_DetectionResult_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionResult_q img(::my_interfaces::msg::DetectionResult::_img_type arg)
  {
    msg_.img = std::move(arg);
    return Init_DetectionResult_q(msg_);
  }

private:
  ::my_interfaces::msg::DetectionResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::DetectionResult>()
{
  return my_interfaces::msg::builder::Init_DetectionResult_img();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_
