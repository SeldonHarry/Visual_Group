# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_interfaces:msg/AimShootMsgPC2Board.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AimShootMsgPC2Board(type):
    """Metaclass of message 'AimShootMsgPC2Board'."""

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
                'my_interfaces.msg.AimShootMsgPC2Board')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__aim_shoot_msg_pc2_board
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__aim_shoot_msg_pc2_board
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__aim_shoot_msg_pc2_board
            cls._TYPE_SUPPORT = module.type_support_msg__msg__aim_shoot_msg_pc2_board
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__aim_shoot_msg_pc2_board

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AimShootMsgPC2Board(metaclass=Metaclass_AimShootMsgPC2Board):
    """Message class 'AimShootMsgPC2Board'."""

    __slots__ = [
        '_yaw_angle',
        '_pitch_angle',
        '_yaw_speed',
        '_pitch_speed',
        '_dist',
        '_shoot_flag',
        '_shoot_id',
        '_enemy_id',
    ]

    _fields_and_field_types = {
        'yaw_angle': 'float',
        'pitch_angle': 'float',
        'yaw_speed': 'float',
        'pitch_speed': 'float',
        'dist': 'float',
        'shoot_flag': 'uint8',
        'shoot_id': 'uint8',
        'enemy_id': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.yaw_angle = kwargs.get('yaw_angle', float())
        self.pitch_angle = kwargs.get('pitch_angle', float())
        self.yaw_speed = kwargs.get('yaw_speed', float())
        self.pitch_speed = kwargs.get('pitch_speed', float())
        self.dist = kwargs.get('dist', float())
        self.shoot_flag = kwargs.get('shoot_flag', int())
        self.shoot_id = kwargs.get('shoot_id', int())
        self.enemy_id = kwargs.get('enemy_id', int())

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
        if self.yaw_angle != other.yaw_angle:
            return False
        if self.pitch_angle != other.pitch_angle:
            return False
        if self.yaw_speed != other.yaw_speed:
            return False
        if self.pitch_speed != other.pitch_speed:
            return False
        if self.dist != other.dist:
            return False
        if self.shoot_flag != other.shoot_flag:
            return False
        if self.shoot_id != other.shoot_id:
            return False
        if self.enemy_id != other.enemy_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def yaw_angle(self):
        """Message field 'yaw_angle'."""
        return self._yaw_angle

    @yaw_angle.setter
    def yaw_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_angle = value

    @builtins.property
    def pitch_angle(self):
        """Message field 'pitch_angle'."""
        return self._pitch_angle

    @pitch_angle.setter
    def pitch_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_angle = value

    @builtins.property
    def yaw_speed(self):
        """Message field 'yaw_speed'."""
        return self._yaw_speed

    @yaw_speed.setter
    def yaw_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_speed = value

    @builtins.property
    def pitch_speed(self):
        """Message field 'pitch_speed'."""
        return self._pitch_speed

    @pitch_speed.setter
    def pitch_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_speed = value

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
    def shoot_flag(self):
        """Message field 'shoot_flag'."""
        return self._shoot_flag

    @shoot_flag.setter
    def shoot_flag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shoot_flag' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'shoot_flag' field must be an unsigned integer in [0, 255]"
        self._shoot_flag = value

    @builtins.property
    def shoot_id(self):
        """Message field 'shoot_id'."""
        return self._shoot_id

    @shoot_id.setter
    def shoot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shoot_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'shoot_id' field must be an unsigned integer in [0, 255]"
        self._shoot_id = value

    @builtins.property
    def enemy_id(self):
        """Message field 'enemy_id'."""
        return self._enemy_id

    @enemy_id.setter
    def enemy_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_id' field must be an unsigned integer in [0, 255]"
        self._enemy_id = value
