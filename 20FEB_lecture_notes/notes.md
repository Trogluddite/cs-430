more red-black trees 

# this is 25% space efficient for single-byte nodes ... but making it more efficient might not be worthwhile
struct keycount_node { 
    struct rb_node node;    // 24 bytes, on x86-64, 0 bytes into struct
    int keycode;            // 4 bytes, 24 bytes into struct 
    unsigned int keycount;  // 4bytes, 28 bytes into the struct
};

# snprintf
* takes char*, size, and format
* look at man pages for family of printf functions

# note about kmalloc
* looking up definition in headers 
* somewhere in slab.h (allocator) we'll define __kmalloc -- used to get a type of memory, not size (??)
* we have a problem in kb_notifier in that we expect the type when we call it -- we may work past that with the offset, or we require the pointer to be the first item
