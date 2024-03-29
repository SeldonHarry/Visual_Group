// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_interfaces/msg/detail/detection_result__struct.hpp"
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

void DetectionResult_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_interfaces::msg::DetectionResult(_init);
}

void DetectionResult_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_interfaces::msg::DetectionResult *>(message_memory);
  typed_message->~DetectionResult();
}

size_t size_function__DetectionResult__armors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<my_interfaces::msg::DetectedArmor> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionResult__armors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<my_interfaces::msg::DetectedArmor> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionResult__armors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<my_interfaces::msg::DetectedArmor> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionResult__armors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const my_interfaces::msg::DetectedArmor *>(
    get_const_function__DetectionResult__armors(untyped_member, index));
  auto & value = *reinterpret_cast<my_interfaces::msg::DetectedArmor *>(untyped_value);
  value = item;
}

void assign_function__DetectionResult__armors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<my_interfaces::msg::DetectedArmor *>(
    get_function__DetectionResult__armors(untyped_member, index));
  const auto & value = *reinterpret_cast<const my_interfaces::msg::DetectedArmor *>(untyped_value);
  item = value;
}

void resize_function__DetectionResult__armors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<my_interfaces::msg::DetectedArmor> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectionResult_message_member_array[3] = {
  {
    "img",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::DetectionResult, img),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "q",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Quaternion>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::DetectionResult, q),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "armors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<my_interfaces::msg::DetectedArmor>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::DetectionResult, armors),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionResult__armors,  // size() function pointer
    get_const_function__DetectionResult__armors,  // get_const(index) function pointer
    get_function__DetectionResult__armors,  // get(index) function pointer
    fetch_function__DetectionResult__armors,  // fetch(index, &value) function pointer
    assign_function__DetectionResult__armors,  // assign(index, value) function pointer
    resize_function__DetectionResult__armors  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectionResult_message_members = {
  "my_interfaces::msg",  // message namespace
  "DetectionResult",  // message name
  3,  // number of fields
  sizeof(my_interfaces::msg::DetectionResult),
  DetectionResult_message_member_array,  // message members
  DetectionResult_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectionResult_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectionResult_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectionResult_message_members,
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
get_message_type_support_handle<my_interfaces::msg::DetectionResult>()
{
  return &::my_interfaces::msg::rosidl_typesupport_introspection_cpp::DetectionResult_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_interfaces, msg, DetectionResult)() {
  return &::my_interfaces::msg::rosidl_typesupport_introspection_cpp::DetectionResult_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
