// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/aim_shoot_msg_board2_pc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AimShootMsgBoard2PC & msg,
  std::ostream & out)
{
  out << "{";
  // member: self_id
  {
    out << "self_id: ";
    rosidl_generator_traits::value_to_yaml(msg.self_id, out);
    out << ", ";
  }

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

  // member: yaw_offset
  {
    out << "yaw_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_offset, out);
    out << ", ";
  }

  // member: pitch_offset
  {
    out << "pitch_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_offset, out);
    out << ", ";
  }

  // member: dist
  {
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << ", ";
  }

  // member: shoot_speed
  {
    out << "shoot_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_speed, out);
    out << ", ";
  }

  // member: shoot_delay
  {
    out << "shoot_delay: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_delay, out);
    out << ", ";
  }

  // member: shoot_id_fdb
  {
    out << "shoot_id_fdb: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_id_fdb, out);
    out << ", ";
  }

  // member: is_big_energy
  {
    out << "is_big_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_big_energy, out);
    out << ", ";
  }

  // member: chassis_vx
  {
    out << "chassis_vx: ";
    rosidl_generator_traits::value_to_yaml(msg.chassis_vx, out);
    out << ", ";
  }

  // member: chassis_vy
  {
    out << "chassis_vy: ";
    rosidl_generator_traits::value_to_yaml(msg.chassis_vy, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AimShootMsgBoard2PC & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: self_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "self_id: ";
    rosidl_generator_traits::value_to_yaml(msg.self_id, out);
    out << "\n";
  }

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

  // member: yaw_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_offset, out);
    out << "\n";
  }

  // member: pitch_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_offset, out);
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

  // member: shoot_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_speed, out);
    out << "\n";
  }

  // member: shoot_delay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot_delay: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_delay, out);
    out << "\n";
  }

  // member: shoot_id_fdb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot_id_fdb: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot_id_fdb, out);
    out << "\n";
  }

  // member: is_big_energy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_big_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_big_energy, out);
    out << "\n";
  }

  // member: chassis_vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chassis_vx: ";
    rosidl_generator_traits::value_to_yaml(msg.chassis_vx, out);
    out << "\n";
  }

  // member: chassis_vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chassis_vy: ";
    rosidl_generator_traits::value_to_yaml(msg.chassis_vy, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AimShootMsgBoard2PC & msg, bool use_flow_style = false)
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
  const my_interfaces::msg::AimShootMsgBoard2PC & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::AimShootMsgBoard2PC & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::AimShootMsgBoard2PC>()
{
  return "my_interfaces::msg::AimShootMsgBoard2PC";
}

template<>
inline const char * name<my_interfaces::msg::AimShootMsgBoard2PC>()
{
  return "my_interfaces/msg/AimShootMsgBoard2PC";
}

template<>
struct has_fixed_size<my_interfaces::msg::AimShootMsgBoard2PC>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::msg::AimShootMsgBoard2PC>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::msg::AimShootMsgBoard2PC>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__TRAITS_HPP_
