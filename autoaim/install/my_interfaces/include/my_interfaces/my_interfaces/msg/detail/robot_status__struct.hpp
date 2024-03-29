// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__RobotStatus __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bullet_speed = 0.0f;
      this->yaw_compensate = 0.0f;
      this->pitch_compensate = 0.0f;
      this->enemy_color = 0;
      this->is_big_energy = 0;
      this->program_mode = 0;
      this->latency_cmd_to_fire = 0;
      this->last_shoot_aim_id = 0l;
      this->laser_distance = 0.0f;
      this->lrc = 0;
    }
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bullet_speed = 0.0f;
      this->yaw_compensate = 0.0f;
      this->pitch_compensate = 0.0f;
      this->enemy_color = 0;
      this->is_big_energy = 0;
      this->program_mode = 0;
      this->latency_cmd_to_fire = 0;
      this->last_shoot_aim_id = 0l;
      this->laser_distance = 0.0f;
      this->lrc = 0;
    }
  }

  // field types and members
  using _bullet_speed_type =
    float;
  _bullet_speed_type bullet_speed;
  using _yaw_compensate_type =
    float;
  _yaw_compensate_type yaw_compensate;
  using _pitch_compensate_type =
    float;
  _pitch_compensate_type pitch_compensate;
  using _enemy_color_type =
    uint8_t;
  _enemy_color_type enemy_color;
  using _is_big_energy_type =
    uint8_t;
  _is_big_energy_type is_big_energy;
  using _program_mode_type =
    uint8_t;
  _program_mode_type program_mode;
  using _latency_cmd_to_fire_type =
    uint8_t;
  _latency_cmd_to_fire_type latency_cmd_to_fire;
  using _last_shoot_aim_id_type =
    int32_t;
  _last_shoot_aim_id_type last_shoot_aim_id;
  using _laser_distance_type =
    float;
  _laser_distance_type laser_distance;
  using _lrc_type =
    uint8_t;
  _lrc_type lrc;

  // setters for named parameter idiom
  Type & set__bullet_speed(
    const float & _arg)
  {
    this->bullet_speed = _arg;
    return *this;
  }
  Type & set__yaw_compensate(
    const float & _arg)
  {
    this->yaw_compensate = _arg;
    return *this;
  }
  Type & set__pitch_compensate(
    const float & _arg)
  {
    this->pitch_compensate = _arg;
    return *this;
  }
  Type & set__enemy_color(
    const uint8_t & _arg)
  {
    this->enemy_color = _arg;
    return *this;
  }
  Type & set__is_big_energy(
    const uint8_t & _arg)
  {
    this->is_big_energy = _arg;
    return *this;
  }
  Type & set__program_mode(
    const uint8_t & _arg)
  {
    this->program_mode = _arg;
    return *this;
  }
  Type & set__latency_cmd_to_fire(
    const uint8_t & _arg)
  {
    this->latency_cmd_to_fire = _arg;
    return *this;
  }
  Type & set__last_shoot_aim_id(
    const int32_t & _arg)
  {
    this->last_shoot_aim_id = _arg;
    return *this;
  }
  Type & set__laser_distance(
    const float & _arg)
  {
    this->laser_distance = _arg;
    return *this;
  }
  Type & set__lrc(
    const uint8_t & _arg)
  {
    this->lrc = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t BLUE =
    0u;
  static constexpr uint8_t RED =
    1u;
  static constexpr uint8_t MANUAL =
    0u;
  static constexpr uint8_t AUTOAIM =
    1u;
  static constexpr uint8_t ANTITOP =
    2u;
  static constexpr uint8_t ENERGY_HIT =
    4u;
  static constexpr uint8_t ENERGY_DISTURB =
    5u;
  static constexpr uint8_t NOT_RECEIVED =
    8u;

  // pointer types
  using RawPtr =
    my_interfaces::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__RobotStatus
    std::shared_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__RobotStatus
    std::shared_ptr<my_interfaces::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->bullet_speed != other.bullet_speed) {
      return false;
    }
    if (this->yaw_compensate != other.yaw_compensate) {
      return false;
    }
    if (this->pitch_compensate != other.pitch_compensate) {
      return false;
    }
    if (this->enemy_color != other.enemy_color) {
      return false;
    }
    if (this->is_big_energy != other.is_big_energy) {
      return false;
    }
    if (this->program_mode != other.program_mode) {
      return false;
    }
    if (this->latency_cmd_to_fire != other.latency_cmd_to_fire) {
      return false;
    }
    if (this->last_shoot_aim_id != other.last_shoot_aim_id) {
      return false;
    }
    if (this->laser_distance != other.laser_distance) {
      return false;
    }
    if (this->lrc != other.lrc) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  my_interfaces::msg::RobotStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::BLUE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::RED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::AUTOAIM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::ANTITOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::ENERGY_HIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::ENERGY_DISTURB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotStatus_<ContainerAllocator>::NOT_RECEIVED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
