#include <stdint.h>

extern void _start(void);

void Default_Handler(void);
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ_Handler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".vectors")))
void (*vector_table[])(void) = {
    (void (*)(void))(&_estack),
    _start,
    Default_Handler,        // NMI
    HardFault_Handler,      // HardFault
    Default_Handler,        // MemManage
    Default_Handler,        // BusFault
    Default_Handler,        // UsageFault
    0, 0, 0, 0,
    Default_Handler,        // SVCall
    Default_Handler,        // Debug
    0,
    Default_Handler,        // PendSV
    Default_Handler,        // SysTick
    IRQ_Handler             // IRQ
};

void Default_Handler(void)
{
    while (1);
}
