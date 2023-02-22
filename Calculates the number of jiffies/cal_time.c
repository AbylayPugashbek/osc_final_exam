#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abylay");
MODULE_DESCRIPTION("Kernel module to show timings for specific boundaries of time");

static int __init my_module_init(void)
{
    unsigned long jiffies_per_hour = HZ * 3600;
    unsigned long jiffies_per_day = HZ * 86400;
    unsigned long jiffies_per_week = jiffies_per_day * 7;

    unsigned long jiffies_in_last_hour = jiffies - (60 * jiffies_per_hour);
    unsigned long jiffies_in_last_day = jiffies - (24 * jiffies_per_day);
    unsigned long jiffies_in_last_week = jiffies - (7 * jiffies_per_week);

    printk(KERN_INFO "Jiffies in last hour: %lu\n", jiffies_in_last_hour);
    printk(KERN_INFO "Jiffies in last day: %lu\n", jiffies_in_last_day);
    printk(KERN_INFO "Jiffies in last week: %lu\n", jiffies_in_last_week);

    return 0;
}

static void __exit my_module_exit(void)
{
    printk(KERN_INFO "Exiting my_module\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
