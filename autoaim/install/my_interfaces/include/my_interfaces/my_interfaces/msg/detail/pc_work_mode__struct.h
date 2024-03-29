// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/PCWorkMode.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'IDLE'.
enum
{
  my_interfaces__msg__PCWorkMode__IDLE = 0
};

/// Constant 'AUTOAIM'.
enum
{
  my_interfaces__msg__PCWorkMode__AUTOAIM = 1
};

/// Constant 'ENERGY'.
enum
{
  my_interfaces__msg__PCWorkMode__ENERGY = 2
};

/// Constant 'ENERGY_DISTURB'.
enum
{
  my_interfaces__msg__PCWorkMode__ENERGY_DISTURB = 3
};

/// Constant 'NAVIGATION'.
enum
{
  my_interfaces__msg__PCWorkMode__NAVIGATION = 4
};

/// Constant 'DECISION'.
enum
{
  my_interfaces__msg__PCWorkMode__DECISION = 5
};

/// Struct defined in msg/PCWorkMode in the package my_interfaces.
/**
  * MINIPC WORK MODE
 */
typedef struct my_interfaces__msg__PCWorkMode
{
  uint8_t mode;
} my_interfaces__msg__PCWorkMode;

// Struct for a sequence of my_interfaces__msg__PCWorkMode.
typedef struct my_interfaces__msg__PCWorkMode__Sequence
{
  my_interfaces__msg__PCWorkMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__PCWorkMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__STRUCT_H_
