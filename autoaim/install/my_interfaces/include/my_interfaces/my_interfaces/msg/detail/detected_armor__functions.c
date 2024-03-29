// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/DetectedArmor.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/detected_armor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pts`
#include "geometry_msgs/msg/detail/point32__functions.h"

bool
my_interfaces__msg__DetectedArmor__init(my_interfaces__msg__DetectedArmor * msg)
{
  if (!msg) {
    return false;
  }
  // pts
  for (size_t i = 0; i < 4; ++i) {
    if (!geometry_msgs__msg__Point32__init(&msg->pts[i])) {
      my_interfaces__msg__DetectedArmor__fini(msg);
      return false;
    }
  }
  // color
  // number
  // conf
  // conf_class
  return true;
}

void
my_interfaces__msg__DetectedArmor__fini(my_interfaces__msg__DetectedArmor * msg)
{
  if (!msg) {
    return;
  }
  // pts
  for (size_t i = 0; i < 4; ++i) {
    geometry_msgs__msg__Point32__fini(&msg->pts[i]);
  }
  // color
  // number
  // conf
  // conf_class
}

bool
my_interfaces__msg__DetectedArmor__are_equal(const my_interfaces__msg__DetectedArmor * lhs, const my_interfaces__msg__DetectedArmor * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pts
  for (size_t i = 0; i < 4; ++i) {
    if (!geometry_msgs__msg__Point32__are_equal(
        &(lhs->pts[i]), &(rhs->pts[i])))
    {
      return false;
    }
  }
  // color
  if (lhs->color != rhs->color) {
    return false;
  }
  // number
  if (lhs->number != rhs->number) {
    return false;
  }
  // conf
  if (lhs->conf != rhs->conf) {
    return false;
  }
  // conf_class
  if (lhs->conf_class != rhs->conf_class) {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__DetectedArmor__copy(
  const my_interfaces__msg__DetectedArmor * input,
  my_interfaces__msg__DetectedArmor * output)
{
  if (!input || !output) {
    return false;
  }
  // pts
  for (size_t i = 0; i < 4; ++i) {
    if (!geometry_msgs__msg__Point32__copy(
        &(input->pts[i]), &(output->pts[i])))
    {
      return false;
    }
  }
  // color
  output->color = input->color;
  // number
  output->number = input->number;
  // conf
  output->conf = input->conf;
  // conf_class
  output->conf_class = input->conf_class;
  return true;
}

my_interfaces__msg__DetectedArmor *
my_interfaces__msg__DetectedArmor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__DetectedArmor * msg = (my_interfaces__msg__DetectedArmor *)allocator.allocate(sizeof(my_interfaces__msg__DetectedArmor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__DetectedArmor));
  bool success = my_interfaces__msg__DetectedArmor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__DetectedArmor__destroy(my_interfaces__msg__DetectedArmor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__DetectedArmor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__DetectedArmor__Sequence__init(my_interfaces__msg__DetectedArmor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__DetectedArmor * data = NULL;

  if (size) {
    data = (my_interfaces__msg__DetectedArmor *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__DetectedArmor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__DetectedArmor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__DetectedArmor__fini(&data[i - 1]);
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
my_interfaces__msg__DetectedArmor__Sequence__fini(my_interfaces__msg__DetectedArmor__Sequence * array)
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
      my_interfaces__msg__DetectedArmor__fini(&array->data[i]);
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

my_interfaces__msg__DetectedArmor__Sequence *
my_interfaces__msg__DetectedArmor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__DetectedArmor__Sequence * array = (my_interfaces__msg__DetectedArmor__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__DetectedArmor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__DetectedArmor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__DetectedArmor__Sequence__destroy(my_interfaces__msg__DetectedArmor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__DetectedArmor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__DetectedArmor__Sequence__are_equal(const my_interfaces__msg__DetectedArmor__Sequence * lhs, const my_interfaces__msg__DetectedArmor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__DetectedArmor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__DetectedArmor__Sequence__copy(
  const my_interfaces__msg__DetectedArmor__Sequence * input,
  my_interfaces__msg__DetectedArmor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__DetectedArmor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__DetectedArmor * data =
      (my_interfaces__msg__DetectedArmor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__DetectedArmor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__DetectedArmor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__DetectedArmor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
