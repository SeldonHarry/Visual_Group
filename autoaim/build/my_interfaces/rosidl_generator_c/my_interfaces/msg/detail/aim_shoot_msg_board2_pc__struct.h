// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AimShootMsgBoard2PC in the package my_interfaces.
/**
  * 自瞄数据包(电控->视觉) id-0x11
  * yaw左+右-，pitch下+上-(ZYX欧拉角，右手定则)
 */
typedef struct my_interfaces__msg__AimShootMsgBoard2PC
{
  /// 用于判断红蓝方
  uint8_t self_id;
  /// deg
  float yaw_angle;
  /// deg
  float pitch_angle;
  /// dps
  float yaw_speed;
  /// dps
  float pitch_speed;
  /// deg，电控yaw补偿
  float yaw_offset;
  /// deg，电控pitch补偿
  float pitch_offset;
  /// m,电控测量距离
  float dist;
  /// m/s，射速
  float shoot_speed;
  /// ms，发射延时
  uint8_t shoot_delay;
  /// 发射id反馈(=对应的shoot_id)
  uint32_t shoot_id_fdb;
  /// 0-小符，1-大符
  uint8_t is_big_energy;
  /// m/s，底盘前后速度，前+后-，用于预测和发射判断
  float chassis_vx;
  /// m/s，底盘前后速度，前+后-，用于预测和发射判断
  float chassis_vy;
} my_interfaces__msg__AimShootMsgBoard2PC;

// Struct for a sequence of my_interfaces__msg__AimShootMsgBoard2PC.
typedef struct my_interfaces__msg__AimShootMsgBoard2PC__Sequence
{
  my_interfaces__msg__AimShootMsgBoard2PC * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__AimShootMsgBoard2PC__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__STRUCT_H_
