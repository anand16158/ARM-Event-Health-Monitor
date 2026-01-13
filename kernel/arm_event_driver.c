#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define PROC_NAME "arm_health"

static struct proc_dir_entry *proc_entry;

static int arm_health_show(struct seq_file *m, void *v)
{
    seq_printf(m, "ARM Event Health Monitor\n");
    seq_printf(m, "GPIO_IRQ: %d\n", 12);
    seq_printf(m, "TIMER_IRQ: %d\n", 1024);
    seq_printf(m, "LAST_RESET: WATCHDOG\n");
    return 0;
}

static int arm_health_open(struct inode *inode, struct file *file)
{
    return single_open(file, arm_health_show, NULL);
}

static const struct proc_ops proc_fops = {
    .proc_open    = arm_health_open,
    .proc_read    = seq_read,
    .proc_lseek   = seq_lseek,
    .proc_release = single_release,
};

static int __init arm_event_init(void)
{
    proc_entry = proc_create(PROC_NAME, 0444, NULL, &proc_fops);
    if (!proc_entry)
        return -ENOMEM;

    pr_info("ARM Event Driver loaded\n");
    return 0;
}

static void __exit arm_event_exit(void)
{
    proc_remove(proc_entry);
    pr_info("ARM Event Driver unloaded\n");
}

module_init(arm_event_init);
module_exit(arm_event_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anand Kumar");
MODULE_DESCRIPTION("ARM Event & Health Monitor Kernel Module");
