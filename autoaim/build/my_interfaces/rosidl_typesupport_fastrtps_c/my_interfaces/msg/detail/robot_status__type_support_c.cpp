// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/robot_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_interfaces/msg/detail/robot_status__struct.h"
#include "my_interfaces/msg/detail/robot_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RobotStatus__ros_msg_type = my_interfaces__msg__RobotStatus;

static bool _RobotStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotStatus__ros_msg_type * ros_message = static_cast<const _RobotStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: bullet_speed
  {
    cdr << ros_message->bullet_speed;
  }

  // Field name: yaw_compensate
  {
    cdr << ros_message->yaw_compensate;
  }

  // Field name: pitch_compensate
  {
    cdr << ros_message->pitch_compensate;
  }

  // Field name: enemy_color
  {
    cdr << ros_message->enemy_color;
  }

  // Field name: is_big_energy
  {
    cdr << ros_message->is_big_energy;
  }

  // Field name: program_mode
  {
    cdr << ros_message->program_mode;
  }

  // Field name: latency_cmd_to_fire
  {
    cdr << ros_message->latency_cmd_to_fire;
  }

  // Field name: last_shoot_aim_id
  {
    cdr << ros_message->last_shoot_aim_id;
  }

  // Field name: laser_distance
  {
    cdr << ros_message->laser_distance;
  }

  // Field name: lrc
  {
    cdr << ros_message->lrc;
  }

  return true;
}

static bool _RobotStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotStatus__ros_msg_type * ros_message = static_cast<_RobotStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: bullet_speed
  {
    cdr >> ros_message->bullet_speed;
  }

  // Field name: yaw_compensate
  {
    cdr >> ros_message->yaw_compensate;
  }

  // Field name: pitch_compensate
  {
    cdr >> ros_message->pitch_compensate;
  }

  // Field name: enemy_color
  {
    cdr >> ros_message->enemy_color;
  }

  // Field name: is_big_energy
  {
    cdr >> ros_message->is_big_energy;
  }

  // Field name: program_mode
  {
    cdr >> ros_message->program_mode;
  }

  // Field name: latency_cmd_to_fire
  {
    cdr >> ros_message->latency_cmd_to_fire;
  }

  // Field name: last_shoot_aim_id
  {
    cdr >> ros_message->last_shoot_aim_id;
  }

  // Field name: laser_distance
  {
    cdr >> ros_message->laser_distance;
  }

  // Field name: lrc
  {
    cdr >> ros_message->lrc;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t get_serialized_size_my_interfaces__msg__RobotStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotStatus__ros_msg_type * ros_message = static_cast<const _RobotStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name bullet_speed
  {
    size_t item_size = sizeof(ros_message->bullet_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_compensate
  {
    size_t item_size = sizeof(ros_message->yaw_compensate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_compensate
  {
    size_t item_size = sizeof(ros_message->pitch_compensate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name enemy_color
  {
    size_t item_size = sizeof(ros_message->enemy_color);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_big_energy
  {
    size_t item_size = sizeof(ros_message->is_big_energy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name program_mode
  {
    size_t item_size = sizeof(ros_message->program_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name latency_cmd_to_fire
  {
    size_t item_size = sizeof(ros_message->latency_cmd_to_fire);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name last_shoot_aim_id
  {
    size_t item_size = sizeof(ros_message->last_shoot_aim_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name laser_distance
  {
    size_t item_size = sizeof(ros_message->laser_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lrc
  {
    size_t item_size = sizeof(ros_message->lrc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_interfaces__msg__RobotStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t max_serialized_size_my_interfaces__msg__RobotStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: bullet_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_compensate
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_compensate
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: enemy_color
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_big_energy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: program_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: latency_cmd_to_fire
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: last_shoot_aim_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: laser_distance
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: lrc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_interfaces__msg__RobotStatus;
    is_plain =
      (
      offsetof(DataType, lrc) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_interfaces__msg__RobotStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotStatus = {
  "my_interfaces::msg",
  "RobotStatus",
  _RobotStatus__cdr_serialize,
  _RobotStatus__cdr_deserialize,
  _RobotStatus__get_serialized_size,
  _RobotStatus__max_serialized_size
};

static rosidl_message_type_support_t _RobotStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, msg, RobotStatus)() {
  return &_RobotStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
