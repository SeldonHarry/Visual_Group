// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/GeneralMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GeneralMsgBoard2PC in the package my_interfaces.
/**
  * 视觉工作模式，电控->视觉, id=0x10
 */
typedef struct my_interfaces__msg__GeneralMsgBoard2PC
{
  uint8_t mode;
} my_interfaces__msg__GeneralMsgBoard2PC;

// Struct for a sequence of my_interfaces__msg__GeneralMsgBoard2PC.
typedef struct my_interfaces__msg__GeneralMsgBoard2PC__Sequence
{
  my_interfaces__msg__GeneralMsgBoard2PC * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__GeneralMsgBoard2PC__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__STRUCT_H_
