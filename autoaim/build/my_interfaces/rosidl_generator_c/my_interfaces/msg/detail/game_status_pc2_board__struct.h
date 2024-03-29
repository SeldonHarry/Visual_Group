// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/GameStatusPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GameStatusPC2Board in the package my_interfaces.
/**
  * 比赛信息数据包(视觉->电控) id-0x03
 */
typedef struct my_interfaces__msg__GameStatusPC2Board
{
  /// ?
  uint8_t reserve;
} my_interfaces__msg__GameStatusPC2Board;

// Struct for a sequence of my_interfaces__msg__GameStatusPC2Board.
typedef struct my_interfaces__msg__GameStatusPC2Board__Sequence
{
  my_interfaces__msg__GameStatusPC2Board * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__GameStatusPC2Board__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__STRUCT_H_
