// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/aim_shoot_msg_board2_pc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_interfaces__msg__AimShootMsgBoard2PC__init(my_interfaces__msg__AimShootMsgBoard2PC * msg)
{
  if (!msg) {
    return false;
  }
  // self_id
  // yaw_angle
  // pitch_angle
  // yaw_speed
  // pitch_speed
  // yaw_offset
  // pitch_offset
  // dist
  // shoot_speed
  // shoot_delay
  // shoot_id_fdb
  // is_big_energy
  // chassis_vx
  // chassis_vy
  return true;
}

void
my_interfaces__msg__AimShootMsgBoard2PC__fini(my_interfaces__msg__AimShootMsgBoard2PC * msg)
{
  if (!msg) {
    return;
  }
  // self_id
  // yaw_angle
  // pitch_angle
  // yaw_speed
  // pitch_speed
  // yaw_offset
  // pitch_offset
  // dist
  // shoot_speed
  // shoot_delay
  // shoot_id_fdb
  // is_big_energy
  // chassis_vx
  // chassis_vy
}

bool
my_interfaces__msg__AimShootMsgBoard2PC__are_equal(const my_interfaces__msg__AimShootMsgBoard2PC * lhs, const my_interfaces__msg__AimShootMsgBoard2PC * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // self_id
  if (lhs->self_id != rhs->self_id) {
    return false;
  }
  // yaw_angle
  if (lhs->yaw_angle != rhs->yaw_angle) {
    return false;
  }
  // pitch_angle
  if (lhs->pitch_angle != rhs->pitch_angle) {
    return false;
  }
  // yaw_speed
  if (lhs->yaw_speed != rhs->yaw_speed) {
    return false;
  }
  // pitch_speed
  if (lhs->pitch_speed != rhs->pitch_speed) {
    return false;
  }
  // yaw_offset
  if (lhs->yaw_offset != rhs->yaw_offset) {
    return false;
  }
  // pitch_offset
  if (lhs->pitch_offset != rhs->pitch_offset) {
    return false;
  }
  // dist
  if (lhs->dist != rhs->dist) {
    return false;
  }
  // shoot_speed
  if (lhs->shoot_speed != rhs->shoot_speed) {
    return false;
  }
  // shoot_delay
  if (lhs->shoot_delay != rhs->shoot_delay) {
    return false;
  }
  // shoot_id_fdb
  if (lhs->shoot_id_fdb != rhs->shoot_id_fdb) {
    return false;
  }
  // is_big_energy
  if (lhs->is_big_energy != rhs->is_big_energy) {
    return false;
  }
  // chassis_vx
  if (lhs->chassis_vx != rhs->chassis_vx) {
    return false;
  }
  // chassis_vy
  if (lhs->chassis_vy != rhs->chassis_vy) {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__AimShootMsgBoard2PC__copy(
  const my_interfaces__msg__AimShootMsgBoard2PC * input,
  my_interfaces__msg__AimShootMsgBoard2PC * output)
{
  if (!input || !output) {
    return false;
  }
  // self_id
  output->self_id = input->self_id;
  // yaw_angle
  output->yaw_angle = input->yaw_angle;
  // pitch_angle
  output->pitch_angle = input->pitch_angle;
  // yaw_speed
  output->yaw_speed = input->yaw_speed;
  // pitch_speed
  output->pitch_speed = input->pitch_speed;
  // yaw_offset
  output->yaw_offset = input->yaw_offset;
  // pitch_offset
  output->pitch_offset = input->pitch_offset;
  // dist
  output->dist = input->dist;
  // shoot_speed
  output->shoot_speed = input->shoot_speed;
  // shoot_delay
  output->shoot_delay = input->shoot_delay;
  // shoot_id_fdb
  output->shoot_id_fdb = input->shoot_id_fdb;
  // is_big_energy
  output->is_big_energy = input->is_big_energy;
  // chassis_vx
  output->chassis_vx = input->chassis_vx;
  // chassis_vy
  output->chassis_vy = input->chassis_vy;
  return true;
}

my_interfaces__msg__AimShootMsgBoard2PC *
my_interfaces__msg__AimShootMsgBoard2PC__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__AimShootMsgBoard2PC * msg = (my_interfaces__msg__AimShootMsgBoard2PC *)allocator.allocate(sizeof(my_interfaces__msg__AimShootMsgBoard2PC), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__AimShootMsgBoard2PC));
  bool success = my_interfaces__msg__AimShootMsgBoard2PC__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__AimShootMsgBoard2PC__destroy(my_interfaces__msg__AimShootMsgBoard2PC * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__AimShootMsgBoard2PC__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__AimShootMsgBoard2PC__Sequence__init(my_interfaces__msg__AimShootMsgBoard2PC__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__AimShootMsgBoard2PC * data = NULL;

  if (size) {
    data = (my_interfaces__msg__AimShootMsgBoard2PC *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__AimShootMsgBoard2PC), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__AimShootMsgBoard2PC__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__AimShootMsgBoard2PC__fini(&data[i - 1]);
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
my_interfaces__msg__AimShootMsgBoard2PC__Sequence__fini(my_interfaces__msg__AimShootMsgBoard2PC__Sequence * array)
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
      my_interfaces__msg__AimShootMsgBoard2PC__fini(&array->data[i]);
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

my_interfaces__msg__AimShootMsgBoard2PC__Sequence *
my_interfaces__msg__AimShootMsgBoard2PC__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__AimShootMsgBoard2PC__Sequence * array = (my_interfaces__msg__AimShootMsgBoard2PC__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__AimShootMsgBoard2PC__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__AimShootMsgBoard2PC__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__AimShootMsgBoard2PC__Sequence__destroy(my_interfaces__msg__AimShootMsgBoard2PC__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__AimShootMsgBoard2PC__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__AimShootMsgBoard2PC__Sequence__are_equal(const my_interfaces__msg__AimShootMsgBoard2PC__Sequence * lhs, const my_interfaces__msg__AimShootMsgBoard2PC__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__AimShootMsgBoard2PC__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__AimShootMsgBoard2PC__Sequence__copy(
  const my_interfaces__msg__AimShootMsgBoard2PC__Sequence * input,
  my_interfaces__msg__AimShootMsgBoard2PC__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__AimShootMsgBoard2PC);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__AimShootMsgBoard2PC * data =
      (my_interfaces__msg__AimShootMsgBoard2PC *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__AimShootMsgBoard2PC__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__AimShootMsgBoard2PC__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__AimShootMsgBoard2PC__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
