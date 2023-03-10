#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
   
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world!");

static int __inithello_init(void)
{
    printk(KERN_INFO "Hello world\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye world\n");
}

module_init(hello_init);
module_exit(hello_exit);
