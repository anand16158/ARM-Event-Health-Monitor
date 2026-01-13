#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>

void interrupt_init(void);
void irq_dispatch(uint32_t irq);

#endif
