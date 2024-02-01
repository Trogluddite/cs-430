#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/proc_fs.h>
#include<linux/sched.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/slab.h>
#include <linux/ctype.h>

#define PROC_FILE_NAME "testfile"
#define MAX_TEXTLEN 1024

unsigned char *text;

ssize_t read_simple(struct file *filp, char *buf, size_t count, loff_t *offp ) 
{	
	register size_t len = strlen(text);
	size_t copylen = len - *offp;
	if(copylen > count)
		copylen = count;
	if(*offp == len)
		return 0;
	raw_copy_to_user(buf, text + *offp, copylen);
	*offp += copylen;
	return copylen;
}

ssize_t write_simple(struct file *filp,const char *buf,size_t count,loff_t *offp)
{

	size_t length = strlen(text);
	unsigned char *i = text;
	printk("Write was called, with a buffer containing %s, *offp = %lld\n", buf, *offp);
	strncpy(text + *offp, buf, MAX_TEXTLEN  - *offp);
	for(; i < text + length; i++)
		if(islower(*i)){
			*i += 13;
			if(*i > 'z')
				*i -= 26;
		} else if(isupper(*i)){
			*i += 13;
			if(*i > 'Z')
				*i -= 26;

		}
	return count;	
}

struct file_operations proc_fops = {
	read: read_simple,
	write: write_simple
};

int proc_init (void) {
	printk("We're in the kernel!\n");
	text = kmalloc(MAX_TEXTLEN, GFP_KERNEL);
	proc_create(PROC_FILE_NAME,0,NULL,&proc_fops);
	return 0;
}

void proc_cleanup(void) {
	kfree(text);
	remove_proc_entry(PROC_FILE_NAME,NULL);
}

MODULE_LICENSE("GPL"); 
module_init(proc_init);
module_exit(proc_cleanup);
