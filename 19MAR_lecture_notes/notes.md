# Memory management
* Textbook chapter 12
  * textbook simplifies some things
# Pages
* Memory is organized into pages -- 4kb on 32bit usually, 8kb on 64-bit usually
  * but this is a setting; it can vary
  * each page struct consumes a bit of memory (about 40bytes, per text)
  * (struct page)
# Memory zones
* Linux has four
  * ZONE_DMA -- pages for direct memory access
  * ZONE_DMA32 -- like zone dma but only accessible by 32 bit devices
  * ZONE_NORMAL -- normal, regularly mapped pates 
  * ZONE_HIGHMEMORY -- not permanantly mapped to kernel address space
# allocating pages
* kmalloc gets contiguous pages space directly in the kernel memory space
* vmalloc -- same but not guaranteed to be contiguous in kernel space (are *virtually* contiguous)pages 5
*
