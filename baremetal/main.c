#include <stdint.h>

volatile uint32_t heartbeat = 0;

int main(void)
{
    while (1)
    {
        heartbeat++;
        for (volatile uint32_t i = 0; i < 100000; i++);
    }
}
