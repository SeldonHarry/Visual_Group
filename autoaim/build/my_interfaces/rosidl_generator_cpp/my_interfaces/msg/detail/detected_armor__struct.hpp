// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/DetectedArmor.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pts'
#include "geometry_msgs/msg/detail/point32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__DetectedArmor __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__DetectedArmor __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedArmor_
{
  using Type = DetectedArmor_<ContainerAllocator>;

  explicit DetectedArmor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pts.fill(geometry_msgs::msg::Point32_<ContainerAllocator>{_init});
      this->color = 0l;
      this->number = 0l;
      this->conf = 0.0f;
      this->conf_class = 0.0f;
    }
  }

  explicit DetectedArmor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pts(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pts.fill(geometry_msgs::msg::Point32_<ContainerAllocator>{_alloc, _init});
      this->color = 0l;
      this->number = 0l;
      this->conf = 0.0f;
      this->conf_class = 0.0f;
    }
  }

  // field types and members
  using _pts_type =
    std::array<geometry_msgs::msg::Point32_<ContainerAllocator>, 4>;
  _pts_type pts;
  using _color_type =
    int32_t;
  _color_type color;
  using _number_type =
    int32_t;
  _number_type number;
  using _conf_type =
    float;
  _conf_type conf;
  using _conf_class_type =
    float;
  _conf_class_type conf_class;

  // setters for named parameter idiom
  Type & set__pts(
    const std::array<geometry_msgs::msg::Point32_<ContainerAllocator>, 4> & _arg)
  {
    this->pts = _arg;
    return *this;
  }
  Type & set__color(
    const int32_t & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__number(
    const int32_t & _arg)
  {
    this->number = _arg;
    return *this;
  }
  Type & set__conf(
    const float & _arg)
  {
    this->conf = _arg;
    return *this;
  }
  Type & set__conf_class(
    const float & _arg)
  {
    this->conf_class = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::DetectedArmor_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::DetectedArmor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::DetectedArmor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::DetectedArmor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__DetectedArmor
    std::shared_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__DetectedArmor
    std::shared_ptr<my_interfaces::msg::DetectedArmor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedArmor_ & other) const
  {
    if (this->pts != other.pts) {
      return false;
    }
    if (this->color != other.color) {
      return false;
    }
    if (this->number != other.number) {
      return false;
    }
    if (this->conf != other.conf) {
      return false;
    }
    if (this->conf_class != other.conf_class) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedArmor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedArmor_

// alias to use template instance with default allocator
using DetectedArmor =
  my_interfaces::msg::DetectedArmor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTED_ARMOR__STRUCT_HPP_
