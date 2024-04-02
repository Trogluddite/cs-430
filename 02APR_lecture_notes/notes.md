# starting on Filesystems
  * People generally want to be able to store and retrieve files
  * fast finding and reading and writing and creating and deleting, seeking maybe
    * they don't necessarily need to be fast at the same things, depending on the application
    * E.G., one filesystem might optimize for seeking in large files; another might optimize for handling many small files
  * don't waste space
    * finding and not wasting space tend to be at odds with each other
    * e.g., tail-packing ... put a small file in the the unused end of a sector, which is good space optimization
  * maintenence not required or it's easy to do
  * don't lose files when power is lost
  * files can't be recovered from a bad disk
  * doesn't hurt your drive -- E.G., solid-state drives that write to specific sectors consistently, like indexes
  * low CPU overhead (though, not usually at the expense of speed)
  * supports metadata like ACL's, modified date, permissions
  * Resizing demo.
  
# Common fetures of filesystems
  * Journaling
    * keep a record of changes as they're ocurring
    * useful if we lose power; the journal lets us check to see what we're doing
    * useful for speeding up consistency checks
    * ext2 does not journal (more likely to lose data), ext3 did (slower, but safer)
    * usually has extra disk access -- the journal has to be written somewhere
  * B-Trees
    * build a structure so that a node takes up a sector on disk
    * speeds up retrieval
  * parallel support (XFS, etc)
  * Expansion / resizing
  * Aging
    * organization can become chaotic over time
    * consider fragmentation in a mostly full disk
  * Max file sizes, volume size, number of files, etc

# Brief summary of some common filesystems:
* FAT
  * simple to implement, easy on floppy disks
  * no ACLs or permissions
  * cluster size limits total size -- FAT12 32MB (or 256MB for 64kb clusters)
  * progeniter of the 8.3 filenaming scheme
* EXT2/3/4
  * no specific file naming restrictions
  * datestamps limited to 1 second
  * uses POSIX ACL's
  * uses Unix permissions
  * no transparent compression/encryption
  * ext3 introduces journaling, online filesystem growth
    * extends ext2 (ext3 is fully compatible with ext2)
  * ext4 is a more complete revision, not quite so backwards compatible
    * introduces b-tree indexes, faster access over linear search
* reiserFS / Reiser4 --> btrfs
  * introduced in 2.4 kernel
  * great seek time, especially for small files
  * had a lot of fragmentation; recovery was difficult
  * Reiser4 was going to succeed Reiser, sponsored by DARPA, but then Hans Reiser murdered his wife.
  * BTRFS is a successor -- everything gets thrown into the b-tree
  * ns time resolution
* jfs (IBM)
* xfs (SGI)
* ntfs (Microsoft)
* hfs (Apple
