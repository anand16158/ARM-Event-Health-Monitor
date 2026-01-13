#include "interrupt.h"
#include "event_buffer.h"
#include "drivers/gpio.h"
#include "drivers/timer.h"
#include "drivers/watchdog.h"

#define IRQ_GPIO     5
#define IRQ_TIMER    10
#define IRQ_WATCHDOG 15

void interrupt_init(void)
{
    event_buffer_init();
}

void irq_dispatch(uint32_t irq)
{
    switch (irq) {
    case IRQ_GPIO:
        event_log(EVENT_SRC_GPIO, 1);
        break;

    case IRQ_TIMER:
        event_log(EVENT_SRC_TIMER, 0);
        break;

    case IRQ_WATCHDOG:
        event_log(EVENT_SRC_WATCHDOG, 2);
        break;

    default:
        event_log(EVENT_SRC_FAULT, 3);
        break;
    }
}
