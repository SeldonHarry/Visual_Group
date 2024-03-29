// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/NavigationPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__NAVIGATION_PC2_BOARD__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__NAVIGATION_PC2_BOARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NavigationPC2Board in the package my_interfaces.
/**
  * 导航数据包(视觉->电控) id-0x02
  * 底盘速度指令
 */
typedef struct my_interfaces__msg__NavigationPC2Board
{
  /// m/s,，底盘前后速度，前+后-
  float vx;
  /// m/s，底盘左右速度，左+右-
  float vy;
  /// dps，底盘旋转角速度，逆时针+顺时针-
  float wz;
} my_interfaces__msg__NavigationPC2Board;

// Struct for a sequence of my_interfaces__msg__NavigationPC2Board.
typedef struct my_interfaces__msg__NavigationPC2Board__Sequence
{
  my_interfaces__msg__NavigationPC2Board * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__NavigationPC2Board__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__NAVIGATION_PC2_BOARD__STRUCT_H_
