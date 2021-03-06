# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from intera_core_msgs/IODeviceConfiguration.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy
import intera_core_msgs.msg

class IODeviceConfiguration(genpy.Message):
  _md5sum = "6757fad6217033498191470cb08f1674"
  _type = "intera_core_msgs/IODeviceConfiguration"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """## IO Device Configuration
time time                             # configuration command timestamp
string commanded                      # configuration command JSON
string upgraded                       # configuration command JSON, upgraded to current schema revision
IOComponentConfiguration   device     # instantiated device configuration
IOComponentConfiguration[] ports      # instantiated port configurations
IOComponentConfiguration[] signals    # instantiated signal configurations

================================================================================
MSG: intera_core_msgs/IOComponentConfiguration
## IO Component configuration data
string name                           # component name
string config                         # component configuration JSON
"""
  __slots__ = ['time','commanded','upgraded','device','ports','signals']
  _slot_types = ['time','string','string','intera_core_msgs/IOComponentConfiguration','intera_core_msgs/IOComponentConfiguration[]','intera_core_msgs/IOComponentConfiguration[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       time,commanded,upgraded,device,ports,signals

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(IODeviceConfiguration, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.time is None:
        self.time = genpy.Time()
      if self.commanded is None:
        self.commanded = ''
      if self.upgraded is None:
        self.upgraded = ''
      if self.device is None:
        self.device = intera_core_msgs.msg.IOComponentConfiguration()
      if self.ports is None:
        self.ports = []
      if self.signals is None:
        self.signals = []
    else:
      self.time = genpy.Time()
      self.commanded = ''
      self.upgraded = ''
      self.device = intera_core_msgs.msg.IOComponentConfiguration()
      self.ports = []
      self.signals = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2I().pack(_x.time.secs, _x.time.nsecs))
      _x = self.commanded
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.upgraded
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.device.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.device.config
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.ports)
      buff.write(_struct_I.pack(length))
      for val1 in self.ports:
        _x = val1.name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1.config
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.signals)
      buff.write(_struct_I.pack(length))
      for val1 in self.signals:
        _x = val1.name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1.config
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.time is None:
        self.time = genpy.Time()
      if self.device is None:
        self.device = intera_core_msgs.msg.IOComponentConfiguration()
      if self.ports is None:
        self.ports = None
      if self.signals is None:
        self.signals = None
      end = 0
      _x = self
      start = end
      end += 8
      (_x.time.secs, _x.time.nsecs,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.commanded = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.commanded = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.upgraded = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.upgraded = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.device.name = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.device.name = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.device.config = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.device.config = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.ports = []
      for i in range(0, length):
        val1 = intera_core_msgs.msg.IOComponentConfiguration()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.name = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.name = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.config = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.config = str[start:end]
        self.ports.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.signals = []
      for i in range(0, length):
        val1 = intera_core_msgs.msg.IOComponentConfiguration()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.name = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.name = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.config = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.config = str[start:end]
        self.signals.append(val1)
      self.time.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2I().pack(_x.time.secs, _x.time.nsecs))
      _x = self.commanded
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.upgraded
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.device.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.device.config
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.ports)
      buff.write(_struct_I.pack(length))
      for val1 in self.ports:
        _x = val1.name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1.config
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.signals)
      buff.write(_struct_I.pack(length))
      for val1 in self.signals:
        _x = val1.name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1.config
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.time is None:
        self.time = genpy.Time()
      if self.device is None:
        self.device = intera_core_msgs.msg.IOComponentConfiguration()
      if self.ports is None:
        self.ports = None
      if self.signals is None:
        self.signals = None
      end = 0
      _x = self
      start = end
      end += 8
      (_x.time.secs, _x.time.nsecs,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.commanded = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.commanded = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.upgraded = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.upgraded = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.device.name = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.device.name = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.device.config = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.device.config = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.ports = []
      for i in range(0, length):
        val1 = intera_core_msgs.msg.IOComponentConfiguration()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.name = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.name = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.config = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.config = str[start:end]
        self.ports.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.signals = []
      for i in range(0, length):
        val1 = intera_core_msgs.msg.IOComponentConfiguration()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.name = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.name = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.config = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.config = str[start:end]
        self.signals.append(val1)
      self.time.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
