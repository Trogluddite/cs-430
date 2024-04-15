# block devices
  ## block device vs. character device
  * block devices allow you to read or write data blocks of any size
  * character devices are serial
  * pseudo-devices appear as devices but aren't really (like /dev/null)
  * sometimes these definitions are somewhat muddy
  * Printers for example:
    * ASCII has stuff like carriage return/linefeed -- early printer devices would accept character device
    * but nowadays printing stuff like images means the printer has some buffer that takes data (neverminding it's a network device usually)
  # `dd`
    * disk writing tools
  # /dev conventions
  * pretend notes
  # mmap (c library)
  * map a piece of a block device from some particular file, making it feel kinda random accessy
  * linux programmer's manual, man map(2)
