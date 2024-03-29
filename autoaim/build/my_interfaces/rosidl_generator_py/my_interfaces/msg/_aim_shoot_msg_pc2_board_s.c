// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_interfaces:msg/AimShootMsgPC2Board.idl
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
#include "my_interfaces/msg/detail/aim_shoot_msg_pc2_board__struct.h"
#include "my_interfaces/msg/detail/aim_shoot_msg_pc2_board__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_interfaces__msg__aim_shoot_msg_pc2_board__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
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
    assert(strncmp("my_interfaces.msg._aim_shoot_msg_pc2_board.AimShootMsgPC2Board", full_classname_dest, 62) == 0);
  }
  my_interfaces__msg__AimShootMsgPC2Board * ros_message = _ros_message;
  {  // yaw_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // shoot_flag
    PyObject * field = PyObject_GetAttrString(_pymsg, "shoot_flag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->shoot_flag = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // shoot_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "shoot_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->shoot_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_interfaces__msg__aim_shoot_msg_pc2_board__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AimShootMsgPC2Board */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_interfaces.msg._aim_shoot_msg_pc2_board");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AimShootMsgPC2Board");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_interfaces__msg__AimShootMsgPC2Board * ros_message = (my_interfaces__msg__AimShootMsgPC2Board *)raw_ros_message;
  {  // yaw_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shoot_flag
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->shoot_flag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shoot_flag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shoot_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->shoot_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shoot_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
