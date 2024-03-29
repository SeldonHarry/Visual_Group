// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/RobotCmd.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__RobotCmd __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__RobotCmd __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotCmd_
{
  using Type = RobotCmd_<ContainerAllocator>;

  explicit RobotCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start = 0;
      this->seq_id = 0;
      this->aim_id = 0l;
      this->car_id = 0;
      this->detection_info = 0;
      this->yaw = 0.0f;
      this->pitch = 0.0f;
      this->yaw_v = 0.0f;
      this->pithc_v = 0.0f;
      this->dist = 0.0f;
      this->shoot = 0;
      this->period = 0;
      this->lrc = 0;
      this->lock_yaw = false;
      this->end = 0;
    }
  }

  explicit RobotCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start = 0;
      this->seq_id = 0;
      this->aim_id = 0l;
      this->car_id = 0;
      this->detection_info = 0;
      this->yaw = 0.0f;
      this->pitch = 0.0f;
      this->yaw_v = 0.0f;
      this->pithc_v = 0.0f;
      this->dist = 0.0f;
      this->shoot = 0;
      this->period = 0;
      this->lrc = 0;
      this->lock_yaw = false;
      this->end = 0;
    }
  }

  // field types and members
  using _start_type =
    uint8_t;
  _start_type start;
  using _seq_id_type =
    uint8_t;
  _seq_id_type seq_id;
  using _aim_id_type =
    int32_t;
  _aim_id_type aim_id;
  using _car_id_type =
    uint16_t;
  _car_id_type car_id;
  using _detection_info_type =
    uint16_t;
  _detection_info_type detection_info;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_v_type =
    float;
  _yaw_v_type yaw_v;
  using _pithc_v_type =
    float;
  _pithc_v_type pithc_v;
  using _dist_type =
    float;
  _dist_type dist;
  using _shoot_type =
    uint8_t;
  _shoot_type shoot;
  using _period_type =
    uint16_t;
  _period_type period;
  using _lrc_type =
    uint8_t;
  _lrc_type lrc;
  using _lock_yaw_type =
    bool;
  _lock_yaw_type lock_yaw;
  using _end_type =
    uint8_t;
  _end_type end;

  // setters for named parameter idiom
  Type & set__start(
    const uint8_t & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__seq_id(
    const uint8_t & _arg)
  {
    this->seq_id = _arg;
    return *this;
  }
  Type & set__aim_id(
    const int32_t & _arg)
  {
    this->aim_id = _arg;
    return *this;
  }
  Type & set__car_id(
    const uint16_t & _arg)
  {
    this->car_id = _arg;
    return *this;
  }
  Type & set__detection_info(
    const uint16_t & _arg)
  {
    this->detection_info = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw_v(
    const float & _arg)
  {
    this->yaw_v = _arg;
    return *this;
  }
  Type & set__pithc_v(
    const float & _arg)
  {
    this->pithc_v = _arg;
    return *this;
  }
  Type & set__dist(
    const float & _arg)
  {
    this->dist = _arg;
    return *this;
  }
  Type & set__shoot(
    const uint8_t & _arg)
  {
    this->shoot = _arg;
    return *this;
  }
  Type & set__period(
    const uint16_t & _arg)
  {
    this->period = _arg;
    return *this;
  }
  Type & set__lrc(
    const uint8_t & _arg)
  {
    this->lrc = _arg;
    return *this;
  }
  Type & set__lock_yaw(
    const bool & _arg)
  {
    this->lock_yaw = _arg;
    return *this;
  }
  Type & set__end(
    const uint8_t & _arg)
  {
    this->end = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TRACKING =
    0u;
  static constexpr uint8_t SHOOT_NOW =
    1u;
  static constexpr uint8_t IDLE =
    2u;

  // pointer types
  using RawPtr =
    my_interfaces::msg::RobotCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::RobotCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::RobotCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::RobotCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__RobotCmd
    std::shared_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__RobotCmd
    std::shared_ptr<my_interfaces::msg::RobotCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotCmd_ & other) const
  {
    if (this->start != other.start) {
      return false;
    }
    if (this->seq_id != other.seq_id) {
      return false;
    }
    if (this->aim_id != other.aim_id) {
      return false;
    }
    if (this->car_id != other.car_id) {
      return false;
    }
    if (this->detection_info != other.detection_info) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw_v != other.yaw_v) {
      return false;
    }
    if (this->pithc_v != other.pithc_v) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    if (this->shoot != other.shoot) {
      return false;
    }
    if (this->period != other.period) {
      return false;
    }
    if (this->lrc != other.lrc) {
      return false;
    }
    if (this->lock_yaw != other.lock_yaw) {
      return false;
    }
    if (this->end != other.end) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotCmd_

// alias to use template instance with default allocator
using RobotCmd =
  my_interfaces::msg::RobotCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotCmd_<ContainerAllocator>::TRACKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotCmd_<ContainerAllocator>::SHOOT_NOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotCmd_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_CMD__STRUCT_HPP_
