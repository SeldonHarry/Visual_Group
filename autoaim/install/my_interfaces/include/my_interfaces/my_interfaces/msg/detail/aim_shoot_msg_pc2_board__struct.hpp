// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/AimShootMsgPC2Board.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__AimShootMsgPC2Board __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__AimShootMsgPC2Board __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AimShootMsgPC2Board_
{
  using Type = AimShootMsgPC2Board_<ContainerAllocator>;

  explicit AimShootMsgPC2Board_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw_angle = 0.0f;
      this->pitch_angle = 0.0f;
      this->yaw_speed = 0.0f;
      this->pitch_speed = 0.0f;
      this->dist = 0.0f;
      this->shoot_flag = 0;
      this->shoot_id = 0;
      this->enemy_id = 0;
    }
  }

  explicit AimShootMsgPC2Board_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw_angle = 0.0f;
      this->pitch_angle = 0.0f;
      this->yaw_speed = 0.0f;
      this->pitch_speed = 0.0f;
      this->dist = 0.0f;
      this->shoot_flag = 0;
      this->shoot_id = 0;
      this->enemy_id = 0;
    }
  }

  // field types and members
  using _yaw_angle_type =
    float;
  _yaw_angle_type yaw_angle;
  using _pitch_angle_type =
    float;
  _pitch_angle_type pitch_angle;
  using _yaw_speed_type =
    float;
  _yaw_speed_type yaw_speed;
  using _pitch_speed_type =
    float;
  _pitch_speed_type pitch_speed;
  using _dist_type =
    float;
  _dist_type dist;
  using _shoot_flag_type =
    uint8_t;
  _shoot_flag_type shoot_flag;
  using _shoot_id_type =
    uint8_t;
  _shoot_id_type shoot_id;
  using _enemy_id_type =
    uint8_t;
  _enemy_id_type enemy_id;

  // setters for named parameter idiom
  Type & set__yaw_angle(
    const float & _arg)
  {
    this->yaw_angle = _arg;
    return *this;
  }
  Type & set__pitch_angle(
    const float & _arg)
  {
    this->pitch_angle = _arg;
    return *this;
  }
  Type & set__yaw_speed(
    const float & _arg)
  {
    this->yaw_speed = _arg;
    return *this;
  }
  Type & set__pitch_speed(
    const float & _arg)
  {
    this->pitch_speed = _arg;
    return *this;
  }
  Type & set__dist(
    const float & _arg)
  {
    this->dist = _arg;
    return *this;
  }
  Type & set__shoot_flag(
    const uint8_t & _arg)
  {
    this->shoot_flag = _arg;
    return *this;
  }
  Type & set__shoot_id(
    const uint8_t & _arg)
  {
    this->shoot_id = _arg;
    return *this;
  }
  Type & set__enemy_id(
    const uint8_t & _arg)
  {
    this->enemy_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__AimShootMsgPC2Board
    std::shared_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__AimShootMsgPC2Board
    std::shared_ptr<my_interfaces::msg::AimShootMsgPC2Board_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AimShootMsgPC2Board_ & other) const
  {
    if (this->yaw_angle != other.yaw_angle) {
      return false;
    }
    if (this->pitch_angle != other.pitch_angle) {
      return false;
    }
    if (this->yaw_speed != other.yaw_speed) {
      return false;
    }
    if (this->pitch_speed != other.pitch_speed) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    if (this->shoot_flag != other.shoot_flag) {
      return false;
    }
    if (this->shoot_id != other.shoot_id) {
      return false;
    }
    if (this->enemy_id != other.enemy_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const AimShootMsgPC2Board_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AimShootMsgPC2Board_

// alias to use template instance with default allocator
using AimShootMsgPC2Board =
  my_interfaces::msg::AimShootMsgPC2Board_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_PC2_BOARD__STRUCT_HPP_
