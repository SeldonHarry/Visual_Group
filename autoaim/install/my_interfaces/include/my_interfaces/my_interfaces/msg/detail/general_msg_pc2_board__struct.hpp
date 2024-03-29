// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/GeneralMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__GeneralMsgPC2Board __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__GeneralMsgPC2Board __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GeneralMsgPC2Board_
{
  using Type = GeneralMsgPC2Board_<ContainerAllocator>;

  explicit GeneralMsgPC2Board_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode_fdb = 0;
    }
  }

  explicit GeneralMsgPC2Board_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode_fdb = 0;
    }
  }

  // field types and members
  using _mode_fdb_type =
    uint8_t;
  _mode_fdb_type mode_fdb;

  // setters for named parameter idiom
  Type & set__mode_fdb(
    const uint8_t & _arg)
  {
    this->mode_fdb = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__GeneralMsgPC2Board
    std::shared_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__GeneralMsgPC2Board
    std::shared_ptr<my_interfaces::msg::GeneralMsgPC2Board_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeneralMsgPC2Board_ & other) const
  {
    if (this->mode_fdb != other.mode_fdb) {
      return false;
    }
    return true;
  }
  bool operator!=(const GeneralMsgPC2Board_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeneralMsgPC2Board_

// alias to use template instance with default allocator
using GeneralMsgPC2Board =
  my_interfaces::msg::GeneralMsgPC2Board_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__GENERAL_MSG_PC2_BOARD__STRUCT_HPP_
