// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/PCWorkMode.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__PCWorkMode __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__PCWorkMode __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PCWorkMode_
{
  using Type = PCWorkMode_<ContainerAllocator>;

  explicit PCWorkMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit PCWorkMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t AUTOAIM =
    1u;
  static constexpr uint8_t ENERGY =
    2u;
  static constexpr uint8_t ENERGY_DISTURB =
    3u;
  static constexpr uint8_t NAVIGATION =
    4u;
  static constexpr uint8_t DECISION =
    5u;

  // pointer types
  using RawPtr =
    my_interfaces::msg::PCWorkMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::PCWorkMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::PCWorkMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::PCWorkMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__PCWorkMode
    std::shared_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__PCWorkMode
    std::shared_ptr<my_interfaces::msg::PCWorkMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PCWorkMode_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const PCWorkMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PCWorkMode_

// alias to use template instance with default allocator
using PCWorkMode =
  my_interfaces::msg::PCWorkMode_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PCWorkMode_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PCWorkMode_<ContainerAllocator>::AUTOAIM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PCWorkMode_<ContainerAllocator>::ENERGY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PCWorkMode_<ContainerAllocator>::ENERGY_DISTURB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PCWorkMode_<ContainerAllocator>::NAVIGATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PCWorkMode_<ContainerAllocator>::DECISION;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__PC_WORK_MODE__STRUCT_HPP_
