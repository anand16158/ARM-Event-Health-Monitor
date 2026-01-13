#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

void gpio_init(void);
void gpio_enable_irq(uint8_t pin);
void gpio_irq_handler(void);

#endif
