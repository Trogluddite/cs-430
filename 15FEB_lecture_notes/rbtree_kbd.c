#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/keyboard.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/slab.h>

#define PROC_FILE_NAME "kbd_demo"

struct keycount_node {
    struct rb_node node; // 24 bytes, on x86-64, 0 bytes into the struct
    int keycode;    // 4 bytes, 24 bytes into the struct
    unsigned int keycount; // 4 bytes, 28 bytes into the struct
};

struct rb_root root = RB_ROOT;

struct notifier_block nb;

ssize_t read_simple(struct file *filp,char *buf,size_t count,loff_t *offp ) 
{
    struct keycount_node *pos, *n;
    size_t sofar = 0;
    if(*offp)
        return 0;
    // kinda like for(auto *pos : rb_root) in C++11
    rbtree_postorder_for_each_entry_safe(pos, n, &root, node){
        sofar += snprintf(buf + sofar, count - sofar, "Keycode %d : %u\n", pos->keycode, pos->keycount);
    }
    *offp = sofar;
    return sofar;
}

struct proc_ops proc_fops = {
    proc_read: read_simple,
};

int kb_notifier_fn(struct notifier_block *nb, unsigned long action, void* data){
    struct keyboard_notifier_param *kp = (struct keyboard_notifier_param*)data;
    // search and insert if needed
    struct rb_node **new = &(root.rb_node), *parent = NULL;
    while(*new) {
        struct keycount_node *this = container_of(*new, struct keycount_node, node);  
        parent = *new;
        if(this->keycode == kp->value){ // We found it!
            this->keycount++;
            printk("Added to %d:%u\n", this->keycode, this->keycount);
            return 0;
        } else if(this->keycode < kp->value)
            new = &((*new)->rb_right);
        else
            new = &((*new)->rb_left);
    }
    {
        // This next bit adds a new node.  We'll have exited above if we found our node already in the tree
        struct keycount_node *new_node = kmalloc(sizeof(struct keycount_node), 1);
        new_node->keycode = kp->value;
        new_node->keycount = 1;
        rb_link_node(&new_node->node, parent, new);
        rb_insert_color(&new_node->node, &root);
        printk("Added new node %d:%u\n", new_node->keycode, new_node->keycount);
    }
    return 0;
}

int init (void) {
    nb.notifier_call = kb_notifier_fn;
    register_keyboard_notifier(&nb);
    proc_create(PROC_FILE_NAME,0,NULL,&proc_fops);
    return 0;
}

void cleanup(void) {
    struct keycount_node *pos, *n;

    unregister_keyboard_notifier(&nb);
    remove_proc_entry(PROC_FILE_NAME,NULL);
    
    printk("Beginning Tree Deallocation\n");
    rbtree_postorder_for_each_entry_safe(pos, n, &root, node){
        printk("Keycode %d : %u\n", pos->keycode, pos->keycount);
        kfree(pos);
    }
}

MODULE_LICENSE("GPL"); 
module_init(init);
module_exit(cleanup);


