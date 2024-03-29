// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'q'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'armors'
#include "my_interfaces/msg/detail/detected_armor__struct.h"

/// Struct defined in msg/DetectionResult in the package my_interfaces.
typedef struct my_interfaces__msg__DetectionResult
{
  sensor_msgs__msg__Image img;
  geometry_msgs__msg__Quaternion q;
  my_interfaces__msg__DetectedArmor__Sequence armors;
} my_interfaces__msg__DetectionResult;

// Struct for a sequence of my_interfaces__msg__DetectionResult.
typedef struct my_interfaces__msg__DetectionResult__Sequence
{
  my_interfaces__msg__DetectionResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__DetectionResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_
