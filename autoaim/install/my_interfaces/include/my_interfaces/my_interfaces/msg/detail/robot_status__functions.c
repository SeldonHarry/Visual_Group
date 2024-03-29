// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_interfaces__msg__RobotStatus__init(my_interfaces__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // bullet_speed
  // yaw_compensate
  // pitch_compensate
  // enemy_color
  // is_big_energy
  // program_mode
  // latency_cmd_to_fire
  // last_shoot_aim_id
  // laser_distance
  // lrc
  return true;
}

void
my_interfaces__msg__RobotStatus__fini(my_interfaces__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // bullet_speed
  // yaw_compensate
  // pitch_compensate
  // enemy_color
  // is_big_energy
  // program_mode
  // latency_cmd_to_fire
  // last_shoot_aim_id
  // laser_distance
  // lrc
}

bool
my_interfaces__msg__RobotStatus__are_equal(const my_interfaces__msg__RobotStatus * lhs, const my_interfaces__msg__RobotStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // bullet_speed
  if (lhs->bullet_speed != rhs->bullet_speed) {
    return false;
  }
  // yaw_compensate
  if (lhs->yaw_compensate != rhs->yaw_compensate) {
    return false;
  }
  // pitch_compensate
  if (lhs->pitch_compensate != rhs->pitch_compensate) {
    return false;
  }
  // enemy_color
  if (lhs->enemy_color != rhs->enemy_color) {
    return false;
  }
  // is_big_energy
  if (lhs->is_big_energy != rhs->is_big_energy) {
    return false;
  }
  // program_mode
  if (lhs->program_mode != rhs->program_mode) {
    return false;
  }
  // latency_cmd_to_fire
  if (lhs->latency_cmd_to_fire != rhs->latency_cmd_to_fire) {
    return false;
  }
  // last_shoot_aim_id
  if (lhs->last_shoot_aim_id != rhs->last_shoot_aim_id) {
    return false;
  }
  // laser_distance
  if (lhs->laser_distance != rhs->laser_distance) {
    return false;
  }
  // lrc
  if (lhs->lrc != rhs->lrc) {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__RobotStatus__copy(
  const my_interfaces__msg__RobotStatus * input,
  my_interfaces__msg__RobotStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // bullet_speed
  output->bullet_speed = input->bullet_speed;
  // yaw_compensate
  output->yaw_compensate = input->yaw_compensate;
  // pitch_compensate
  output->pitch_compensate = input->pitch_compensate;
  // enemy_color
  output->enemy_color = input->enemy_color;
  // is_big_energy
  output->is_big_energy = input->is_big_energy;
  // program_mode
  output->program_mode = input->program_mode;
  // latency_cmd_to_fire
  output->latency_cmd_to_fire = input->latency_cmd_to_fire;
  // last_shoot_aim_id
  output->last_shoot_aim_id = input->last_shoot_aim_id;
  // laser_distance
  output->laser_distance = input->laser_distance;
  // lrc
  output->lrc = input->lrc;
  return true;
}

my_interfaces__msg__RobotStatus *
my_interfaces__msg__RobotStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__RobotStatus * msg = (my_interfaces__msg__RobotStatus *)allocator.allocate(sizeof(my_interfaces__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__RobotStatus));
  bool success = my_interfaces__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__RobotStatus__destroy(my_interfaces__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__RobotStatus__Sequence__init(my_interfaces__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__RobotStatus * data = NULL;

  if (size) {
    data = (my_interfaces__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__RobotStatus__fini(&data[i - 1]);
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
my_interfaces__msg__RobotStatus__Sequence__fini(my_interfaces__msg__RobotStatus__Sequence * array)
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
      my_interfaces__msg__RobotStatus__fini(&array->data[i]);
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

my_interfaces__msg__RobotStatus__Sequence *
my_interfaces__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__RobotStatus__Sequence * array = (my_interfaces__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__RobotStatus__Sequence__destroy(my_interfaces__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__RobotStatus__Sequence__are_equal(const my_interfaces__msg__RobotStatus__Sequence * lhs, const my_interfaces__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__RobotStatus__Sequence__copy(
  const my_interfaces__msg__RobotStatus__Sequence * input,
  my_interfaces__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__RobotStatus * data =
      (my_interfaces__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
