// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_interfaces:msg/RobotCmd.idl
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
#include "my_interfaces/msg/detail/robot_cmd__struct.h"
#include "my_interfaces/msg/detail/robot_cmd__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_interfaces__msg__robot_cmd__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("my_interfaces.msg._robot_cmd.RobotCmd", full_classname_dest, 37) == 0);
  }
  my_interfaces__msg__RobotCmd * ros_message = _ros_message;
  {  // start
    PyObject * field = PyObject_GetAttrString(_pymsg, "start");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->start = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // seq_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "seq_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->seq_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // aim_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "aim_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->aim_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // car_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "car_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->car_id = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // detection_info
    PyObject * field = PyObject_GetAttrString(_pymsg, "detection_info");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->detection_info = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_v = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pithc_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "pithc_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pithc_v = (float)PyFloat_AS_DOUBLE(field);
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
  {  // shoot
    PyObject * field = PyObject_GetAttrString(_pymsg, "shoot");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->shoot = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // period
    PyObject * field = PyObject_GetAttrString(_pymsg, "period");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->period = (uint16_t)PyLong_AsUnsignedLong(field);
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
  {  // lock_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "lock_yaw");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->lock_yaw = (Py_True == field);
    Py_DECREF(field);
  }
  {  // end
    PyObject * field = PyObject_GetAttrString(_pymsg, "end");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->end = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_interfaces__msg__robot_cmd__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotCmd */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_interfaces.msg._robot_cmd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotCmd");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_interfaces__msg__RobotCmd * ros_message = (my_interfaces__msg__RobotCmd *)raw_ros_message;
  {  // start
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->start);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // seq_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->seq_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "seq_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aim_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->aim_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aim_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // car_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->car_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "car_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // detection_info
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->detection_info);
    {
      int rc = PyObject_SetAttrString(_pymessage, "detection_info", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pithc_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pithc_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pithc_v", field);
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
  {  // shoot
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->shoot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shoot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // period
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->period);
    {
      int rc = PyObject_SetAttrString(_pymessage, "period", field);
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
  {  // lock_yaw
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->lock_yaw ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lock_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // end
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->end);
    {
      int rc = PyObject_SetAttrString(_pymessage, "end", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
