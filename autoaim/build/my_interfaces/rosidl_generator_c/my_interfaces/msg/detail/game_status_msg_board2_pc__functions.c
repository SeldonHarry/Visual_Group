// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/GameStatusMsgBoard2PC.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/game_status_msg_board2_pc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_interfaces__msg__GameStatusMsgBoard2PC__init(my_interfaces__msg__GameStatusMsgBoard2PC * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // remain_hp
  // max_hp
  // red_1_robot_hp
  // red_2_robot_hp
  // red_3_robot_hp
  // red_4_robot_hp
  // red_5_robot_hp
  // red_7_robot_hp
  // red_outpost_hp
  // red_base_hp
  // blue_1_robot_hp
  // blue_2_robot_hp
  // blue_3_robot_hp
  // blue_4_robot_hp
  // blue_5_robot_hp
  // blue_7_robot_hp
  // blue_outpost_hp
  // blue_base_hp
  return true;
}

void
my_interfaces__msg__GameStatusMsgBoard2PC__fini(my_interfaces__msg__GameStatusMsgBoard2PC * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // remain_hp
  // max_hp
  // red_1_robot_hp
  // red_2_robot_hp
  // red_3_robot_hp
  // red_4_robot_hp
  // red_5_robot_hp
  // red_7_robot_hp
  // red_outpost_hp
  // red_base_hp
  // blue_1_robot_hp
  // blue_2_robot_hp
  // blue_3_robot_hp
  // blue_4_robot_hp
  // blue_5_robot_hp
  // blue_7_robot_hp
  // blue_outpost_hp
  // blue_base_hp
}

bool
my_interfaces__msg__GameStatusMsgBoard2PC__are_equal(const my_interfaces__msg__GameStatusMsgBoard2PC * lhs, const my_interfaces__msg__GameStatusMsgBoard2PC * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // remain_hp
  if (lhs->remain_hp != rhs->remain_hp) {
    return false;
  }
  // max_hp
  if (lhs->max_hp != rhs->max_hp) {
    return false;
  }
  // red_1_robot_hp
  if (lhs->red_1_robot_hp != rhs->red_1_robot_hp) {
    return false;
  }
  // red_2_robot_hp
  if (lhs->red_2_robot_hp != rhs->red_2_robot_hp) {
    return false;
  }
  // red_3_robot_hp
  if (lhs->red_3_robot_hp != rhs->red_3_robot_hp) {
    return false;
  }
  // red_4_robot_hp
  if (lhs->red_4_robot_hp != rhs->red_4_robot_hp) {
    return false;
  }
  // red_5_robot_hp
  if (lhs->red_5_robot_hp != rhs->red_5_robot_hp) {
    return false;
  }
  // red_7_robot_hp
  if (lhs->red_7_robot_hp != rhs->red_7_robot_hp) {
    return false;
  }
  // red_outpost_hp
  if (lhs->red_outpost_hp != rhs->red_outpost_hp) {
    return false;
  }
  // red_base_hp
  if (lhs->red_base_hp != rhs->red_base_hp) {
    return false;
  }
  // blue_1_robot_hp
  if (lhs->blue_1_robot_hp != rhs->blue_1_robot_hp) {
    return false;
  }
  // blue_2_robot_hp
  if (lhs->blue_2_robot_hp != rhs->blue_2_robot_hp) {
    return false;
  }
  // blue_3_robot_hp
  if (lhs->blue_3_robot_hp != rhs->blue_3_robot_hp) {
    return false;
  }
  // blue_4_robot_hp
  if (lhs->blue_4_robot_hp != rhs->blue_4_robot_hp) {
    return false;
  }
  // blue_5_robot_hp
  if (lhs->blue_5_robot_hp != rhs->blue_5_robot_hp) {
    return false;
  }
  // blue_7_robot_hp
  if (lhs->blue_7_robot_hp != rhs->blue_7_robot_hp) {
    return false;
  }
  // blue_outpost_hp
  if (lhs->blue_outpost_hp != rhs->blue_outpost_hp) {
    return false;
  }
  // blue_base_hp
  if (lhs->blue_base_hp != rhs->blue_base_hp) {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__GameStatusMsgBoard2PC__copy(
  const my_interfaces__msg__GameStatusMsgBoard2PC * input,
  my_interfaces__msg__GameStatusMsgBoard2PC * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // remain_hp
  output->remain_hp = input->remain_hp;
  // max_hp
  output->max_hp = input->max_hp;
  // red_1_robot_hp
  output->red_1_robot_hp = input->red_1_robot_hp;
  // red_2_robot_hp
  output->red_2_robot_hp = input->red_2_robot_hp;
  // red_3_robot_hp
  output->red_3_robot_hp = input->red_3_robot_hp;
  // red_4_robot_hp
  output->red_4_robot_hp = input->red_4_robot_hp;
  // red_5_robot_hp
  output->red_5_robot_hp = input->red_5_robot_hp;
  // red_7_robot_hp
  output->red_7_robot_hp = input->red_7_robot_hp;
  // red_outpost_hp
  output->red_outpost_hp = input->red_outpost_hp;
  // red_base_hp
  output->red_base_hp = input->red_base_hp;
  // blue_1_robot_hp
  output->blue_1_robot_hp = input->blue_1_robot_hp;
  // blue_2_robot_hp
  output->blue_2_robot_hp = input->blue_2_robot_hp;
  // blue_3_robot_hp
  output->blue_3_robot_hp = input->blue_3_robot_hp;
  // blue_4_robot_hp
  output->blue_4_robot_hp = input->blue_4_robot_hp;
  // blue_5_robot_hp
  output->blue_5_robot_hp = input->blue_5_robot_hp;
  // blue_7_robot_hp
  output->blue_7_robot_hp = input->blue_7_robot_hp;
  // blue_outpost_hp
  output->blue_outpost_hp = input->blue_outpost_hp;
  // blue_base_hp
  output->blue_base_hp = input->blue_base_hp;
  return true;
}

my_interfaces__msg__GameStatusMsgBoard2PC *
my_interfaces__msg__GameStatusMsgBoard2PC__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__GameStatusMsgBoard2PC * msg = (my_interfaces__msg__GameStatusMsgBoard2PC *)allocator.allocate(sizeof(my_interfaces__msg__GameStatusMsgBoard2PC), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__GameStatusMsgBoard2PC));
  bool success = my_interfaces__msg__GameStatusMsgBoard2PC__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__GameStatusMsgBoard2PC__destroy(my_interfaces__msg__GameStatusMsgBoard2PC * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__GameStatusMsgBoard2PC__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__init(my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__GameStatusMsgBoard2PC * data = NULL;

  if (size) {
    data = (my_interfaces__msg__GameStatusMsgBoard2PC *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__GameStatusMsgBoard2PC), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__GameStatusMsgBoard2PC__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__GameStatusMsgBoard2PC__fini(&data[i - 1]);
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
my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__fini(my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * array)
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
      my_interfaces__msg__GameStatusMsgBoard2PC__fini(&array->data[i]);
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

my_interfaces__msg__GameStatusMsgBoard2PC__Sequence *
my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * array = (my_interfaces__msg__GameStatusMsgBoard2PC__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__GameStatusMsgBoard2PC__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__destroy(my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__are_equal(const my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * lhs, const my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__GameStatusMsgBoard2PC__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__GameStatusMsgBoard2PC__Sequence__copy(
  const my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * input,
  my_interfaces__msg__GameStatusMsgBoard2PC__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__GameStatusMsgBoard2PC);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__GameStatusMsgBoard2PC * data =
      (my_interfaces__msg__GameStatusMsgBoard2PC *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__GameStatusMsgBoard2PC__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__GameStatusMsgBoard2PC__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__GameStatusMsgBoard2PC__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
