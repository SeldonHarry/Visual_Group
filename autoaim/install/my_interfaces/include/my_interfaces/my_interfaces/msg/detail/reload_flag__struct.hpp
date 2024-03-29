// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/ReloadFlag.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__ReloadFlag __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__ReloadFlag __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ReloadFlag_
{
  using Type = ReloadFlag_<ContainerAllocator>;

  explicit ReloadFlag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = false;
    }
  }

  explicit ReloadFlag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = false;
    }
  }

  // field types and members
  using _flag_type =
    bool;
  _flag_type flag;

  // setters for named parameter idiom
  Type & set__flag(
    const bool & _arg)
  {
    this->flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::ReloadFlag_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::ReloadFlag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::ReloadFlag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::ReloadFlag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__ReloadFlag
    std::shared_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__ReloadFlag
    std::shared_ptr<my_interfaces::msg::ReloadFlag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReloadFlag_ & other) const
  {
    if (this->flag != other.flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReloadFlag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReloadFlag_

// alias to use template instance with default allocator
using ReloadFlag =
  my_interfaces::msg::ReloadFlag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__RELOAD_FLAG__STRUCT_HPP_
