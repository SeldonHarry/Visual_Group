// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from my_interfaces:msg/GameStatusPC2Board.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "my_interfaces/msg/detail/game_status_pc2_board__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace my_interfaces
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _GameStatusPC2Board_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GameStatusPC2Board_type_support_ids_t;

static const _GameStatusPC2Board_type_support_ids_t _GameStatusPC2Board_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GameStatusPC2Board_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GameStatusPC2Board_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GameStatusPC2Board_type_support_symbol_names_t _GameStatusPC2Board_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_interfaces, msg, GameStatusPC2Board)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_interfaces, msg, GameStatusPC2Board)),
  }
};

typedef struct _GameStatusPC2Board_type_support_data_t
{
  void * data[2];
} _GameStatusPC2Board_type_support_data_t;

static _GameStatusPC2Board_type_support_data_t _GameStatusPC2Board_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GameStatusPC2Board_message_typesupport_map = {
  2,
  "my_interfaces",
  &_GameStatusPC2Board_message_typesupport_ids.typesupport_identifier[0],
  &_GameStatusPC2Board_message_typesupport_symbol_names.symbol_name[0],
  &_GameStatusPC2Board_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GameStatusPC2Board_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GameStatusPC2Board_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace my_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_interfaces::msg::GameStatusPC2Board>()
{
  return &::my_interfaces::msg::rosidl_typesupport_cpp::GameStatusPC2Board_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, my_interfaces, msg, GameStatusPC2Board)() {
  return get_message_type_support_handle<my_interfaces::msg::GameStatusPC2Board>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
