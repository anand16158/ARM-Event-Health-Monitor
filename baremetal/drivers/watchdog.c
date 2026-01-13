#include "watchdog.h"
#include "core/interrupt.h"

#define WDT_BASE        0x40001000
#define WDT_IRQ_NUM     15

volatile uint32_t *WDT_CTRL = (uint32_t *)(WDT_BASE + 0x00);
volatile uint32_t *WDT_CLR  = (uint32_t *)(WDT_BASE + 0x0C);

void watchdog_init(uint32_t timeout)
{
    *WDT_CTRL = timeout | (1 << 0);
}

void watchdog_kick(void)
{
    *WDT_CLR = 0xABCD;
}

void watchdog_irq_handler(void)
{
    irq_dispatch(WDT_IRQ_NUM);
}
