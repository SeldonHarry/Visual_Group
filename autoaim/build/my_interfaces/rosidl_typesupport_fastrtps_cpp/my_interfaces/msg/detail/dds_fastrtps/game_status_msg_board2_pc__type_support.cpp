// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from my_interfaces:msg/GameStatusMsgBoard2PC.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/game_status_msg_board2_pc__rosidl_typesupport_fastrtps_cpp.hpp"
#include "my_interfaces/msg/detail/game_status_msg_board2_pc__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace my_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_interfaces
cdr_serialize(
  const my_interfaces::msg::GameStatusMsgBoard2PC & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_id
  cdr << ros_message.robot_id;
  // Member: remain_hp
  cdr << ros_message.remain_hp;
  // Member: max_hp
  cdr << ros_message.max_hp;
  // Member: red_1_robot_hp
  cdr << ros_message.red_1_robot_hp;
  // Member: red_2_robot_hp
  cdr << ros_message.red_2_robot_hp;
  // Member: red_3_robot_hp
  cdr << ros_message.red_3_robot_hp;
  // Member: red_4_robot_hp
  cdr << ros_message.red_4_robot_hp;
  // Member: red_5_robot_hp
  cdr << ros_message.red_5_robot_hp;
  // Member: red_7_robot_hp
  cdr << ros_message.red_7_robot_hp;
  // Member: red_outpost_hp
  cdr << ros_message.red_outpost_hp;
  // Member: red_base_hp
  cdr << ros_message.red_base_hp;
  // Member: blue_1_robot_hp
  cdr << ros_message.blue_1_robot_hp;
  // Member: blue_2_robot_hp
  cdr << ros_message.blue_2_robot_hp;
  // Member: blue_3_robot_hp
  cdr << ros_message.blue_3_robot_hp;
  // Member: blue_4_robot_hp
  cdr << ros_message.blue_4_robot_hp;
  // Member: blue_5_robot_hp
  cdr << ros_message.blue_5_robot_hp;
  // Member: blue_7_robot_hp
  cdr << ros_message.blue_7_robot_hp;
  // Member: blue_outpost_hp
  cdr << ros_message.blue_outpost_hp;
  // Member: blue_base_hp
  cdr << ros_message.blue_base_hp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_interfaces::msg::GameStatusMsgBoard2PC & ros_message)
{
  // Member: robot_id
  cdr >> ros_message.robot_id;

  // Member: remain_hp
  cdr >> ros_message.remain_hp;

  // Member: max_hp
  cdr >> ros_message.max_hp;

  // Member: red_1_robot_hp
  cdr >> ros_message.red_1_robot_hp;

  // Member: red_2_robot_hp
  cdr >> ros_message.red_2_robot_hp;

  // Member: red_3_robot_hp
  cdr >> ros_message.red_3_robot_hp;

  // Member: red_4_robot_hp
  cdr >> ros_message.red_4_robot_hp;

  // Member: red_5_robot_hp
  cdr >> ros_message.red_5_robot_hp;

  // Member: red_7_robot_hp
  cdr >> ros_message.red_7_robot_hp;

  // Member: red_outpost_hp
  cdr >> ros_message.red_outpost_hp;

  // Member: red_base_hp
  cdr >> ros_message.red_base_hp;

  // Member: blue_1_robot_hp
  cdr >> ros_message.blue_1_robot_hp;

  // Member: blue_2_robot_hp
  cdr >> ros_message.blue_2_robot_hp;

  // Member: blue_3_robot_hp
  cdr >> ros_message.blue_3_robot_hp;

  // Member: blue_4_robot_hp
  cdr >> ros_message.blue_4_robot_hp;

  // Member: blue_5_robot_hp
  cdr >> ros_message.blue_5_robot_hp;

  // Member: blue_7_robot_hp
  cdr >> ros_message.blue_7_robot_hp;

  // Member: blue_outpost_hp
  cdr >> ros_message.blue_outpost_hp;

  // Member: blue_base_hp
  cdr >> ros_message.blue_base_hp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_interfaces
get_serialized_size(
  const my_interfaces::msg::GameStatusMsgBoard2PC & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_id
  {
    size_t item_size = sizeof(ros_message.robot_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: remain_hp
  {
    size_t item_size = sizeof(ros_message.remain_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_hp
  {
    size_t item_size = sizeof(ros_message.max_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_5_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.red_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_outpost_hp
  {
    size_t item_size = sizeof(ros_message.red_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_base_hp
  {
    size_t item_size = sizeof(ros_message.red_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_1_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_1_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_2_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_2_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_3_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_3_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_4_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_4_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_5_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_5_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_7_robot_hp
  {
    size_t item_size = sizeof(ros_message.blue_7_robot_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_outpost_hp
  {
    size_t item_size = sizeof(ros_message.blue_outpost_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: blue_base_hp
  {
    size_t item_size = sizeof(ros_message.blue_base_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_interfaces
max_serialized_size_GameStatusMsgBoard2PC(
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


  // Member: robot_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: remain_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: max_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: red_1_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_2_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_3_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_4_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_5_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_7_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_outpost_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: red_base_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_1_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_2_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_3_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_4_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_5_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_7_robot_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_outpost_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: blue_base_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_interfaces::msg::GameStatusMsgBoard2PC;
    is_plain =
      (
      offsetof(DataType, blue_base_hp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GameStatusMsgBoard2PC__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const my_interfaces::msg::GameStatusMsgBoard2PC *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GameStatusMsgBoard2PC__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<my_interfaces::msg::GameStatusMsgBoard2PC *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GameStatusMsgBoard2PC__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const my_interfaces::msg::GameStatusMsgBoard2PC *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GameStatusMsgBoard2PC__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GameStatusMsgBoard2PC(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GameStatusMsgBoard2PC__callbacks = {
  "my_interfaces::msg",
  "GameStatusMsgBoard2PC",
  _GameStatusMsgBoard2PC__cdr_serialize,
  _GameStatusMsgBoard2PC__cdr_deserialize,
  _GameStatusMsgBoard2PC__get_serialized_size,
  _GameStatusMsgBoard2PC__max_serialized_size
};

static rosidl_message_type_support_t _GameStatusMsgBoard2PC__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GameStatusMsgBoard2PC__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_my_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<my_interfaces::msg::GameStatusMsgBoard2PC>()
{
  return &my_interfaces::msg::typesupport_fastrtps_cpp::_GameStatusMsgBoard2PC__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_interfaces, msg, GameStatusMsgBoard2PC)() {
  return &my_interfaces::msg::typesupport_fastrtps_cpp::_GameStatusMsgBoard2PC__handle;
}

#ifdef __cplusplus
}
#endif
