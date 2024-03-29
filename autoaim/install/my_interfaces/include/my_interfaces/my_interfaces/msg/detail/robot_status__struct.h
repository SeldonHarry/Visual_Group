// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BLUE'.
enum
{
  my_interfaces__msg__RobotStatus__BLUE = 0
};

/// Constant 'RED'.
enum
{
  my_interfaces__msg__RobotStatus__RED = 1
};

/// Constant 'MANUAL'.
/**
  * ProgramMode
 */
enum
{
  my_interfaces__msg__RobotStatus__MANUAL = 0
};

/// Constant 'AUTOAIM'.
enum
{
  my_interfaces__msg__RobotStatus__AUTOAIM = 1
};

/// Constant 'ANTITOP'.
enum
{
  my_interfaces__msg__RobotStatus__ANTITOP = 2
};

/// Constant 'ENERGY_HIT'.
enum
{
  my_interfaces__msg__RobotStatus__ENERGY_HIT = 4
};

/// Constant 'ENERGY_DISTURB'.
enum
{
  my_interfaces__msg__RobotStatus__ENERGY_DISTURB = 5
};

/// Constant 'NOT_RECEIVED'.
enum
{
  my_interfaces__msg__RobotStatus__NOT_RECEIVED = 8
};

/// Struct defined in msg/RobotStatus in the package my_interfaces.
/**
  * EnemyColor
 */
typedef struct my_interfaces__msg__RobotStatus
{
  /// parameters
  float bullet_speed;
  /// offset 4
  float yaw_compensate;
  /// offset 8
  float pitch_compensate;
  uint8_t enemy_color;
  uint8_t is_big_energy;
  uint8_t program_mode;
  uint8_t latency_cmd_to_fire;
  int32_t last_shoot_aim_id;
  float laser_distance;
  /// lrc校验位
  uint8_t lrc;
} my_interfaces__msg__RobotStatus;

// Struct for a sequence of my_interfaces__msg__RobotStatus.
typedef struct my_interfaces__msg__RobotStatus__Sequence
{
  my_interfaces__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
