# ARM Event & Health Monitor

This project implements a bare-metal ARM firmware with custom linker script,
startup code, and vector table. It demonstrates ARM boot flow, memory
initialization, and prepares the system for interrupt-driven event handling.

## Features
- Custom linker script
- ARM startup assembly
- Vector table and exception handling
- Bare-metal main loop

## Architecture
- ARM Cortex-M
- No HAL
- No framework
- Production-style layout


## How to Test

make
sudo insmod arm_event_driver.ko
cat /proc/arm_health
sudo rmmod arm_event_driver

Expected output:

ARM Event Health Monitor
GPIO_IRQ: 12
TIMER_IRQ: 1024
LAST_RESET: WATCHDOG

