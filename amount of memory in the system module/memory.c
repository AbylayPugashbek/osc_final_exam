#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abylay");
MODULE_VERSION("0.1");

static int __init memory_init(void) {
    struct sysinfo si;
    si_meminfo(&si);
    printk(KERN_INFO "Total memory: %lu KB\n", si.totalram/1024);
    return 0;
}

static void __exit memory_exit(void) {
    printk(KERN_INFO "Goodbye, memory!\n");
}

module_init(memory_init);
module_exit(memory_exit);
