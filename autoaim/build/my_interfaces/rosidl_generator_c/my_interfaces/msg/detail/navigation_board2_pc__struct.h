// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/NavigationBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__NAVIGATION_BOARD2_PC__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__NAVIGATION_BOARD2_PC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NavigationBoard2PC in the package my_interfaces.
/**
  * 导航数据包(电控->视觉) id-0x12
  * 里程计(世界坐标系)
 */
typedef struct my_interfaces__msg__NavigationBoard2PC
{
  /// m
  float x;
  /// m
  float y;
  /// deg
  float theta;
} my_interfaces__msg__NavigationBoard2PC;

// Struct for a sequence of my_interfaces__msg__NavigationBoard2PC.
typedef struct my_interfaces__msg__NavigationBoard2PC__Sequence
{
  my_interfaces__msg__NavigationBoard2PC * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__NavigationBoard2PC__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__NAVIGATION_BOARD2_PC__STRUCT_H_
