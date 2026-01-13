#ifndef WATCHDOG_H
#define WATCHDOG_H

void watchdog_init(uint32_t timeout);
void watchdog_kick(void);
void watchdog_irq_handler(void);

#endif
