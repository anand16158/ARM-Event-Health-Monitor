#include "core/interrupt.h"
#include "core/event_buffer.h"

int main(void)
{
    interrupt_init();

    arm_event_t evt;

    while (1) {
        if (event_read(&evt) == 0) {
            // Placeholder for debug / LED / trace
            (void)evt;
        }
    }
}
