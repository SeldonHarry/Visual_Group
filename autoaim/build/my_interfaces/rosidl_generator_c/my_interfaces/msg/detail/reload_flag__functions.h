// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_interfaces:msg/ReloadFlag.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__FUNCTIONS_H_
#define MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "my_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "my_interfaces/msg/detail/reload_flag__struct.h"

/// Initialize msg/ReloadFlag message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_interfaces__msg__ReloadFlag
 * )) before or use
 * my_interfaces__msg__ReloadFlag__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__ReloadFlag__init(my_interfaces__msg__ReloadFlag * msg);

/// Finalize msg/ReloadFlag message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__ReloadFlag__fini(my_interfaces__msg__ReloadFlag * msg);

/// Create msg/ReloadFlag message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_interfaces__msg__ReloadFlag__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
my_interfaces__msg__ReloadFlag *
my_interfaces__msg__ReloadFlag__create();

/// Destroy msg/ReloadFlag message.
/**
 * It calls
 * my_interfaces__msg__ReloadFlag__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__ReloadFlag__destroy(my_interfaces__msg__ReloadFlag * msg);

/// Check for msg/ReloadFlag message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__ReloadFlag__are_equal(const my_interfaces__msg__ReloadFlag * lhs, const my_interfaces__msg__ReloadFlag * rhs);

/// Copy a msg/ReloadFlag message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__ReloadFlag__copy(
  const my_interfaces__msg__ReloadFlag * input,
  my_interfaces__msg__ReloadFlag * output);

/// Initialize array of msg/ReloadFlag messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_interfaces__msg__ReloadFlag__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__ReloadFlag__Sequence__init(my_interfaces__msg__ReloadFlag__Sequence * array, size_t size);

/// Finalize array of msg/ReloadFlag messages.
/**
 * It calls
 * my_interfaces__msg__ReloadFlag__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__ReloadFlag__Sequence__fini(my_interfaces__msg__ReloadFlag__Sequence * array);

/// Create array of msg/ReloadFlag messages.
/**
 * It allocates the memory for the array and calls
 * my_interfaces__msg__ReloadFlag__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
my_interfaces__msg__ReloadFlag__Sequence *
my_interfaces__msg__ReloadFlag__Sequence__create(size_t size);

/// Destroy array of msg/ReloadFlag messages.
/**
 * It calls
 * my_interfaces__msg__ReloadFlag__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__ReloadFlag__Sequence__destroy(my_interfaces__msg__ReloadFlag__Sequence * array);

/// Check for msg/ReloadFlag message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__ReloadFlag__Sequence__are_equal(const my_interfaces__msg__ReloadFlag__Sequence * lhs, const my_interfaces__msg__ReloadFlag__Sequence * rhs);

/// Copy an array of msg/ReloadFlag messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__ReloadFlag__Sequence__copy(
  const my_interfaces__msg__ReloadFlag__Sequence * input,
  my_interfaces__msg__ReloadFlag__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__FUNCTIONS_H_
