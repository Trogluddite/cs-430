#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>

#define PROC_FILE_NAME "testfile"

#define PROCFS_MAX_SIZE		1024
static char procfs_buffer[PROCFS_MAX_SIZE];
static unsigned long procfs_buffer_size = 0;

char text[] = "There was an armadillo which had a lot of money to invest.  Gold, stocks, property, and bitcoin were all too high!";
char inbuff[PROCFS_MAX_SIZE] = "L0";

ssize_t read_simple(struct file *filp, char *buf, size_t count, loff_t *offp ) 
{
	char* readspot = text + *offp;
	size_t readlen = strlen(readspot) > count ? count : strlen(readspot);
	printk("proc_read just ran!  count = %lu, sizeof(loff_t) = %lu, *offp = %llu\n", count, sizeof(loff_t), *offp);	
	if(*offp >= strlen(text))
			return 0;
	strncpy(buf, readspot, count);
	*offp += readlen;
	return readlen;
}

ssize_t write_simple(struct file *file, const char *buffer,
                 size_t count, loff_t *ppos)
{
  procfs_buffer_size = count;
  if (procfs_buffer_size > PROCFS_MAX_SIZE) {
    procfs_buffer_size = PROCFS_MAX_SIZE;
  }

  if (copy_from_user(procfs_buffer, buffer, procfs_buffer_size) ){
    printk("copy_from_user failed with input buffer of size %lu", procfs_buffer_size);
    return -EFAULT;
  }
  strncpy(inbuff, buffer, count);

  if(count > 3){
    printk("Invalid control sequence, expected input of no more than 2 characters but got %s", inbuff);
    return -EINVAL;
  }
  else if( inbuff[0] != 'L' && inbuff[0] != 'D'){
    printk("Invalid control sequence, expected first character of input to be L or D but got %s", inbuff);
    return -EINVAL;
  }
  else if( ((char)inbuff[1] - '0') > 7 || ((char)inbuff[1] - '0') < 0){
    printk(
      "Invalid control sequence, second character of input to be a number in the range 0-7 but input was %s",
      inbuff
    );
    return -EINVAL;

  }
  return procfs_buffer_size;
}

struct proc_ops proc_fops = {
	proc_read: read_simple,
	proc_write: write_simple
};

int proc_init (void) {
	printk("We're in the kernel!\n");
	proc_create(PROC_FILE_NAME,0,NULL,&proc_fops);
	return 0;
}

void proc_cleanup(void) {
	remove_proc_entry(PROC_FILE_NAME,NULL);
}

MODULE_LICENSE("GPL"); 
module_init(proc_init);
module_exit(proc_cleanup);
