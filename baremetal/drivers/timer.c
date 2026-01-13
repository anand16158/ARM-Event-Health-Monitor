#include "timer.h"
#include "core/interrupt.h"

#define TIMER_BASE    0x40000000
#define TIMER_IRQ_NUM 10

volatile uint32_t *TIMER_CTRL = (uint32_t *)(TIMER_BASE + 0x00);
volatile uint32_t *TIMER_CLR  = (uint32_t *)(TIMER_BASE + 0x0C);

void timer_init(uint32_t ticks)
{
    *TIMER_CTRL = ticks | (1 << 7); // enable timer + irq
}

void timer_irq_handler(void)
{
    *TIMER_CLR = 1;
    irq_dispatch(TIMER_IRQ_NUM);
}
