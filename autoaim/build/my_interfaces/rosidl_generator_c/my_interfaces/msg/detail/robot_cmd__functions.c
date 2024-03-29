// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/RobotCmd.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/robot_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_interfaces__msg__RobotCmd__init(my_interfaces__msg__RobotCmd * msg)
{
  if (!msg) {
    return false;
  }
  // start
  // seq_id
  // aim_id
  // car_id
  // detection_info
  // yaw
  // pitch
  // yaw_v
  // pithc_v
  // dist
  // shoot
  // period
  // lrc
  // lock_yaw
  // end
  return true;
}

void
my_interfaces__msg__RobotCmd__fini(my_interfaces__msg__RobotCmd * msg)
{
  if (!msg) {
    return;
  }
  // start
  // seq_id
  // aim_id
  // car_id
  // detection_info
  // yaw
  // pitch
  // yaw_v
  // pithc_v
  // dist
  // shoot
  // period
  // lrc
  // lock_yaw
  // end
}

bool
my_interfaces__msg__RobotCmd__are_equal(const my_interfaces__msg__RobotCmd * lhs, const my_interfaces__msg__RobotCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start
  if (lhs->start != rhs->start) {
    return false;
  }
  // seq_id
  if (lhs->seq_id != rhs->seq_id) {
    return false;
  }
  // aim_id
  if (lhs->aim_id != rhs->aim_id) {
    return false;
  }
  // car_id
  if (lhs->car_id != rhs->car_id) {
    return false;
  }
  // detection_info
  if (lhs->detection_info != rhs->detection_info) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw_v
  if (lhs->yaw_v != rhs->yaw_v) {
    return false;
  }
  // pithc_v
  if (lhs->pithc_v != rhs->pithc_v) {
    return false;
  }
  // dist
  if (lhs->dist != rhs->dist) {
    return false;
  }
  // shoot
  if (lhs->shoot != rhs->shoot) {
    return false;
  }
  // period
  if (lhs->period != rhs->period) {
    return false;
  }
  // lrc
  if (lhs->lrc != rhs->lrc) {
    return false;
  }
  // lock_yaw
  if (lhs->lock_yaw != rhs->lock_yaw) {
    return false;
  }
  // end
  if (lhs->end != rhs->end) {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__RobotCmd__copy(
  const my_interfaces__msg__RobotCmd * input,
  my_interfaces__msg__RobotCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // start
  output->start = input->start;
  // seq_id
  output->seq_id = input->seq_id;
  // aim_id
  output->aim_id = input->aim_id;
  // car_id
  output->car_id = input->car_id;
  // detection_info
  output->detection_info = input->detection_info;
  // yaw
  output->yaw = input->yaw;
  // pitch
  output->pitch = input->pitch;
  // yaw_v
  output->yaw_v = input->yaw_v;
  // pithc_v
  output->pithc_v = input->pithc_v;
  // dist
  output->dist = input->dist;
  // shoot
  output->shoot = input->shoot;
  // period
  output->period = input->period;
  // lrc
  output->lrc = input->lrc;
  // lock_yaw
  output->lock_yaw = input->lock_yaw;
  // end
  output->end = input->end;
  return true;
}

my_interfaces__msg__RobotCmd *
my_interfaces__msg__RobotCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__RobotCmd * msg = (my_interfaces__msg__RobotCmd *)allocator.allocate(sizeof(my_interfaces__msg__RobotCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__RobotCmd));
  bool success = my_interfaces__msg__RobotCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__RobotCmd__destroy(my_interfaces__msg__RobotCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__RobotCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__RobotCmd__Sequence__init(my_interfaces__msg__RobotCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__RobotCmd * data = NULL;

  if (size) {
    data = (my_interfaces__msg__RobotCmd *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__RobotCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__RobotCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__RobotCmd__fini(&data[i - 1]);
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
my_interfaces__msg__RobotCmd__Sequence__fini(my_interfaces__msg__RobotCmd__Sequence * array)
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
      my_interfaces__msg__RobotCmd__fini(&array->data[i]);
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

my_interfaces__msg__RobotCmd__Sequence *
my_interfaces__msg__RobotCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__RobotCmd__Sequence * array = (my_interfaces__msg__RobotCmd__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__RobotCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__RobotCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__RobotCmd__Sequence__destroy(my_interfaces__msg__RobotCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__RobotCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__RobotCmd__Sequence__are_equal(const my_interfaces__msg__RobotCmd__Sequence * lhs, const my_interfaces__msg__RobotCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__RobotCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__RobotCmd__Sequence__copy(
  const my_interfaces__msg__RobotCmd__Sequence * input,
  my_interfaces__msg__RobotCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__RobotCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__RobotCmd * data =
      (my_interfaces__msg__RobotCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__RobotCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__RobotCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__RobotCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
