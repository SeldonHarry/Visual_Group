// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/AimShootMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/aim_shoot_msg_pc2_board__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AimShootMsgPC2Board & msg,
  std::ostream & out)
{
  out << "{";
  // member: yaw_angle
  {
    out << "yaw_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_angle, out);
    out << ", ";
  }

  // member: pitch_angle
  {
    out << "pitch_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_angle, out);
    out << ", ";
  }

  // member: yaw_speed
  {
    out << "yaw_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_speed, out);
    out << ", ";
  }

  // member: pitch_speed
  {
    out << "pitch_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_speed, out);
    out << ", ";
  }

  // member: dist
  {
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << ", ";
  }

  // member: shoot_flag
  {
    out << "shoot_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_flag, out);
    out << ", ";
  }

  // member: shoot_id
  {
    out << "shoot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_id, out);
    out << ", ";
  }

  // member: enemy_id
  {
    out << "enemy_id: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AimShootMsgPC2Board & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: yaw_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_angle, out);
    out << "\n";
  }

  // member: pitch_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_angle, out);
    out << "\n";
  }

  // member: yaw_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_speed, out);
    out << "\n";
  }

  // member: pitch_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_speed, out);
    out << "\n";
  }

  // member: dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << "\n";
  }

  // member: shoot_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_flag, out);
    out << "\n";
  }

  // member: shoot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_id, out);
    out << "\n";
  }

  // member: enemy_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_id: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AimShootMsgPC2Board & msg, bool use_flow_style = false)
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
  const my_interfaces::msg::AimShootMsgPC2Board & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::AimShootMsgPC2Board & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::AimShootMsgPC2Board>()
{
  return "my_interfaces::msg::AimShootMsgPC2Board";
}

template<>
inline const char * name<my_interfaces::msg::AimShootMsgPC2Board>()
{
  return "my_interfaces/msg/AimShootMsgPC2Board";
}

template<>
struct has_fixed_size<my_interfaces::msg::AimShootMsgPC2Board>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::msg::AimShootMsgPC2Board>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::msg::AimShootMsgPC2Board>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__TRAITS_HPP_
