#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void timer_init(uint32_t ticks);
void timer_irq_handler(void);

#endif
