// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/detection_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `img`
#include "sensor_msgs/msg/detail/image__functions.h"
// Member `q`
#include "geometry_msgs/msg/detail/quaternion__functions.h"
// Member `armors`
#include "my_interfaces/msg/detail/detected_armor__functions.h"

bool
my_interfaces__msg__DetectionResult__init(my_interfaces__msg__DetectionResult * msg)
{
  if (!msg) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__init(&msg->img)) {
    my_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  // q
  if (!geometry_msgs__msg__Quaternion__init(&msg->q)) {
    my_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  // armors
  if (!my_interfaces__msg__DetectedArmor__Sequence__init(&msg->armors, 0)) {
    my_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  return true;
}

void
my_interfaces__msg__DetectionResult__fini(my_interfaces__msg__DetectionResult * msg)
{
  if (!msg) {
    return;
  }
  // img
  sensor_msgs__msg__Image__fini(&msg->img);
  // q
  geometry_msgs__msg__Quaternion__fini(&msg->q);
  // armors
  my_interfaces__msg__DetectedArmor__Sequence__fini(&msg->armors);
}

bool
my_interfaces__msg__DetectionResult__are_equal(const my_interfaces__msg__DetectionResult * lhs, const my_interfaces__msg__DetectionResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->img), &(rhs->img)))
  {
    return false;
  }
  // q
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->q), &(rhs->q)))
  {
    return false;
  }
  // armors
  if (!my_interfaces__msg__DetectedArmor__Sequence__are_equal(
      &(lhs->armors), &(rhs->armors)))
  {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__DetectionResult__copy(
  const my_interfaces__msg__DetectionResult * input,
  my_interfaces__msg__DetectionResult * output)
{
  if (!input || !output) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__copy(
      &(input->img), &(output->img)))
  {
    return false;
  }
  // q
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->q), &(output->q)))
  {
    return false;
  }
  // armors
  if (!my_interfaces__msg__DetectedArmor__Sequence__copy(
      &(input->armors), &(output->armors)))
  {
    return false;
  }
  return true;
}

my_interfaces__msg__DetectionResult *
my_interfaces__msg__DetectionResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__DetectionResult * msg = (my_interfaces__msg__DetectionResult *)allocator.allocate(sizeof(my_interfaces__msg__DetectionResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__DetectionResult));
  bool success = my_interfaces__msg__DetectionResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__DetectionResult__destroy(my_interfaces__msg__DetectionResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__DetectionResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__DetectionResult__Sequence__init(my_interfaces__msg__DetectionResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__DetectionResult * data = NULL;

  if (size) {
    data = (my_interfaces__msg__DetectionResult *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__DetectionResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__DetectionResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__DetectionResult__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_interfaces__msg__DetectionResult__Sequence__fini(my_interfaces__msg__DetectionResult__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_interfaces__msg__DetectionResult__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_interfaces__msg__DetectionResult__Sequence *
my_interfaces__msg__DetectionResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__DetectionResult__Sequence * array = (my_interfaces__msg__DetectionResult__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__DetectionResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__DetectionResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__DetectionResult__Sequence__destroy(my_interfaces__msg__DetectionResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__DetectionResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__DetectionResult__Sequence__are_equal(const my_interfaces__msg__DetectionResult__Sequence * lhs, const my_interfaces__msg__DetectionResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__DetectionResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__DetectionResult__Sequence__copy(
  const my_interfaces__msg__DetectionResult__Sequence * input,
  my_interfaces__msg__DetectionResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__DetectionResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__DetectionResult * data =
      (my_interfaces__msg__DetectionResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__DetectionResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__DetectionResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__DetectionResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
