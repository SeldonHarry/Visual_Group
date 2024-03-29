// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_interfaces:msg/NavigationPC2Board.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_interfaces/msg/detail/navigation_pc2_board__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void NavigationPC2Board_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_interfaces::msg::NavigationPC2Board(_init);
}

void NavigationPC2Board_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_interfaces::msg::NavigationPC2Board *>(message_memory);
  typed_message->~NavigationPC2Board();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NavigationPC2Board_message_member_array[3] = {
  {
    "vx",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::NavigationPC2Board, vx),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::NavigationPC2Board, vy),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "wz",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::NavigationPC2Board, wz),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NavigationPC2Board_message_members = {
  "my_interfaces::msg",  // message namespace
  "NavigationPC2Board",  // message name
  3,  // number of fields
  sizeof(my_interfaces::msg::NavigationPC2Board),
  NavigationPC2Board_message_member_array,  // message members
  NavigationPC2Board_init_function,  // function to initialize message memory (memory has to be allocated)
  NavigationPC2Board_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NavigationPC2Board_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NavigationPC2Board_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_interfaces::msg::NavigationPC2Board>()
{
  return &::my_interfaces::msg::rosidl_typesupport_introspection_cpp::NavigationPC2Board_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_interfaces, msg, NavigationPC2Board)() {
  return &::my_interfaces::msg::rosidl_typesupport_introspection_cpp::NavigationPC2Board_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
