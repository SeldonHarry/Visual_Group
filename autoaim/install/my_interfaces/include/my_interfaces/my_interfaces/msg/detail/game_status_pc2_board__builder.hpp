// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/GameStatusPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/game_status_pc2_board__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_GameStatusPC2Board_reserve
{
public:
  Init_GameStatusPC2Board_reserve()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::msg::GameStatusPC2Board reserve(::my_interfaces::msg::GameStatusPC2Board::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::GameStatusPC2Board msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::GameStatusPC2Board>()
{
  return my_interfaces::msg::builder::Init_GameStatusPC2Board_reserve();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__BUILDER_HPP_
