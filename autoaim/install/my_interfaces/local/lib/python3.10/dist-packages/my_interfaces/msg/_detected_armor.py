# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_interfaces:msg/DetectedArmor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectedArmor(type):
    """Metaclass of message 'DetectedArmor'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_interfaces.msg.DetectedArmor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detected_armor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detected_armor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detected_armor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detected_armor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detected_armor

            from geometry_msgs.msg import Point32
            if Point32.__class__._TYPE_SUPPORT is None:
                Point32.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectedArmor(metaclass=Metaclass_DetectedArmor):
    """Message class 'DetectedArmor'."""

    __slots__ = [
        '_pts',
        '_color',
        '_number',
        '_conf',
        '_conf_class',
    ]

    _fields_and_field_types = {
        'pts': 'geometry_msgs/Point32[4]',
        'color': 'int32',
        'number': 'int32',
        'conf': 'float',
        'conf_class': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point32
        self.pts = kwargs.get(
            'pts',
            [Point32() for x in range(4)]
        )
        self.color = kwargs.get('color', int())
        self.number = kwargs.get('number', int())
        self.conf = kwargs.get('conf', float())
        self.conf_class = kwargs.get('conf_class', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pts != other.pts:
            return False
        if self.color != other.color:
            return False
        if self.number != other.number:
            return False
        if self.conf != other.conf:
            return False
        if self.conf_class != other.conf_class:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pts(self):
        """Message field 'pts'."""
        return self._pts

    @pts.setter
    def pts(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, Point32) for v in value) and
                 True), \
                "The 'pts' field must be a set or sequence with length 4 and each value of type 'Point32'"
        self._pts = value

    @builtins.property
    def color(self):
        """Message field 'color'."""
        return self._color

    @color.setter
    def color(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'color' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'color' field must be an integer in [-2147483648, 2147483647]"
        self._color = value

    @builtins.property
    def number(self):
        """Message field 'number'."""
        return self._number

    @number.setter
    def number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'number' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'number' field must be an integer in [-2147483648, 2147483647]"
        self._number = value

    @builtins.property
    def conf(self):
        """Message field 'conf'."""
        return self._conf

    @conf.setter
    def conf(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'conf' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'conf' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._conf = value

    @builtins.property
    def conf_class(self):
        """Message field 'conf_class'."""
        return self._conf_class

    @conf_class.setter
    def conf_class(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'conf_class' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'conf_class' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._conf_class = value
