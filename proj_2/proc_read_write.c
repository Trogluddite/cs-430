#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>

#define PROC_FILE_NAME "testfile"

#define PROCFS_MAX_SIZE		1024
static char procfs_buffer[PROCFS_MAX_SIZE];
static unsigned long procfs_buffer_size = 0;

char text[] = "There was an armadillo which had a lot of money to invest.  Gold, stocks, property, and bitcoin were all too high!";

ssize_t read_simple(struct file *filp, char *buf, size_t count, loff_t *offp ) 
{
	char* readspot = text + *offp;
	size_t readlen = strlen(readspot) > count? count:strlen(readspot);
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
    return -EFAULT;
  }
  printk("proc_write just ran! count = %lu, sizeof(loff_t) = %lu, *ppos= %llu\n", count, sizeof(loff_t), *ppos);
  strncpy(text, buffer, count);
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
