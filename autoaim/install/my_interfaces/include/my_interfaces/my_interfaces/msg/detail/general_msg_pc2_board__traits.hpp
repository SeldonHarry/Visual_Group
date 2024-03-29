// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/GeneralMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/general_msg_pc2_board__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GeneralMsgPC2Board & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode_fdb
  {
    out << "mode_fdb: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_fdb, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GeneralMsgPC2Board & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode_fdb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode_fdb: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_fdb, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GeneralMsgPC2Board & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::msg::GeneralMsgPC2Board & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::GeneralMsgPC2Board & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::GeneralMsgPC2Board>()
{
  return "my_interfaces::msg::GeneralMsgPC2Board";
}

template<>
inline const char * name<my_interfaces::msg::GeneralMsgPC2Board>()
{
  return "my_interfaces/msg/GeneralMsgPC2Board";
}

template<>
struct has_fixed_size<my_interfaces::msg::GeneralMsgPC2Board>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::msg::GeneralMsgPC2Board>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::msg::GeneralMsgPC2Board>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__TRAITS_HPP_
