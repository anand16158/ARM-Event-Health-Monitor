#include <linux/fs.h>
#include <linux/uaccess.h>

#define ARM_IOC_MAGIC   'A'
#define ARM_IOC_FAULT   _IO(ARM_IOC_MAGIC, 1)

long arm_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch (cmd) {
    case ARM_IOC_FAULT:
        pr_warn("ARM: Fault injection requested\n");
        break;
    default:
        return -EINVAL;
    }
    return 0;
}
