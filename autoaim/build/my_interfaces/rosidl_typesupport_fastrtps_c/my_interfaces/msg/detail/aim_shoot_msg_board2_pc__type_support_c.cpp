// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/aim_shoot_msg_board2_pc__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_interfaces/msg/detail/aim_shoot_msg_board2_pc__struct.h"
#include "my_interfaces/msg/detail/aim_shoot_msg_board2_pc__functions.h"
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


using _AimShootMsgBoard2PC__ros_msg_type = my_interfaces__msg__AimShootMsgBoard2PC;

static bool _AimShootMsgBoard2PC__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AimShootMsgBoard2PC__ros_msg_type * ros_message = static_cast<const _AimShootMsgBoard2PC__ros_msg_type *>(untyped_ros_message);
  // Field name: self_id
  {
    cdr << ros_message->self_id;
  }

  // Field name: yaw_angle
  {
    cdr << ros_message->yaw_angle;
  }

  // Field name: pitch_angle
  {
    cdr << ros_message->pitch_angle;
  }

  // Field name: yaw_speed
  {
    cdr << ros_message->yaw_speed;
  }

  // Field name: pitch_speed
  {
    cdr << ros_message->pitch_speed;
  }

  // Field name: yaw_offset
  {
    cdr << ros_message->yaw_offset;
  }

  // Field name: pitch_offset
  {
    cdr << ros_message->pitch_offset;
  }

  // Field name: dist
  {
    cdr << ros_message->dist;
  }

  // Field name: shoot_speed
  {
    cdr << ros_message->shoot_speed;
  }

  // Field name: shoot_delay
  {
    cdr << ros_message->shoot_delay;
  }

  // Field name: shoot_id_fdb
  {
    cdr << ros_message->shoot_id_fdb;
  }

  // Field name: is_big_energy
  {
    cdr << ros_message->is_big_energy;
  }

  // Field name: chassis_vx
  {
    cdr << ros_message->chassis_vx;
  }

  // Field name: chassis_vy
  {
    cdr << ros_message->chassis_vy;
  }

  return true;
}

static bool _AimShootMsgBoard2PC__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AimShootMsgBoard2PC__ros_msg_type * ros_message = static_cast<_AimShootMsgBoard2PC__ros_msg_type *>(untyped_ros_message);
  // Field name: self_id
  {
    cdr >> ros_message->self_id;
  }

  // Field name: yaw_angle
  {
    cdr >> ros_message->yaw_angle;
  }

  // Field name: pitch_angle
  {
    cdr >> ros_message->pitch_angle;
  }

  // Field name: yaw_speed
  {
    cdr >> ros_message->yaw_speed;
  }

  // Field name: pitch_speed
  {
    cdr >> ros_message->pitch_speed;
  }

  // Field name: yaw_offset
  {
    cdr >> ros_message->yaw_offset;
  }

  // Field name: pitch_offset
  {
    cdr >> ros_message->pitch_offset;
  }

  // Field name: dist
  {
    cdr >> ros_message->dist;
  }

  // Field name: shoot_speed
  {
    cdr >> ros_message->shoot_speed;
  }

  // Field name: shoot_delay
  {
    cdr >> ros_message->shoot_delay;
  }

  // Field name: shoot_id_fdb
  {
    cdr >> ros_message->shoot_id_fdb;
  }

  // Field name: is_big_energy
  {
    cdr >> ros_message->is_big_energy;
  }

  // Field name: chassis_vx
  {
    cdr >> ros_message->chassis_vx;
  }

  // Field name: chassis_vy
  {
    cdr >> ros_message->chassis_vy;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t get_serialized_size_my_interfaces__msg__AimShootMsgBoard2PC(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AimShootMsgBoard2PC__ros_msg_type * ros_message = static_cast<const _AimShootMsgBoard2PC__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name self_id
  {
    size_t item_size = sizeof(ros_message->self_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_angle
  {
    size_t item_size = sizeof(ros_message->yaw_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_angle
  {
    size_t item_size = sizeof(ros_message->pitch_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_speed
  {
    size_t item_size = sizeof(ros_message->yaw_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_speed
  {
    size_t item_size = sizeof(ros_message->pitch_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_offset
  {
    size_t item_size = sizeof(ros_message->yaw_offset);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_offset
  {
    size_t item_size = sizeof(ros_message->pitch_offset);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dist
  {
    size_t item_size = sizeof(ros_message->dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shoot_speed
  {
    size_t item_size = sizeof(ros_message->shoot_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shoot_delay
  {
    size_t item_size = sizeof(ros_message->shoot_delay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shoot_id_fdb
  {
    size_t item_size = sizeof(ros_message->shoot_id_fdb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_big_energy
  {
    size_t item_size = sizeof(ros_message->is_big_energy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name chassis_vx
  {
    size_t item_size = sizeof(ros_message->chassis_vx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name chassis_vy
  {
    size_t item_size = sizeof(ros_message->chassis_vy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AimShootMsgBoard2PC__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_interfaces__msg__AimShootMsgBoard2PC(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_interfaces
size_t max_serialized_size_my_interfaces__msg__AimShootMsgBoard2PC(
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

  // member: self_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: yaw_angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_offset
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_offset
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: dist
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: shoot_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: shoot_delay
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: shoot_id_fdb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: is_big_energy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: chassis_vx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: chassis_vy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_interfaces__msg__AimShootMsgBoard2PC;
    is_plain =
      (
      offsetof(DataType, chassis_vy) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AimShootMsgBoard2PC__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_interfaces__msg__AimShootMsgBoard2PC(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AimShootMsgBoard2PC = {
  "my_interfaces::msg",
  "AimShootMsgBoard2PC",
  _AimShootMsgBoard2PC__cdr_serialize,
  _AimShootMsgBoard2PC__cdr_deserialize,
  _AimShootMsgBoard2PC__get_serialized_size,
  _AimShootMsgBoard2PC__max_serialized_size
};

static rosidl_message_type_support_t _AimShootMsgBoard2PC__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AimShootMsgBoard2PC,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_interfaces, msg, AimShootMsgBoard2PC)() {
  return &_AimShootMsgBoard2PC__type_support;
}

#if defined(__cplusplus)
}
#endif
