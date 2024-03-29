// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/RobotCmd.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TRACKING'.
enum
{
  my_interfaces__msg__RobotCmd__TRACKING = 0
};

/// Constant 'SHOOT_NOW'.
enum
{
  my_interfaces__msg__RobotCmd__SHOOT_NOW = 1
};

/// Constant 'IDLE'.
enum
{
  my_interfaces__msg__RobotCmd__IDLE = 2
};

/// Struct defined in msg/RobotCmd in the package my_interfaces.
/**
  * Shoot_Mode
 */
typedef struct my_interfaces__msg__RobotCmd
{
  /// start起始位，不要把数据放到起始位前面
  uint8_t start;
  /// 丢包率测试
  uint8_t seq_id;
  int32_t aim_id;
  uint16_t car_id;
  uint16_t detection_info;
  float yaw;
  float pitch;
  float yaw_v;
  float pithc_v;
  float dist;
  /// SHOOT_MODE
  uint8_t shoot;
  /// 2021反陀螺的延时发射要求
  uint16_t period;
  /// lrc校验位，不要把数据放在lrc位后面
  uint8_t lrc;
  bool lock_yaw;
  uint8_t end;
} my_interfaces__msg__RobotCmd;

// Struct for a sequence of my_interfaces__msg__RobotCmd.
typedef struct my_interfaces__msg__RobotCmd__Sequence
{
  my_interfaces__msg__RobotCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__RobotCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__STRUCT_H_
