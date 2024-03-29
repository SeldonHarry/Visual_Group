// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/DetectedArmor.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pts'
#include "geometry_msgs/msg/detail/point32__struct.h"

/// Struct defined in msg/DetectedArmor in the package my_interfaces.
typedef struct my_interfaces__msg__DetectedArmor
{
  geometry_msgs__msg__Point32 pts[4];
  int32_t color;
  int32_t number;
  float conf;
  float conf_class;
} my_interfaces__msg__DetectedArmor;

// Struct for a sequence of my_interfaces__msg__DetectedArmor.
typedef struct my_interfaces__msg__DetectedArmor__Sequence
{
  my_interfaces__msg__DetectedArmor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__DetectedArmor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__STRUCT_H_
