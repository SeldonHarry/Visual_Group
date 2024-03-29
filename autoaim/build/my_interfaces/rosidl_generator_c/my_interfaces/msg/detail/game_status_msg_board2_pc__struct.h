// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/GameStatusMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GAME_STATUS_MSG_BOARD2_PC__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__GAME_STATUS_MSG_BOARD2_PC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GameStatusMsgBoard2PC in the package my_interfaces.
/**
  * 比赛信息数据包(电控->视觉) id-0x13
 */
typedef struct my_interfaces__msg__GameStatusMsgBoard2PC
{
  uint8_t robot_id;
  uint8_t remain_hp;
  uint8_t max_hp;
  /// 全体机器人血量
  uint16_t red_1_robot_hp;
  uint16_t red_2_robot_hp;
  uint16_t red_3_robot_hp;
  uint16_t red_4_robot_hp;
  uint16_t red_5_robot_hp;
  uint16_t red_7_robot_hp;
  uint16_t red_outpost_hp;
  uint16_t red_base_hp;
  uint16_t blue_1_robot_hp;
  uint16_t blue_2_robot_hp;
  uint16_t blue_3_robot_hp;
  uint16_t blue_4_robot_hp;
  uint16_t blue_5_robot_hp;
  uint16_t blue_7_robot_hp;
  uint16_t blue_outpost_hp;
  uint16_t blue_base_hp;
} my_interfaces__msg__GameStatusMsgBoard2PC;

// Struct for a sequence of my_interfaces__msg__GameStatusMsgBoard2PC.
typedef struct my_interfaces__msg__GameStatusMsgBoard2PC__Sequence
{
  my_interfaces__msg__GameStatusMsgBoard2PC * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__GameStatusMsgBoard2PC__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__GAME_STATUS_MSG_BOARD2_PC__STRUCT_H_
