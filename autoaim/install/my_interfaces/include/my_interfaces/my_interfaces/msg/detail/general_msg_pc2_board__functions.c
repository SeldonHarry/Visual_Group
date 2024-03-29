// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/GeneralMsgPC2Board.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/general_msg_pc2_board__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_interfaces__msg__GeneralMsgPC2Board__init(my_interfaces__msg__GeneralMsgPC2Board * msg)
{
  if (!msg) {
    return false;
  }
  // mode_fdb
  return true;
}

void
my_interfaces__msg__GeneralMsgPC2Board__fini(my_interfaces__msg__GeneralMsgPC2Board * msg)
{
  if (!msg) {
    return;
  }
  // mode_fdb
}

bool
my_interfaces__msg__GeneralMsgPC2Board__are_equal(const my_interfaces__msg__GeneralMsgPC2Board * lhs, const my_interfaces__msg__GeneralMsgPC2Board * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode_fdb
  if (lhs->mode_fdb != rhs->mode_fdb) {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__GeneralMsgPC2Board__copy(
  const my_interfaces__msg__GeneralMsgPC2Board * input,
  my_interfaces__msg__GeneralMsgPC2Board * output)
{
  if (!input || !output) {
    return false;
  }
  // mode_fdb
  output->mode_fdb = input->mode_fdb;
  return true;
}

my_interfaces__msg__GeneralMsgPC2Board *
my_interfaces__msg__GeneralMsgPC2Board__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__GeneralMsgPC2Board * msg = (my_interfaces__msg__GeneralMsgPC2Board *)allocator.allocate(sizeof(my_interfaces__msg__GeneralMsgPC2Board), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__GeneralMsgPC2Board));
  bool success = my_interfaces__msg__GeneralMsgPC2Board__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__GeneralMsgPC2Board__destroy(my_interfaces__msg__GeneralMsgPC2Board * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__GeneralMsgPC2Board__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__GeneralMsgPC2Board__Sequence__init(my_interfaces__msg__GeneralMsgPC2Board__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__GeneralMsgPC2Board * data = NULL;

  if (size) {
    data = (my_interfaces__msg__GeneralMsgPC2Board *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__GeneralMsgPC2Board), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__GeneralMsgPC2Board__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__GeneralMsgPC2Board__fini(&data[i - 1]);
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
my_interfaces__msg__GeneralMsgPC2Board__Sequence__fini(my_interfaces__msg__GeneralMsgPC2Board__Sequence * array)
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
      my_interfaces__msg__GeneralMsgPC2Board__fini(&array->data[i]);
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

my_interfaces__msg__GeneralMsgPC2Board__Sequence *
my_interfaces__msg__GeneralMsgPC2Board__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__GeneralMsgPC2Board__Sequence * array = (my_interfaces__msg__GeneralMsgPC2Board__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__GeneralMsgPC2Board__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__GeneralMsgPC2Board__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__GeneralMsgPC2Board__Sequence__destroy(my_interfaces__msg__GeneralMsgPC2Board__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__GeneralMsgPC2Board__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__GeneralMsgPC2Board__Sequence__are_equal(const my_interfaces__msg__GeneralMsgPC2Board__Sequence * lhs, const my_interfaces__msg__GeneralMsgPC2Board__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__GeneralMsgPC2Board__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__GeneralMsgPC2Board__Sequence__copy(
  const my_interfaces__msg__GeneralMsgPC2Board__Sequence * input,
  my_interfaces__msg__GeneralMsgPC2Board__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__GeneralMsgPC2Board);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__GeneralMsgPC2Board * data =
      (my_interfaces__msg__GeneralMsgPC2Board *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__GeneralMsgPC2Board__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__GeneralMsgPC2Board__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__GeneralMsgPC2Board__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
