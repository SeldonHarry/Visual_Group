# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_interfaces:msg/RobotStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotStatus(type):
    """Metaclass of message 'RobotStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'BLUE': 0,
        'RED': 1,
        'MANUAL': 0,
        'AUTOAIM': 1,
        'ANTITOP': 2,
        'ENERGY_HIT': 4,
        'ENERGY_DISTURB': 5,
        'NOT_RECEIVED': 8,
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
                'my_interfaces.msg.RobotStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'BLUE': cls.__constants['BLUE'],
            'RED': cls.__constants['RED'],
            'MANUAL': cls.__constants['MANUAL'],
            'AUTOAIM': cls.__constants['AUTOAIM'],
            'ANTITOP': cls.__constants['ANTITOP'],
            'ENERGY_HIT': cls.__constants['ENERGY_HIT'],
            'ENERGY_DISTURB': cls.__constants['ENERGY_DISTURB'],
            'NOT_RECEIVED': cls.__constants['NOT_RECEIVED'],
        }

    @property
    def BLUE(self):
        """Message constant 'BLUE'."""
        return Metaclass_RobotStatus.__constants['BLUE']

    @property
    def RED(self):
        """Message constant 'RED'."""
        return Metaclass_RobotStatus.__constants['RED']

    @property
    def MANUAL(self):
        """Message constant 'MANUAL'."""
        return Metaclass_RobotStatus.__constants['MANUAL']

    @property
    def AUTOAIM(self):
        """Message constant 'AUTOAIM'."""
        return Metaclass_RobotStatus.__constants['AUTOAIM']

    @property
    def ANTITOP(self):
        """Message constant 'ANTITOP'."""
        return Metaclass_RobotStatus.__constants['ANTITOP']

    @property
    def ENERGY_HIT(self):
        """Message constant 'ENERGY_HIT'."""
        return Metaclass_RobotStatus.__constants['ENERGY_HIT']

    @property
    def ENERGY_DISTURB(self):
        """Message constant 'ENERGY_DISTURB'."""
        return Metaclass_RobotStatus.__constants['ENERGY_DISTURB']

    @property
    def NOT_RECEIVED(self):
        """Message constant 'NOT_RECEIVED'."""
        return Metaclass_RobotStatus.__constants['NOT_RECEIVED']


class RobotStatus(metaclass=Metaclass_RobotStatus):
    """
    Message class 'RobotStatus'.

    Constants:
      BLUE
      RED
      MANUAL
      AUTOAIM
      ANTITOP
      ENERGY_HIT
      ENERGY_DISTURB
      NOT_RECEIVED
    """

    __slots__ = [
        '_bullet_speed',
        '_yaw_compensate',
        '_pitch_compensate',
        '_enemy_color',
        '_is_big_energy',
        '_program_mode',
        '_latency_cmd_to_fire',
        '_last_shoot_aim_id',
        '_laser_distance',
        '_lrc',
    ]

    _fields_and_field_types = {
        'bullet_speed': 'float',
        'yaw_compensate': 'float',
        'pitch_compensate': 'float',
        'enemy_color': 'uint8',
        'is_big_energy': 'uint8',
        'program_mode': 'uint8',
        'latency_cmd_to_fire': 'uint8',
        'last_shoot_aim_id': 'int32',
        'laser_distance': 'float',
        'lrc': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.bullet_speed = kwargs.get('bullet_speed', float())
        self.yaw_compensate = kwargs.get('yaw_compensate', float())
        self.pitch_compensate = kwargs.get('pitch_compensate', float())
        self.enemy_color = kwargs.get('enemy_color', int())
        self.is_big_energy = kwargs.get('is_big_energy', int())
        self.program_mode = kwargs.get('program_mode', int())
        self.latency_cmd_to_fire = kwargs.get('latency_cmd_to_fire', int())
        self.last_shoot_aim_id = kwargs.get('last_shoot_aim_id', int())
        self.laser_distance = kwargs.get('laser_distance', float())
        self.lrc = kwargs.get('lrc', int())

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
        if self.bullet_speed != other.bullet_speed:
            return False
        if self.yaw_compensate != other.yaw_compensate:
            return False
        if self.pitch_compensate != other.pitch_compensate:
            return False
        if self.enemy_color != other.enemy_color:
            return False
        if self.is_big_energy != other.is_big_energy:
            return False
        if self.program_mode != other.program_mode:
            return False
        if self.latency_cmd_to_fire != other.latency_cmd_to_fire:
            return False
        if self.last_shoot_aim_id != other.last_shoot_aim_id:
            return False
        if self.laser_distance != other.laser_distance:
            return False
        if self.lrc != other.lrc:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def bullet_speed(self):
        """Message field 'bullet_speed'."""
        return self._bullet_speed

    @bullet_speed.setter
    def bullet_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bullet_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bullet_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bullet_speed = value

    @builtins.property
    def yaw_compensate(self):
        """Message field 'yaw_compensate'."""
        return self._yaw_compensate

    @yaw_compensate.setter
    def yaw_compensate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_compensate' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_compensate' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_compensate = value

    @builtins.property
    def pitch_compensate(self):
        """Message field 'pitch_compensate'."""
        return self._pitch_compensate

    @pitch_compensate.setter
    def pitch_compensate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_compensate' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_compensate' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_compensate = value

    @builtins.property
    def enemy_color(self):
        """Message field 'enemy_color'."""
        return self._enemy_color

    @enemy_color.setter
    def enemy_color(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_color' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_color' field must be an unsigned integer in [0, 255]"
        self._enemy_color = value

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
    def program_mode(self):
        """Message field 'program_mode'."""
        return self._program_mode

    @program_mode.setter
    def program_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'program_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'program_mode' field must be an unsigned integer in [0, 255]"
        self._program_mode = value

    @builtins.property
    def latency_cmd_to_fire(self):
        """Message field 'latency_cmd_to_fire'."""
        return self._latency_cmd_to_fire

    @latency_cmd_to_fire.setter
    def latency_cmd_to_fire(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'latency_cmd_to_fire' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'latency_cmd_to_fire' field must be an unsigned integer in [0, 255]"
        self._latency_cmd_to_fire = value

    @builtins.property
    def last_shoot_aim_id(self):
        """Message field 'last_shoot_aim_id'."""
        return self._last_shoot_aim_id

    @last_shoot_aim_id.setter
    def last_shoot_aim_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_shoot_aim_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'last_shoot_aim_id' field must be an integer in [-2147483648, 2147483647]"
        self._last_shoot_aim_id = value

    @builtins.property
    def laser_distance(self):
        """Message field 'laser_distance'."""
        return self._laser_distance

    @laser_distance.setter
    def laser_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'laser_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'laser_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._laser_distance = value

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
