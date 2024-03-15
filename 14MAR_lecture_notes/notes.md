# memory issues
* it's relatively easy to push a bunch of stack frames until we segfault
* for heap allocation it takes a little more work, but we can consume all of the system memory and force OOM-kill

# virtual memory
* A process in memory has a table with references to its own variables (virtual memory)
* the virtual memory can reference to either physical memory, or disk/storage
* linux systems usually have a disk part for swap space
* CPU's usually have an MMU that automatically translates virtual addresses to real addresses
  * 286 introduced protected memory; virtual memory concepts are older
* page tables
 * data structure used by VM system to store mappings between virtual addreses and physical addresses
 * pages aren't expected to be contiguous
 * translation: follows some algorithm to map address to page
 * page fault: could occur because of a segfault, could occur because the page has been moved to a backing store
   * in cases where it's on the backing store, it should be brought back into main memory
   * this isn't a systemcall! The hardware generates a page-fault, kicking us back into the kernel
   * kernel will send SIGSEGV (or maybe SIGBUS) depending on architecture in cases of segfault 
