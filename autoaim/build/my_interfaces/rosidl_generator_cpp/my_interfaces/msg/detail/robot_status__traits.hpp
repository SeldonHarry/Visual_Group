// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: bullet_speed
  {
    out << "bullet_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.bullet_speed, out);
    out << ", ";
  }

  // member: yaw_compensate
  {
    out << "yaw_compensate: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_compensate, out);
    out << ", ";
  }

  // member: pitch_compensate
  {
    out << "pitch_compensate: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_compensate, out);
    out << ", ";
  }

  // member: enemy_color
  {
    out << "enemy_color: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_color, out);
    out << ", ";
  }

  // member: is_big_energy
  {
    out << "is_big_energy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_big_energy, out);
    out << ", ";
  }

  // member: program_mode
  {
    out << "program_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.program_mode, out);
    out << ", ";
  }

  // member: latency_cmd_to_fire
  {
    out << "latency_cmd_to_fire: ";
    rosidl_generator_traits::value_to_yaml(msg.latency_cmd_to_fire, out);
    out << ", ";
  }

  // member: last_shoot_aim_id
  {
    out << "last_shoot_aim_id: ";
    rosidl_generator_traits::value_to_yaml(msg.last_shoot_aim_id, out);
    out << ", ";
  }

  // member: laser_distance
  {
    out << "laser_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.laser_distance, out);
    out << ", ";
  }

  // member: lrc
  {
    out << "lrc: ";
    rosidl_generator_traits::value_to_yaml(msg.lrc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: bullet_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bullet_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.bullet_speed, out);
    out << "\n";
  }

  // member: yaw_compensate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_compensate: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_compensate, out);
    out << "\n";
  }

  // member: pitch_compensate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_compensate: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_compensate, out);
    out << "\n";
  }

  // member: enemy_color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enemy_color: ";
    rosidl_generator_traits::value_to_yaml(msg.enemy_color, out);
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

  // member: program_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "program_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.program_mode, out);
    out << "\n";
  }

  // member: latency_cmd_to_fire
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latency_cmd_to_fire: ";
    rosidl_generator_traits::value_to_yaml(msg.latency_cmd_to_fire, out);
    out << "\n";
  }

  // member: last_shoot_aim_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_shoot_aim_id: ";
    rosidl_generator_traits::value_to_yaml(msg.last_shoot_aim_id, out);
    out << "\n";
  }

  // member: laser_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "laser_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.laser_distance, out);
    out << "\n";
  }

  // member: lrc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lrc: ";
    rosidl_generator_traits::value_to_yaml(msg.lrc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
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
  const my_interfaces::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::RobotStatus & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::RobotStatus>()
{
  return "my_interfaces::msg::RobotStatus";
}

template<>
inline const char * name<my_interfaces::msg::RobotStatus>()
{
  return "my_interfaces/msg/RobotStatus";
}

template<>
struct has_fixed_size<my_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::msg::RobotStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
