// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/RobotCmd.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/robot_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << ", ";
  }

  // member: seq_id
  {
    out << "seq_id: ";
    rosidl_generator_traits::value_to_yaml(msg.seq_id, out);
    out << ", ";
  }

  // member: aim_id
  {
    out << "aim_id: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_id, out);
    out << ", ";
  }

  // member: car_id
  {
    out << "car_id: ";
    rosidl_generator_traits::value_to_yaml(msg.car_id, out);
    out << ", ";
  }

  // member: detection_info
  {
    out << "detection_info: ";
    rosidl_generator_traits::value_to_yaml(msg.detection_info, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw_v
  {
    out << "yaw_v: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_v, out);
    out << ", ";
  }

  // member: pithc_v
  {
    out << "pithc_v: ";
    rosidl_generator_traits::value_to_yaml(msg.pithc_v, out);
    out << ", ";
  }

  // member: dist
  {
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << ", ";
  }

  // member: shoot
  {
    out << "shoot: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot, out);
    out << ", ";
  }

  // member: period
  {
    out << "period: ";
    rosidl_generator_traits::value_to_yaml(msg.period, out);
    out << ", ";
  }

  // member: lrc
  {
    out << "lrc: ";
    rosidl_generator_traits::value_to_yaml(msg.lrc, out);
    out << ", ";
  }

  // member: lock_yaw
  {
    out << "lock_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.lock_yaw, out);
    out << ", ";
  }

  // member: end
  {
    out << "end: ";
    rosidl_generator_traits::value_to_yaml(msg.end, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }

  // member: seq_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seq_id: ";
    rosidl_generator_traits::value_to_yaml(msg.seq_id, out);
    out << "\n";
  }

  // member: aim_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aim_id: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_id, out);
    out << "\n";
  }

  // member: car_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "car_id: ";
    rosidl_generator_traits::value_to_yaml(msg.car_id, out);
    out << "\n";
  }

  // member: detection_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detection_info: ";
    rosidl_generator_traits::value_to_yaml(msg.detection_info, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_v: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_v, out);
    out << "\n";
  }

  // member: pithc_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pithc_v: ";
    rosidl_generator_traits::value_to_yaml(msg.pithc_v, out);
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

  // member: shoot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoot: ";
    rosidl_generator_traits::value_to_yaml(msg.shoot, out);
    out << "\n";
  }

  // member: period
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "period: ";
    rosidl_generator_traits::value_to_yaml(msg.period, out);
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

  // member: lock_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lock_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.lock_yaw, out);
    out << "\n";
  }

  // member: end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end: ";
    rosidl_generator_traits::value_to_yaml(msg.end, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotCmd & msg, bool use_flow_style = false)
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
  const my_interfaces::msg::RobotCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::RobotCmd & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::RobotCmd>()
{
  return "my_interfaces::msg::RobotCmd";
}

template<>
inline const char * name<my_interfaces::msg::RobotCmd>()
{
  return "my_interfaces/msg/RobotCmd";
}

template<>
struct has_fixed_size<my_interfaces::msg::RobotCmd>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::msg::RobotCmd>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::msg::RobotCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__TRAITS_HPP_
