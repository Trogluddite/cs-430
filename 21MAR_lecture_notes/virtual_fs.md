# pickling
  * writing a datastructure including it's memory addresses would be silly
  * so we need to preserve data in some way
  * padding can caus problems
  * endianess can be a problem
  * dynamic datasturcutres may take some searching
# filesystems, OS perspective
  * unified file tree (independent of hardware)
    * demo changing files while they're open by some other process
  * open file table
  * multiple users may open a file at once
  * use count
  * lsof
  * inode
    - ls -i
    - reiserfs omits inode table
    - struct inod
    - vnodes in BSD
  * links to inodes and stat
  * loops in linking and symbolic links vs hard links
    - find with sympolic link loop
  * types and file
    - 'magic numbers'
  * `#!`
  * permissiosn & executions
  * mounting directories (sshfs, usb)
    - automount daemons
    - mounting in multiple places
