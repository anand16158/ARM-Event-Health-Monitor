#include <linux/netlink.h>
#include <net/sock.h>

#define NETLINK_ARM_EVENT 31

static struct sock *nl_sock;

static void arm_nl_recv(struct sk_buff *skb)
{
    pr_info("ARM Netlink message received\n");
}

int arm_netlink_init(void)
{
    struct netlink_kernel_cfg cfg = {
        .input = arm_nl_recv,
    };

    nl_sock = netlink_kernel_create(&init_net, NETLINK_ARM_EVENT, &cfg);
    if (!nl_sock)
        return -ENOMEM;

    return 0;
}

void arm_netlink_exit(void)
{
    netlink_kernel_release(nl_sock);
}
