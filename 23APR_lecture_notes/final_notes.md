# kernel programming
 * Pointers, kmalloc, casting void* as other things, arrays, structures with pointers included, binary arithmetic, macros, stuff we've covered when talking about kernel modules
 * /proc including read and write functions
 * writing kernel modules
 * Generic OS topics like memory management, block devices, filesystems, process management
 * something from the FreeBSD driver demo (short answer)
 * what is the purpose of the ioctl system call?
 
# A few sample questions: 
* suppose a computer has 1gb of RAM and no swap space and two processes each call malloc and request 600mb. Both requests are granted. One process uses all 600mb. After this the other process attempts to use all 600mb. What will happen next?
* why do many filesystmes use a B-tree to store information that must be looked up? (instead of a binary tree)
* why does page cache have two levels?
* Declare a function that takes a opinter to a function as an argument. The argument should be a pointer to a function that takes an integer and a float, and returns a char 
* iniside a proc_read function, 4000 characters are available to return to the user in an array called buf. "Buf" is declared as a char buff[8000], but only contains 4000 characters. The user will call the function with less than 4000 characters available in the userspace bufffer. Complete the following function to return no mor than the user vuffer can hold.

//check ubuf_size;
// copy_to_user vs. memcpy -- which should you use?
ssize_t proc_read(struct file *filp, char *user_buffer, size_t ubuf_size, loff_t *offp){
  copy_to_user(user_buffer, buf, 4000); // oh no! this will overfill the user's buffer!
  return 4000;
}

up to ten pages of two-sided 8.5x11 notes
Final: Thursday May 9 at 9AM
