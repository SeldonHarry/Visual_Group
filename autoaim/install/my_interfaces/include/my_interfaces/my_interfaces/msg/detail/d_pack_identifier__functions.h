// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_interfaces:msg/DPackIdentifier.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__FUNCTIONS_H_
#define MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "my_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "my_interfaces/msg/detail/d_pack_identifier__struct.h"

/// Initialize msg/DPackIdentifier message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_interfaces__msg__DPackIdentifier
 * )) before or use
 * my_interfaces__msg__DPackIdentifier__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__DPackIdentifier__init(my_interfaces__msg__DPackIdentifier * msg);

/// Finalize msg/DPackIdentifier message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__DPackIdentifier__fini(my_interfaces__msg__DPackIdentifier * msg);

/// Create msg/DPackIdentifier message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_interfaces__msg__DPackIdentifier__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
my_interfaces__msg__DPackIdentifier *
my_interfaces__msg__DPackIdentifier__create();

/// Destroy msg/DPackIdentifier message.
/**
 * It calls
 * my_interfaces__msg__DPackIdentifier__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__DPackIdentifier__destroy(my_interfaces__msg__DPackIdentifier * msg);

/// Check for msg/DPackIdentifier message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__DPackIdentifier__are_equal(const my_interfaces__msg__DPackIdentifier * lhs, const my_interfaces__msg__DPackIdentifier * rhs);

/// Copy a msg/DPackIdentifier message.
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
my_interfaces__msg__DPackIdentifier__copy(
  const my_interfaces__msg__DPackIdentifier * input,
  my_interfaces__msg__DPackIdentifier * output);

/// Initialize array of msg/DPackIdentifier messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_interfaces__msg__DPackIdentifier__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__DPackIdentifier__Sequence__init(my_interfaces__msg__DPackIdentifier__Sequence * array, size_t size);

/// Finalize array of msg/DPackIdentifier messages.
/**
 * It calls
 * my_interfaces__msg__DPackIdentifier__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__DPackIdentifier__Sequence__fini(my_interfaces__msg__DPackIdentifier__Sequence * array);

/// Create array of msg/DPackIdentifier messages.
/**
 * It allocates the memory for the array and calls
 * my_interfaces__msg__DPackIdentifier__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
my_interfaces__msg__DPackIdentifier__Sequence *
my_interfaces__msg__DPackIdentifier__Sequence__create(size_t size);

/// Destroy array of msg/DPackIdentifier messages.
/**
 * It calls
 * my_interfaces__msg__DPackIdentifier__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
void
my_interfaces__msg__DPackIdentifier__Sequence__destroy(my_interfaces__msg__DPackIdentifier__Sequence * array);

/// Check for msg/DPackIdentifier message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_interfaces
bool
my_interfaces__msg__DPackIdentifier__Sequence__are_equal(const my_interfaces__msg__DPackIdentifier__Sequence * lhs, const my_interfaces__msg__DPackIdentifier__Sequence * rhs);

/// Copy an array of msg/DPackIdentifier messages.
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
my_interfaces__msg__DPackIdentifier__Sequence__copy(
  const my_interfaces__msg__DPackIdentifier__Sequence * input,
  my_interfaces__msg__DPackIdentifier__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__FUNCTIONS_H_
