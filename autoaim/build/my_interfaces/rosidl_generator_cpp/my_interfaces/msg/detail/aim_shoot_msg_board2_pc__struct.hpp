// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__AimShootMsgBoard2PC __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__AimShootMsgBoard2PC __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AimShootMsgBoard2PC_
{
  using Type = AimShootMsgBoard2PC_<ContainerAllocator>;

  explicit AimShootMsgBoard2PC_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->self_id = 0;
      this->yaw_angle = 0.0f;
      this->pitch_angle = 0.0f;
      this->yaw_speed = 0.0f;
      this->pitch_speed = 0.0f;
      this->yaw_offset = 0.0f;
      this->pitch_offset = 0.0f;
      this->dist = 0.0f;
      this->shoot_speed = 0.0f;
      this->shoot_delay = 0;
      this->shoot_id_fdb = 0ul;
      this->is_big_energy = 0;
      this->chassis_vx = 0.0f;
      this->chassis_vy = 0.0f;
    }
  }

  explicit AimShootMsgBoard2PC_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->self_id = 0;
      this->yaw_angle = 0.0f;
      this->pitch_angle = 0.0f;
      this->yaw_speed = 0.0f;
      this->pitch_speed = 0.0f;
      this->yaw_offset = 0.0f;
      this->pitch_offset = 0.0f;
      this->dist = 0.0f;
      this->shoot_speed = 0.0f;
      this->shoot_delay = 0;
      this->shoot_id_fdb = 0ul;
      this->is_big_energy = 0;
      this->chassis_vx = 0.0f;
      this->chassis_vy = 0.0f;
    }
  }

  // field types and members
  using _self_id_type =
    uint8_t;
  _self_id_type self_id;
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
  using _yaw_offset_type =
    float;
  _yaw_offset_type yaw_offset;
  using _pitch_offset_type =
    float;
  _pitch_offset_type pitch_offset;
  using _dist_type =
    float;
  _dist_type dist;
  using _shoot_speed_type =
    float;
  _shoot_speed_type shoot_speed;
  using _shoot_delay_type =
    uint8_t;
  _shoot_delay_type shoot_delay;
  using _shoot_id_fdb_type =
    uint32_t;
  _shoot_id_fdb_type shoot_id_fdb;
  using _is_big_energy_type =
    uint8_t;
  _is_big_energy_type is_big_energy;
  using _chassis_vx_type =
    float;
  _chassis_vx_type chassis_vx;
  using _chassis_vy_type =
    float;
  _chassis_vy_type chassis_vy;

  // setters for named parameter idiom
  Type & set__self_id(
    const uint8_t & _arg)
  {
    this->self_id = _arg;
    return *this;
  }
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
  Type & set__yaw_offset(
    const float & _arg)
  {
    this->yaw_offset = _arg;
    return *this;
  }
  Type & set__pitch_offset(
    const float & _arg)
  {
    this->pitch_offset = _arg;
    return *this;
  }
  Type & set__dist(
    const float & _arg)
  {
    this->dist = _arg;
    return *this;
  }
  Type & set__shoot_speed(
    const float & _arg)
  {
    this->shoot_speed = _arg;
    return *this;
  }
  Type & set__shoot_delay(
    const uint8_t & _arg)
  {
    this->shoot_delay = _arg;
    return *this;
  }
  Type & set__shoot_id_fdb(
    const uint32_t & _arg)
  {
    this->shoot_id_fdb = _arg;
    return *this;
  }
  Type & set__is_big_energy(
    const uint8_t & _arg)
  {
    this->is_big_energy = _arg;
    return *this;
  }
  Type & set__chassis_vx(
    const float & _arg)
  {
    this->chassis_vx = _arg;
    return *this;
  }
  Type & set__chassis_vy(
    const float & _arg)
  {
    this->chassis_vy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__AimShootMsgBoard2PC
    std::shared_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__AimShootMsgBoard2PC
    std::shared_ptr<my_interfaces::msg::AimShootMsgBoard2PC_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AimShootMsgBoard2PC_ & other) const
  {
    if (this->self_id != other.self_id) {
      return false;
    }
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
    if (this->yaw_offset != other.yaw_offset) {
      return false;
    }
    if (this->pitch_offset != other.pitch_offset) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    if (this->shoot_speed != other.shoot_speed) {
      return false;
    }
    if (this->shoot_delay != other.shoot_delay) {
      return false;
    }
    if (this->shoot_id_fdb != other.shoot_id_fdb) {
      return false;
    }
    if (this->is_big_energy != other.is_big_energy) {
      return false;
    }
    if (this->chassis_vx != other.chassis_vx) {
      return false;
    }
    if (this->chassis_vy != other.chassis_vy) {
      return false;
    }
    return true;
  }
  bool operator!=(const AimShootMsgBoard2PC_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AimShootMsgBoard2PC_

// alias to use template instance with default allocator
using AimShootMsgBoard2PC =
  my_interfaces::msg::AimShootMsgBoard2PC_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__AIM_SHOOT_MSG_BOARD2_PC__STRUCT_HPP_
