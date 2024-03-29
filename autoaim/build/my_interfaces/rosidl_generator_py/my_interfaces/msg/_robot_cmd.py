# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_interfaces:msg/RobotCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotCmd(type):
    """Metaclass of message 'RobotCmd'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TRACKING': 0,
        'SHOOT_NOW': 1,
        'IDLE': 2,
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
                'my_interfaces.msg.RobotCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TRACKING': cls.__constants['TRACKING'],
            'SHOOT_NOW': cls.__constants['SHOOT_NOW'],
            'IDLE': cls.__constants['IDLE'],
        }

    @property
    def TRACKING(self):
        """Message constant 'TRACKING'."""
        return Metaclass_RobotCmd.__constants['TRACKING']

    @property
    def SHOOT_NOW(self):
        """Message constant 'SHOOT_NOW'."""
        return Metaclass_RobotCmd.__constants['SHOOT_NOW']

    @property
    def IDLE(self):
        """Message constant 'IDLE'."""
        return Metaclass_RobotCmd.__constants['IDLE']


class RobotCmd(metaclass=Metaclass_RobotCmd):
    """
    Message class 'RobotCmd'.

    Constants:
      TRACKING
      SHOOT_NOW
      IDLE
    """

    __slots__ = [
        '_start',
        '_seq_id',
        '_aim_id',
        '_car_id',
        '_detection_info',
        '_yaw',
        '_pitch',
        '_yaw_v',
        '_pithc_v',
        '_dist',
        '_shoot',
        '_period',
        '_lrc',
        '_lock_yaw',
        '_end',
    ]

    _fields_and_field_types = {
        'start': 'uint8',
        'seq_id': 'uint8',
        'aim_id': 'int32',
        'car_id': 'uint16',
        'detection_info': 'uint16',
        'yaw': 'float',
        'pitch': 'float',
        'yaw_v': 'float',
        'pithc_v': 'float',
        'dist': 'float',
        'shoot': 'uint8',
        'period': 'uint16',
        'lrc': 'uint8',
        'lock_yaw': 'boolean',
        'end': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.start = kwargs.get('start', int())
        self.seq_id = kwargs.get('seq_id', int())
        self.aim_id = kwargs.get('aim_id', int())
        self.car_id = kwargs.get('car_id', int())
        self.detection_info = kwargs.get('detection_info', int())
        self.yaw = kwargs.get('yaw', float())
        self.pitch = kwargs.get('pitch', float())
        self.yaw_v = kwargs.get('yaw_v', float())
        self.pithc_v = kwargs.get('pithc_v', float())
        self.dist = kwargs.get('dist', float())
        self.shoot = kwargs.get('shoot', int())
        self.period = kwargs.get('period', int())
        self.lrc = kwargs.get('lrc', int())
        self.lock_yaw = kwargs.get('lock_yaw', bool())
        self.end = kwargs.get('end', int())

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
        if self.start != other.start:
            return False
        if self.seq_id != other.seq_id:
            return False
        if self.aim_id != other.aim_id:
            return False
        if self.car_id != other.car_id:
            return False
        if self.detection_info != other.detection_info:
            return False
        if self.yaw != other.yaw:
            return False
        if self.pitch != other.pitch:
            return False
        if self.yaw_v != other.yaw_v:
            return False
        if self.pithc_v != other.pithc_v:
            return False
        if self.dist != other.dist:
            return False
        if self.shoot != other.shoot:
            return False
        if self.period != other.period:
            return False
        if self.lrc != other.lrc:
            return False
        if self.lock_yaw != other.lock_yaw:
            return False
        if self.end != other.end:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start(self):
        """Message field 'start'."""
        return self._start

    @start.setter
    def start(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'start' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'start' field must be an unsigned integer in [0, 255]"
        self._start = value

    @builtins.property
    def seq_id(self):
        """Message field 'seq_id'."""
        return self._seq_id

    @seq_id.setter
    def seq_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'seq_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'seq_id' field must be an unsigned integer in [0, 255]"
        self._seq_id = value

    @builtins.property
    def aim_id(self):
        """Message field 'aim_id'."""
        return self._aim_id

    @aim_id.setter
    def aim_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'aim_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'aim_id' field must be an integer in [-2147483648, 2147483647]"
        self._aim_id = value

    @builtins.property
    def car_id(self):
        """Message field 'car_id'."""
        return self._car_id

    @car_id.setter
    def car_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'car_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'car_id' field must be an unsigned integer in [0, 65535]"
        self._car_id = value

    @builtins.property
    def detection_info(self):
        """Message field 'detection_info'."""
        return self._detection_info

    @detection_info.setter
    def detection_info(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'detection_info' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'detection_info' field must be an unsigned integer in [0, 65535]"
        self._detection_info = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch = value

    @builtins.property
    def yaw_v(self):
        """Message field 'yaw_v'."""
        return self._yaw_v

    @yaw_v.setter
    def yaw_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_v' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_v' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_v = value

    @builtins.property
    def pithc_v(self):
        """Message field 'pithc_v'."""
        return self._pithc_v

    @pithc_v.setter
    def pithc_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pithc_v' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pithc_v' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pithc_v = value

    @builtins.property
    def dist(self):
        """Message field 'dist'."""
        return self._dist

    @dist.setter
    def dist(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'dist' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._dist = value

    @builtins.property
    def shoot(self):
        """Message field 'shoot'."""
        return self._shoot

    @shoot.setter
    def shoot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shoot' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'shoot' field must be an unsigned integer in [0, 255]"
        self._shoot = value

    @builtins.property
    def period(self):
        """Message field 'period'."""
        return self._period

    @period.setter
    def period(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'period' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'period' field must be an unsigned integer in [0, 65535]"
        self._period = value

    @builtins.property
    def lrc(self):
        """Message field 'lrc'."""
        return self._lrc

    @lrc.setter
    def lrc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lrc' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'lrc' field must be an unsigned integer in [0, 255]"
        self._lrc = value

    @builtins.property
    def lock_yaw(self):
        """Message field 'lock_yaw'."""
        return self._lock_yaw

    @lock_yaw.setter
    def lock_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'lock_yaw' field must be of type 'bool'"
        self._lock_yaw = value

    @builtins.property
    def end(self):
        """Message field 'end'."""
        return self._end

    @end.setter
    def end(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'end' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'end' field must be an unsigned integer in [0, 255]"
        self._end = value
