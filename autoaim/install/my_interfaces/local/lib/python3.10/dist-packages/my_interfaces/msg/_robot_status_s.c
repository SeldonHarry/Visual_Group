// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "my_interfaces/msg/detail/robot_status__struct.h"
#include "my_interfaces/msg/detail/robot_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_interfaces__msg__robot_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("my_interfaces.msg._robot_status.RobotStatus", full_classname_dest, 43) == 0);
  }
  my_interfaces__msg__RobotStatus * ros_message = _ros_message;
  {  // bullet_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "bullet_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bullet_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_compensate
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_compensate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_compensate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_compensate
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_compensate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_compensate = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_color
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_color");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_color = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // is_big_energy
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_big_energy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->is_big_energy = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // program_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "program_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->program_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // latency_cmd_to_fire
    PyObject * field = PyObject_GetAttrString(_pymsg, "latency_cmd_to_fire");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->latency_cmd_to_fire = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // last_shoot_aim_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_shoot_aim_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_shoot_aim_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // laser_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "laser_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->laser_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lrc
    PyObject * field = PyObject_GetAttrString(_pymsg, "lrc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lrc = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_interfaces__msg__robot_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_interfaces.msg._robot_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_interfaces__msg__RobotStatus * ros_message = (my_interfaces__msg__RobotStatus *)raw_ros_message;
  {  // bullet_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bullet_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bullet_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_compensate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_compensate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_compensate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_compensate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_compensate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_compensate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_color
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_color);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_color", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_big_energy
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->is_big_energy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_big_energy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // program_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->program_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "program_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // latency_cmd_to_fire
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->latency_cmd_to_fire);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latency_cmd_to_fire", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_shoot_aim_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->last_shoot_aim_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_shoot_aim_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // laser_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->laser_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "laser_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lrc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->lrc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lrc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
