// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:srv/DebugInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__SRV__DETAIL__DEBUG_INFO__BUILDER_HPP_
#define MY_INTERFACES__SRV__DETAIL__DEBUG_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/srv/detail/debug_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace srv
{

namespace builder
{

class Init_DebugInfo_Request_value
{
public:
  explicit Init_DebugInfo_Request_value(::my_interfaces::srv::DebugInfo_Request & msg)
  : msg_(msg)
  {}
  ::my_interfaces::srv::DebugInfo_Request value(::my_interfaces::srv::DebugInfo_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::srv::DebugInfo_Request msg_;
};

class Init_DebugInfo_Request_key
{
public:
  explicit Init_DebugInfo_Request_key(::my_interfaces::srv::DebugInfo_Request & msg)
  : msg_(msg)
  {}
  Init_DebugInfo_Request_value key(::my_interfaces::srv::DebugInfo_Request::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_DebugInfo_Request_value(msg_);
  }

private:
  ::my_interfaces::srv::DebugInfo_Request msg_;
};

class Init_DebugInfo_Request_node_name
{
public:
  Init_DebugInfo_Request_node_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DebugInfo_Request_key node_name(::my_interfaces::srv::DebugInfo_Request::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_DebugInfo_Request_key(msg_);
  }

private:
  ::my_interfaces::srv::DebugInfo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::srv::DebugInfo_Request>()
{
  return my_interfaces::srv::builder::Init_DebugInfo_Request_node_name();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace srv
{

namespace builder
{

class Init_DebugInfo_Response_ok
{
public:
  Init_DebugInfo_Response_ok()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::srv::DebugInfo_Response ok(::my_interfaces::srv::DebugInfo_Response::_ok_type arg)
  {
    msg_.ok = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::srv::DebugInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::srv::DebugInfo_Response>()
{
  return my_interfaces::srv::builder::Init_DebugInfo_Response_ok();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__SRV__DETAIL__DEBUG_INFO__BUILDER_HPP_
