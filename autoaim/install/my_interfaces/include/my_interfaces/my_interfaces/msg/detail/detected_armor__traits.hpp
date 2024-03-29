// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/DetectedArmor.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/detected_armor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pts'
#include "geometry_msgs/msg/detail/point32__traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedArmor & msg,
  std::ostream & out)
{
  out << "{";
  // member: pts
  {
    if (msg.pts.size() == 0) {
      out << "pts: []";
    } else {
      out << "pts: [";
      size_t pending_items = msg.pts.size();
      for (auto item : msg.pts) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: number
  {
    out << "number: ";
    rosidl_generator_traits::value_to_yaml(msg.number, out);
    out << ", ";
  }

  // member: conf
  {
    out << "conf: ";
    rosidl_generator_traits::value_to_yaml(msg.conf, out);
    out << ", ";
  }

  // member: conf_class
  {
    out << "conf_class: ";
    rosidl_generator_traits::value_to_yaml(msg.conf_class, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedArmor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pts.size() == 0) {
      out << "pts: []\n";
    } else {
      out << "pts:\n";
      for (auto item : msg.pts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << "\n";
  }

  // member: number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "number: ";
    rosidl_generator_traits::value_to_yaml(msg.number, out);
    out << "\n";
  }

  // member: conf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "conf: ";
    rosidl_generator_traits::value_to_yaml(msg.conf, out);
    out << "\n";
  }

  // member: conf_class
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "conf_class: ";
    rosidl_generator_traits::value_to_yaml(msg.conf_class, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedArmor & msg, bool use_flow_style = false)
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
  const my_interfaces::msg::DetectedArmor & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::DetectedArmor & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::DetectedArmor>()
{
  return "my_interfaces::msg::DetectedArmor";
}

template<>
inline const char * name<my_interfaces::msg::DetectedArmor>()
{
  return "my_interfaces/msg/DetectedArmor";
}

template<>
struct has_fixed_size<my_interfaces::msg::DetectedArmor>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct has_bounded_size<my_interfaces::msg::DetectedArmor>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct is_message<my_interfaces::msg::DetectedArmor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__TRAITS_HPP_
