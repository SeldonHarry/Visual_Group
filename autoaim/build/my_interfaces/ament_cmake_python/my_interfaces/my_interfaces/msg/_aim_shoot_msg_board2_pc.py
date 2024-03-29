# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_interfaces:msg/AimShootMsgBoard2PC.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AimShootMsgBoard2PC(type):
    """Metaclass of message 'AimShootMsgBoard2PC'."""

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
                'my_interfaces.msg.AimShootMsgBoard2PC')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__aim_shoot_msg_board2_pc
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__aim_shoot_msg_board2_pc
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__aim_shoot_msg_board2_pc
            cls._TYPE_SUPPORT = module.type_support_msg__msg__aim_shoot_msg_board2_pc
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__aim_shoot_msg_board2_pc

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AimShootMsgBoard2PC(metaclass=Metaclass_AimShootMsgBoard2PC):
    """Message class 'AimShootMsgBoard2PC'."""

    __slots__ = [
        '_self_id',
        '_yaw_angle',
        '_pitch_angle',
        '_yaw_speed',
        '_pitch_speed',
        '_yaw_offset',
        '_pitch_offset',
        '_dist',
        '_shoot_speed',
        '_shoot_delay',
        '_shoot_id_fdb',
        '_is_big_energy',
        '_chassis_vx',
        '_chassis_vy',
    ]

    _fields_and_field_types = {
        'self_id': 'uint8',
        'yaw_angle': 'float',
        'pitch_angle': 'float',
        'yaw_speed': 'float',
        'pitch_speed': 'float',
        'yaw_offset': 'float',
        'pitch_offset': 'float',
        'dist': 'float',
        'shoot_speed': 'float',
        'shoot_delay': 'uint8',
        'shoot_id_fdb': 'uint32',
        'is_big_energy': 'uint8',
        'chassis_vx': 'float',
        'chassis_vy': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.self_id = kwargs.get('self_id', int())
        self.yaw_angle = kwargs.get('yaw_angle', float())
        self.pitch_angle = kwargs.get('pitch_angle', float())
        self.yaw_speed = kwargs.get('yaw_speed', float())
        self.pitch_speed = kwargs.get('pitch_speed', float())
        self.yaw_offset = kwargs.get('yaw_offset', float())
        self.pitch_offset = kwargs.get('pitch_offset', float())
        self.dist = kwargs.get('dist', float())
        self.shoot_speed = kwargs.get('shoot_speed', float())
        self.shoot_delay = kwargs.get('shoot_delay', int())
        self.shoot_id_fdb = kwargs.get('shoot_id_fdb', int())
        self.is_big_energy = kwargs.get('is_big_energy', int())
        self.chassis_vx = kwargs.get('chassis_vx', float())
        self.chassis_vy = kwargs.get('chassis_vy', float())

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
        if self.self_id != other.self_id:
            return False
        if self.yaw_angle != other.yaw_angle:
            return False
        if self.pitch_angle != other.pitch_angle:
            return False
        if self.yaw_speed != other.yaw_speed:
            return False
        if self.pitch_speed != other.pitch_speed:
            return False
        if self.yaw_offset != other.yaw_offset:
            return False
        if self.pitch_offset != other.pitch_offset:
            return False
        if self.dist != other.dist:
            return False
        if self.shoot_speed != other.shoot_speed:
            return False
        if self.shoot_delay != other.shoot_delay:
            return False
        if self.shoot_id_fdb != other.shoot_id_fdb:
            return False
        if self.is_big_energy != other.is_big_energy:
            return False
        if self.chassis_vx != other.chassis_vx:
            return False
        if self.chassis_vy != other.chassis_vy:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def self_id(self):
        """Message field 'self_id'."""
        return self._self_id

    @self_id.setter
    def self_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'self_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'self_id' field must be an unsigned integer in [0, 255]"
        self._self_id = value

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
    def yaw_offset(self):
        """Message field 'yaw_offset'."""
        return self._yaw_offset

    @yaw_offset.setter
    def yaw_offset(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_offset' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_offset' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_offset = value

    @builtins.property
    def pitch_offset(self):
        """Message field 'pitch_offset'."""
        return self._pitch_offset

    @pitch_offset.setter
    def pitch_offset(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_offset' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_offset' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_offset = value

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
    def shoot_speed(self):
        """Message field 'shoot_speed'."""
        return self._shoot_speed

    @shoot_speed.setter
    def shoot_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shoot_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'shoot_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._shoot_speed = value

    @builtins.property
    def shoot_delay(self):
        """Message field 'shoot_delay'."""
        return self._shoot_delay

    @shoot_delay.setter
    def shoot_delay(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shoot_delay' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'shoot_delay' field must be an unsigned integer in [0, 255]"
        self._shoot_delay = value

    @builtins.property
    def shoot_id_fdb(self):
        """Message field 'shoot_id_fdb'."""
        return self._shoot_id_fdb

    @shoot_id_fdb.setter
    def shoot_id_fdb(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'shoot_id_fdb' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'shoot_id_fdb' field must be an unsigned integer in [0, 4294967295]"
        self._shoot_id_fdb = value

    @builtins.property
    def is_big_energy(self):
        """Message field 'is_big_energy'."""
        return self._is_big_energy

    @is_big_energy.setter
    def is_big_energy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'is_big_energy' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'is_big_energy' field must be an unsigned integer in [0, 255]"
        self._is_big_energy = value

    @builtins.property
    def chassis_vx(self):
        """Message field 'chassis_vx'."""
        return self._chassis_vx

    @chassis_vx.setter
    def chassis_vx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_vx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'chassis_vx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._chassis_vx = value

    @builtins.property
    def chassis_vy(self):
        """Message field 'chassis_vy'."""
        return self._chassis_vy

    @chassis_vy.setter
    def chassis_vy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_vy' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'chassis_vy' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._chassis_vy = value
