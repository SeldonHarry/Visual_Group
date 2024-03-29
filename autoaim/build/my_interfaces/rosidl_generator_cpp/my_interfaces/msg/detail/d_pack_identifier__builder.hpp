// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/DPackIdentifier.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/d_pack_identifier__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_DPackIdentifier_frame_id
{
public:
  Init_DPackIdentifier_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::DPackIdentifier frame_id(::my_interfaces::msg::DPackIdentifier::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::DPackIdentifier msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::DPackIdentifier>()
{
  return my_interfaces::msg::builder::Init_DPackIdentifier_frame_id();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__BUILDER_HPP_
