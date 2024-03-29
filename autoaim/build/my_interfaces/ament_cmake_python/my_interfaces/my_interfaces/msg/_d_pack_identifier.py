# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_interfaces:msg/DPackIdentifier.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DPackIdentifier(type):
    """Metaclass of message 'DPackIdentifier'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MIMIPC_COMM_MAX_SIZE': 64,
        'MINIPC_COMM_SOF': 35,
        'PC2BOARD': 0,
        'BOARD2PC': 16,
        'GENERAL': 0,
        'AIM_SHOOT': 1,
        'NAVIGATION': 2,
        'GAME_STATUS': 3,
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
                'my_interfaces.msg.DPackIdentifier')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__d_pack_identifier
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__d_pack_identifier
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__d_pack_identifier
            cls._TYPE_SUPPORT = module.type_support_msg__msg__d_pack_identifier
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__d_pack_identifier

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MIMIPC_COMM_MAX_SIZE': cls.__constants['MIMIPC_COMM_MAX_SIZE'],
            'MINIPC_COMM_SOF': cls.__constants['MINIPC_COMM_SOF'],
            'PC2BOARD': cls.__constants['PC2BOARD'],
            'BOARD2PC': cls.__constants['BOARD2PC'],
            'GENERAL': cls.__constants['GENERAL'],
            'AIM_SHOOT': cls.__constants['AIM_SHOOT'],
            'NAVIGATION': cls.__constants['NAVIGATION'],
            'GAME_STATUS': cls.__constants['GAME_STATUS'],
        }

    @property
    def MIMIPC_COMM_MAX_SIZE(self):
        """Message constant 'MIMIPC_COMM_MAX_SIZE'."""
        return Metaclass_DPackIdentifier.__constants['MIMIPC_COMM_MAX_SIZE']

    @property
    def MINIPC_COMM_SOF(self):
        """Message constant 'MINIPC_COMM_SOF'."""
        return Metaclass_DPackIdentifier.__constants['MINIPC_COMM_SOF']

    @property
    def PC2BOARD(self):
        """Message constant 'PC2BOARD'."""
        return Metaclass_DPackIdentifier.__constants['PC2BOARD']

    @property
    def BOARD2PC(self):
        """Message constant 'BOARD2PC'."""
        return Metaclass_DPackIdentifier.__constants['BOARD2PC']

    @property
    def GENERAL(self):
        """Message constant 'GENERAL'."""
        return Metaclass_DPackIdentifier.__constants['GENERAL']

    @property
    def AIM_SHOOT(self):
        """Message constant 'AIM_SHOOT'."""
        return Metaclass_DPackIdentifier.__constants['AIM_SHOOT']

    @property
    def NAVIGATION(self):
        """Message constant 'NAVIGATION'."""
        return Metaclass_DPackIdentifier.__constants['NAVIGATION']

    @property
    def GAME_STATUS(self):
        """Message constant 'GAME_STATUS'."""
        return Metaclass_DPackIdentifier.__constants['GAME_STATUS']


class DPackIdentifier(metaclass=Metaclass_DPackIdentifier):
    """
    Message class 'DPackIdentifier'.

    Constants:
      MIMIPC_COMM_MAX_SIZE
      MINIPC_COMM_SOF
      PC2BOARD
      BOARD2PC
      GENERAL
      AIM_SHOOT
      NAVIGATION
      GAME_STATUS
    """

    __slots__ = [
        '_frame_id',
    ]

    _fields_and_field_types = {
        'frame_id': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.frame_id = kwargs.get('frame_id', int())

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
        if self.frame_id != other.frame_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def frame_id(self):
        """Message field 'frame_id'."""
        return self._frame_id

    @frame_id.setter
    def frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'frame_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'frame_id' field must be an unsigned integer in [0, 255]"
        self._frame_id = value
