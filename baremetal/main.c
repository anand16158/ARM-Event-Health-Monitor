#include "core/interrupt.h"
#include "core/event_buffer.h"
#include "drivers/gpio.h"
#include "drivers/timer.h"
#include "drivers/watchdog.h"

int main(void)
{
    interrupt_init();

    gpio_init();
    gpio_enable_irq(0);

    timer_init(1000);
    watchdog_init(5000);

    arm_event_t evt;

    while (1) {
        watchdog_kick();

        if (event_read(&evt) == 0) {
            // Event consumed
            (void)evt;
        }
    }
}
