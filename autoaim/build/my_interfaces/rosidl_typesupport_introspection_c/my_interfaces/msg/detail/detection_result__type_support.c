// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_interfaces/msg/detail/detection_result__rosidl_typesupport_introspection_c.h"
#include "my_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_interfaces/msg/detail/detection_result__functions.h"
#include "my_interfaces/msg/detail/detection_result__struct.h"


// Include directives for member types
// Member `img`
#include "sensor_msgs/msg/image.h"
// Member `img`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `q`
#include "geometry_msgs/msg/quaternion.h"
// Member `q`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"
// Member `armors`
#include "my_interfaces/msg/detected_armor.h"
// Member `armors`
#include "my_interfaces/msg/detail/detected_armor__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_interfaces__msg__DetectionResult__init(message_memory);
}

void my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_fini_function(void * message_memory)
{
  my_interfaces__msg__DetectionResult__fini(message_memory);
}

size_t my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__armors(
  const void * untyped_member)
{
  const my_interfaces__msg__DetectedArmor__Sequence * member =
    (const my_interfaces__msg__DetectedArmor__Sequence *)(untyped_member);
  return member->size;
}

const void * my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__armors(
  const void * untyped_member, size_t index)
{
  const my_interfaces__msg__DetectedArmor__Sequence * member =
    (const my_interfaces__msg__DetectedArmor__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__armors(
  void * untyped_member, size_t index)
{
  my_interfaces__msg__DetectedArmor__Sequence * member =
    (my_interfaces__msg__DetectedArmor__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__armors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const my_interfaces__msg__DetectedArmor * item =
    ((const my_interfaces__msg__DetectedArmor *)
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__armors(untyped_member, index));
  my_interfaces__msg__DetectedArmor * value =
    (my_interfaces__msg__DetectedArmor *)(untyped_value);
  *value = *item;
}

void my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__armors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  my_interfaces__msg__DetectedArmor * item =
    ((my_interfaces__msg__DetectedArmor *)
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__armors(untyped_member, index));
  const my_interfaces__msg__DetectedArmor * value =
    (const my_interfaces__msg__DetectedArmor *)(untyped_value);
  *item = *value;
}

bool my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__armors(
  void * untyped_member, size_t size)
{
  my_interfaces__msg__DetectedArmor__Sequence * member =
    (my_interfaces__msg__DetectedArmor__Sequence *)(untyped_member);
  my_interfaces__msg__DetectedArmor__Sequence__fini(member);
  return my_interfaces__msg__DetectedArmor__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[3] = {
  {
    "img",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectionResult, img),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "q",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectionResult, q),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "armors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__DetectionResult, armors),  // bytes offset in struct
    NULL,  // default value
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__armors,  // size() function pointer
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__armors,  // get_const(index) function pointer
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__armors,  // get(index) function pointer
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__armors,  // fetch(index, &value) function pointer
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__armors,  // assign(index, value) function pointer
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__armors  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_members = {
  "my_interfaces__msg",  // message namespace
  "DetectionResult",  // message name
  3,  // number of fields
  sizeof(my_interfaces__msg__DetectionResult),
  my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array,  // message members
  my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_init_function,  // function to initialize message memory (memory has to be allocated)
  my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle = {
  0,
  &my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_interfaces, msg, DetectionResult)() {
  my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_interfaces, msg, DetectedArmor)();
  if (!my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle.typesupport_identifier) {
    my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
