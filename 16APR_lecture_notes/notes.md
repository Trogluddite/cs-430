# hole file
* if we lseek we might leave empty space between chunks of data we care about
* size on disk on right may be fairly small (8k in demo)
* transfering the file, it may end up taking up much more space (1.1m in our case)
  * nginx, SCP, rsync
* the file ends up existing on multiple sectors -- making the hole 'real'
# considerations
* holes are fine in XFS, NTFS; copying across partitions doesn't seem to change size
# blockIO layer
* lwn.net/Articles/736534
* device nodes are at same level of abstraction as filesystem (device nodes aren't part of the FS)
# * I/O Schedulers
* linux has a history as an OS for cheap hardware
* goal is to minimize head movement; reduce interleaving read/writes and moving read head (particularly spinny disks)
## I/O elevator metaphor
  * usually elevators don't reverse direction unless there are no requests further on
  * linus elevator, default up to 2.4, replaced in 2.6
  * requests are checked against all others for merging 
  * merge onto front or back depending
  * if no merging, add to a sorted point in queue
  * if no good sorted point, add to the end of the queue
  * if tail is old, new requests go at the end regardless
    * this prevents infinite starvations
## Deadline scheduler
* writes can starve reads
* so requests have an expiration time (500ms for read, 5 seconds for write)
* extra queue for each, sorted by time
* if a request expires in the extra queue, it is serviced
* generally, services are requested by expiration time
## Anticapatory scheduler
* heavy write load may perform badly on deadline scheduler (writes might expire in the queue)
* wait a few ms after performing read before resuming write
  * in case the application needs to read something else
* keeps track of process access patterns to determine wait; we'll usually read from the same places for the same process
## completely fair scheduler
* not necessarily completely fair to processes
* each process has a queue
* merging is performed across queues (duplicates, references)
* round-robin with selection of a few items from each queues
* generally works well with non-pathological cases
* was intended for multimedia originally -- processes sort of self-soft into the same area, and requests tend to be linear/predictable
* was default when textbook was published; replaced by budget fair queuein
## Noop IO scheduler
* merge requests, but don't do ANY sorting
* simpler than others
* intended for flash memory only (no head position)
# Page cache
## page cache caches pages of file in main memory
* might be in L1, L2, L3, (remember, it's hardware thing)
* remember: milli, micro, nano
## Read cahce: 
* simple, if it's read it's in the cache
## write caching:
* simple: if you update the block device, invalidate the cache
* write-through: update cache, then schedule a write to the block device later
* write-back: update the cache, and mark the update cache as 'dirty'; update the block device when we get around to it
* (write means put a write in the block device's queue)
## Cache Eviction:
* nothing voluntarily leaves the cache; we don't remove anything unless we need the space
* ideal strategy: remove page that is least used when we need space in the future
* Linux uses two lists: active and inactive 
  * 1 access: into inactive
  * more access will move pages into the active queue
  * if active queue is to obig, pages move to inactive
  * (by reference here, not actual copying)
# O_DIRECT
* flag for file handle
* tries to minimize cache effects of IO to and from a file; may be useful if an application does its own caching
  * this might still be a problem because other apps using the same file can't use the OS-level caching
# O_SYNC
* write ops will complete according to the requirements of syncronizedIO
