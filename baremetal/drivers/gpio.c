#include "gpio.h"
#include "core/interrupt.h"

#define GPIO_BASE      0x40020000
#define GPIO_IRQ_NUM   5

volatile uint32_t *GPIO_INT_STATUS = (uint32_t *)(GPIO_BASE + 0x10);
volatile uint32_t *GPIO_INT_CLEAR  = (uint32_t *)(GPIO_BASE + 0x14);

void gpio_init(void)
{
    // GPIO configuration would go here
}

void gpio_enable_irq(uint8_t pin)
{
    (void)pin;
    // Enable GPIO interrupt for pin
}

void gpio_irq_handler(void)
{
    *GPIO_INT_CLEAR = *GPIO_INT_STATUS;
    irq_dispatch(GPIO_IRQ_NUM);
}
