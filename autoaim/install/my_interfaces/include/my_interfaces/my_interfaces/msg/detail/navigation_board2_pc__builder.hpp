// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/NavigationBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__NAVIGATION_BOARD2_PC__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__NAVIGATION_BOARD2_PC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/navigation_board2_pc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavigationBoard2PC_theta
{
public:
  explicit Init_NavigationBoard2PC_theta(::my_interfaces::msg::NavigationBoard2PC & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::NavigationBoard2PC theta(::my_interfaces::msg::NavigationBoard2PC::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::NavigationBoard2PC msg_;
};

class Init_NavigationBoard2PC_y
{
public:
  explicit Init_NavigationBoard2PC_y(::my_interfaces::msg::NavigationBoard2PC & msg)
  : msg_(msg)
  {}
  Init_NavigationBoard2PC_theta y(::my_interfaces::msg::NavigationBoard2PC::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NavigationBoard2PC_theta(msg_);
  }

private:
  ::my_interfaces::msg::NavigationBoard2PC msg_;
};

class Init_NavigationBoard2PC_x
{
public:
  Init_NavigationBoard2PC_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationBoard2PC_y x(::my_interfaces::msg::NavigationBoard2PC::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NavigationBoard2PC_y(msg_);
  }

private:
  ::my_interfaces::msg::NavigationBoard2PC msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::NavigationBoard2PC>()
{
  return my_interfaces::msg::builder::Init_NavigationBoard2PC_x();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__NAVIGATION_BOARD2_PC__BUILDER_HPP_
