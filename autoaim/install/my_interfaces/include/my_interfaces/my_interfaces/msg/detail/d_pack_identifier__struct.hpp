// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/DPackIdentifier.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__DPackIdentifier __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__DPackIdentifier __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DPackIdentifier_
{
  using Type = DPackIdentifier_<ContainerAllocator>;

  explicit DPackIdentifier_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = 0;
    }
  }

  explicit DPackIdentifier_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = 0;
    }
  }

  // field types and members
  using _frame_id_type =
    uint8_t;
  _frame_id_type frame_id;

  // setters for named parameter idiom
  Type & set__frame_id(
    const uint8_t & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MIMIPC_COMM_MAX_SIZE =
    64u;
  static constexpr uint8_t MINIPC_COMM_SOF =
    35u;
  static constexpr uint8_t PC2BOARD =
    0u;
  static constexpr uint8_t BOARD2PC =
    16u;
  static constexpr uint8_t GENERAL =
    0u;
  static constexpr uint8_t AIM_SHOOT =
    1u;
  static constexpr uint8_t NAVIGATION =
    2u;
  static constexpr uint8_t GAME_STATUS =
    3u;

  // pointer types
  using RawPtr =
    my_interfaces::msg::DPackIdentifier_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::DPackIdentifier_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::DPackIdentifier_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::DPackIdentifier_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__DPackIdentifier
    std::shared_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__DPackIdentifier
    std::shared_ptr<my_interfaces::msg::DPackIdentifier_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DPackIdentifier_ & other) const
  {
    if (this->frame_id != other.frame_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const DPackIdentifier_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DPackIdentifier_

// alias to use template instance with default allocator
using DPackIdentifier =
  my_interfaces::msg::DPackIdentifier_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::MIMIPC_COMM_MAX_SIZE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::MINIPC_COMM_SOF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::PC2BOARD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::BOARD2PC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::GENERAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::AIM_SHOOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::NAVIGATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DPackIdentifier_<ContainerAllocator>::GAME_STATUS;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__D_PACK_IDENTIFIER__STRUCT_HPP_
