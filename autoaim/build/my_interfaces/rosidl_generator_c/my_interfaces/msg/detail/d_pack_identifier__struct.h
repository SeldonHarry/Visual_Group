// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/DPackIdentifier.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MIMIPC_COMM_MAX_SIZE'.
enum
{
  my_interfaces__msg__DPackIdentifier__MIMIPC_COMM_MAX_SIZE = 64
};

/// Constant 'MINIPC_COMM_SOF'.
enum
{
  my_interfaces__msg__DPackIdentifier__MINIPC_COMM_SOF = 35
};

/// Constant 'PC2BOARD'.
/**
  * DATA TRANSMIT DIRECTION
 */
enum
{
  my_interfaces__msg__DPackIdentifier__PC2BOARD = 0
};

/// Constant 'BOARD2PC'.
enum
{
  my_interfaces__msg__DPackIdentifier__BOARD2PC = 16
};

/// Constant 'GENERAL'.
/**
  * DATA PACK IDENTIFIER
 */
enum
{
  my_interfaces__msg__DPackIdentifier__GENERAL = 0
};

/// Constant 'AIM_SHOOT'.
enum
{
  my_interfaces__msg__DPackIdentifier__AIM_SHOOT = 1
};

/// Constant 'NAVIGATION'.
enum
{
  my_interfaces__msg__DPackIdentifier__NAVIGATION = 2
};

/// Constant 'GAME_STATUS'.
enum
{
  my_interfaces__msg__DPackIdentifier__GAME_STATUS = 3
};

/// Struct defined in msg/DPackIdentifier in the package my_interfaces.
/**
  * Common Header for Frame Identity
 */
typedef struct my_interfaces__msg__DPackIdentifier
{
  uint8_t frame_id;
} my_interfaces__msg__DPackIdentifier;

// Struct for a sequence of my_interfaces__msg__DPackIdentifier.
typedef struct my_interfaces__msg__DPackIdentifier__Sequence
{
  my_interfaces__msg__DPackIdentifier * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__DPackIdentifier__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__STRUCT_H_
