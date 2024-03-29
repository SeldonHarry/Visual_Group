// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'q'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"
// Member 'armors'
#include "my_interfaces/msg/detail/detected_armor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__DetectionResult __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__DetectionResult __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionResult_
{
  using Type = DetectionResult_<ContainerAllocator>;

  explicit DetectionResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : img(_init),
    q(_init)
  {
    (void)_init;
  }

  explicit DetectionResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : img(_alloc, _init),
    q(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _img_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _img_type img;
  using _q_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _q_type q;
  using _armors_type =
    std::vector<my_interfaces::msg::DetectedArmor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_interfaces::msg::DetectedArmor_<ContainerAllocator>>>;
  _armors_type armors;

  // setters for named parameter idiom
  Type & set__img(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->img = _arg;
    return *this;
  }
  Type & set__q(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__armors(
    const std::vector<my_interfaces::msg::DetectedArmor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_interfaces::msg::DetectedArmor_<ContainerAllocator>>> & _arg)
  {
    this->armors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::DetectionResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::DetectionResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::DetectionResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::DetectionResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__DetectionResult
    std::shared_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__DetectionResult
    std::shared_ptr<my_interfaces::msg::DetectionResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionResult_ & other) const
  {
    if (this->img != other.img) {
      return false;
    }
    if (this->q != other.q) {
      return false;
    }
    if (this->armors != other.armors) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionResult_

// alias to use template instance with default allocator
using DetectionResult =
  my_interfaces::msg::DetectionResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_HPP_
