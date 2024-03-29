// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/AimShootMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AimShootMsgPC2Board in the package my_interfaces.
/**
  * 自瞄数据包，视觉->电控，id=0x01
  * C++中float就是此处的float32
 */
typedef struct my_interfaces__msg__AimShootMsgPC2Board
{
  /// deg
  float yaw_angle;
  /// deg
  float pitch_angle;
  /// dps
  float yaw_speed;
  /// dps
  float pitch_speed;
  /// dps
  float dist;
  /// 发射标志
  uint8_t shoot_flag;
  /// 发射id
  uint8_t shoot_id;
  /// 敌方id
  uint8_t enemy_id;
} my_interfaces__msg__AimShootMsgPC2Board;

// Struct for a sequence of my_interfaces__msg__AimShootMsgPC2Board.
typedef struct my_interfaces__msg__AimShootMsgPC2Board__Sequence
{
  my_interfaces__msg__AimShootMsgPC2Board * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__AimShootMsgPC2Board__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__STRUCT_H_
