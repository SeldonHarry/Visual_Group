// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_interfaces:msg/DetectedArmor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_interfaces/msg/detail/detected_armor__rosidl_typesupport_introspection_c.h"
#include "my_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_interfaces/msg/detail/detected_armor__functions.h"
#include "my_interfaces/msg/detail/detected_armor__struct.h"


// Include directives for member types
// Member `pts`
#include "geometry_msgs/msg/point32.h"
// Member `pts`
#include "geometry_msgs/msg/detail/point32__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_interfaces__msg__DetectedArmor__init(message_memory);
}

void my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_fini_function(void * message_memory)
{
  my_interfaces__msg__DetectedArmor__fini(message_memory);
}

size_t my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__size_function__DetectedArmor__pts(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__get_const_function__DetectedArmor__pts(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point32 * member =
    (const geometry_msgs__msg__Point32 *)(untyped_member);
  return &member[index];
}

void * my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__get_function__DetectedArmor__pts(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point32 * member =
    (geometry_msgs__msg__Point32 *)(untyped_member);
  return &member[index];
}

void my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__fetch_function__DetectedArmor__pts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point32 * item =
    ((const geometry_msgs__msg__Point32 *)
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__get_const_function__DetectedArmor__pts(untyped_member, index));
  geometry_msgs__msg__Point32 * value =
    (geometry_msgs__msg__Point32 *)(untyped_value);
  *value = *item;
}

void my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__assign_function__DetectedArmor__pts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point32 * item =
    ((geometry_msgs__msg__Point32 *)
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__get_function__DetectedArmor__pts(untyped_member, index));
  const geometry_msgs__msg__Point32 * value =
    (const geometry_msgs__msg__Point32 *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_member_array[5] = {
  {
    "pts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectedArmor, pts),  // bytes offset in struct
    NULL,  // default value
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__size_function__DetectedArmor__pts,  // size() function pointer
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__get_const_function__DetectedArmor__pts,  // get_const(index) function pointer
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__get_function__DetectedArmor__pts,  // get(index) function pointer
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__fetch_function__DetectedArmor__pts,  // fetch(index, &value) function pointer
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__assign_function__DetectedArmor__pts,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectedArmor, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectedArmor, number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "conf",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectedArmor, conf),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "conf_class",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectedArmor, conf_class),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_members = {
  "my_interfaces__msg",  // message namespace
  "DetectedArmor",  // message name
  5,  // number of fields
  sizeof(my_interfaces__msg__DetectedArmor),
  my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_member_array,  // message members
  my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_init_function,  // function to initialize message memory (memory has to be allocated)
  my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_type_support_handle = {
  0,
  &my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_interfaces, msg, DetectedArmor)() {
  my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  if (!my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_type_support_handle.typesupport_identifier) {
    my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_interfaces__msg__DetectedArmor__rosidl_typesupport_introspection_c__DetectedArmor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
