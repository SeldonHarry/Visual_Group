// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:srv/DebugInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__DEBUG_INFO__TRAITS_HPP_
#define MY_INTERFACES__SRV__DETAIL__DEBUG_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/srv/detail/debug_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DebugInfo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << ", ";
  }

  // member: key
  {
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DebugInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }

  // member: key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DebugInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::srv::DebugInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::srv::DebugInfo_Request & msg)
{
  return my_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::srv::DebugInfo_Request>()
{
  return "my_interfaces::srv::DebugInfo_Request";
}

template<>
inline const char * name<my_interfaces::srv::DebugInfo_Request>()
{
  return "my_interfaces/srv/DebugInfo_Request";
}

template<>
struct has_fixed_size<my_interfaces::srv::DebugInfo_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_interfaces::srv::DebugInfo_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_interfaces::srv::DebugInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DebugInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ok
  {
    out << "ok: ";
    rosidl_generator_traits::value_to_yaml(msg.ok, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DebugInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ok: ";
    rosidl_generator_traits::value_to_yaml(msg.ok, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DebugInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::srv::DebugInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::srv::DebugInfo_Response & msg)
{
  return my_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::srv::DebugInfo_Response>()
{
  return "my_interfaces::srv::DebugInfo_Response";
}

template<>
inline const char * name<my_interfaces::srv::DebugInfo_Response>()
{
  return "my_interfaces/srv/DebugInfo_Response";
}

template<>
struct has_fixed_size<my_interfaces::srv::DebugInfo_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_interfaces::srv::DebugInfo_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_interfaces::srv::DebugInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_interfaces::srv::DebugInfo>()
{
  return "my_interfaces::srv::DebugInfo";
}

template<>
inline const char * name<my_interfaces::srv::DebugInfo>()
{
  return "my_interfaces/srv/DebugInfo";
}

template<>
struct has_fixed_size<my_interfaces::srv::DebugInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<my_interfaces::srv::DebugInfo_Request>::value &&
    has_fixed_size<my_interfaces::srv::DebugInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_interfaces::srv::DebugInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<my_interfaces::srv::DebugInfo_Request>::value &&
    has_bounded_size<my_interfaces::srv::DebugInfo_Response>::value
  >
{
};

template<>
struct is_service<my_interfaces::srv::DebugInfo>
  : std::true_type
{
};

template<>
struct is_service_request<my_interfaces::srv::DebugInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_interfaces::srv::DebugInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__SRV__DETAIL__DEBUG_INFO__TRAITS_HPP_
