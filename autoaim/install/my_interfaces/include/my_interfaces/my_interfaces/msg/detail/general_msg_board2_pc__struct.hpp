// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/GeneralMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__GeneralMsgBoard2PC __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__GeneralMsgBoard2PC __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GeneralMsgBoard2PC_
{
  using Type = GeneralMsgBoard2PC_<ContainerAllocator>;

  explicit GeneralMsgBoard2PC_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit GeneralMsgBoard2PC_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  // pointer types
  using RawPtr =
    my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__GeneralMsgBoard2PC
    std::shared_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__GeneralMsgBoard2PC
    std::shared_ptr<my_interfaces::msg::GeneralMsgBoard2PC_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeneralMsgBoard2PC_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const GeneralMsgBoard2PC_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeneralMsgBoard2PC_

// alias to use template instance with default allocator
using GeneralMsgBoard2PC =
  my_interfaces::msg::GeneralMsgBoard2PC_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_BOARD2_PC__STRUCT_HPP_
