// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'q'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"
// Member 'armors'
#include "my_interfaces/msg/detail/detected_armor__traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: img
  {
    out << "img: ";
    to_flow_style_yaml(msg.img, out);
    out << ", ";
  }

  // member: q
  {
    out << "q: ";
    to_flow_style_yaml(msg.q, out);
    out << ", ";
  }

  // member: armors
  {
    if (msg.armors.size() == 0) {
      out << "armors: []";
    } else {
      out << "armors: [";
      size_t pending_items = msg.armors.size();
      for (auto item : msg.armors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: img
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "img:\n";
    to_block_style_yaml(msg.img, out, indentation + 2);
  }

  // member: q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q:\n";
    to_block_style_yaml(msg.q, out, indentation + 2);
  }

  // member: armors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.armors.size() == 0) {
      out << "armors: []\n";
    } else {
      out << "armors:\n";
      for (auto item : msg.armors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionResult & msg, bool use_flow_style = false)
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
  const my_interfaces::msg::DetectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::DetectionResult & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::DetectionResult>()
{
  return "my_interfaces::msg::DetectionResult";
}

template<>
inline const char * name<my_interfaces::msg::DetectionResult>()
{
  return "my_interfaces/msg/DetectionResult";
}

template<>
struct has_fixed_size<my_interfaces::msg::DetectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_interfaces::msg::DetectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_interfaces::msg::DetectionResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_
