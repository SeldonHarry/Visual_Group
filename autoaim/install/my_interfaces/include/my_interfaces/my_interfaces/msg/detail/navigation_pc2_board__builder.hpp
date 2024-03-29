// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/NavigationPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__NAVIGATION_PC2_BOARD__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__NAVIGATION_PC2_BOARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/navigation_pc2_board__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavigationPC2Board_wz
{
public:
  explicit Init_NavigationPC2Board_wz(::my_interfaces::msg::NavigationPC2Board & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::NavigationPC2Board wz(::my_interfaces::msg::NavigationPC2Board::_wz_type arg)
  {
    msg_.wz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::NavigationPC2Board msg_;
};

class Init_NavigationPC2Board_vy
{
public:
  explicit Init_NavigationPC2Board_vy(::my_interfaces::msg::NavigationPC2Board & msg)
  : msg_(msg)
  {}
  Init_NavigationPC2Board_wz vy(::my_interfaces::msg::NavigationPC2Board::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_NavigationPC2Board_wz(msg_);
  }

private:
  ::my_interfaces::msg::NavigationPC2Board msg_;
};

class Init_NavigationPC2Board_vx
{
public:
  Init_NavigationPC2Board_vx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationPC2Board_vy vx(::my_interfaces::msg::NavigationPC2Board::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_NavigationPC2Board_vy(msg_);
  }

private:
  ::my_interfaces::msg::NavigationPC2Board msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::NavigationPC2Board>()
{
  return my_interfaces::msg::builder::Init_NavigationPC2Board_vx();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__NAVIGATION_PC2_BOARD__BUILDER_HPP_
