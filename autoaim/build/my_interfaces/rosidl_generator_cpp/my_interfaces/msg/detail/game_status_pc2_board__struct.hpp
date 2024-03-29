// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/GameStatusPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__GameStatusPC2Board __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__GameStatusPC2Board __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameStatusPC2Board_
{
  using Type = GameStatusPC2Board_<ContainerAllocator>;

  explicit GameStatusPC2Board_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reserve = 0;
    }
  }

  explicit GameStatusPC2Board_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reserve = 0;
    }
  }

  // field types and members
  using _reserve_type =
    uint8_t;
  _reserve_type reserve;

  // setters for named parameter idiom
  Type & set__reserve(
    const uint8_t & _arg)
  {
    this->reserve = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__GameStatusPC2Board
    std::shared_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__GameStatusPC2Board
    std::shared_ptr<my_interfaces::msg::GameStatusPC2Board_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameStatusPC2Board_ & other) const
  {
    if (this->reserve != other.reserve) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameStatusPC2Board_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameStatusPC2Board_

// alias to use template instance with default allocator
using GameStatusPC2Board =
  my_interfaces::msg::GameStatusPC2Board_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GAME_STATUS_PC2_BOARD__STRUCT_HPP_
