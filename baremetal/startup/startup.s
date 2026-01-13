.syntax unified
.cpu cortex-m3
.thumb

.global _start

.extern main
.extern _estack
.extern _sdata
.extern _edata
.extern _sbss
.extern _ebss

_start:
    ldr sp, =_estack

    /* Copy .data from flash to RAM */
    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata
copy_data:
    cmp r0, r1
    ittt lt
    ldrlt r3, [r2], #4
    strlt r3, [r0], #4
    blt copy_data

    /* Zero .bss */
    ldr r0, =_sbss
    ldr r1, =_ebss
zero_bss:
    cmp r0, r1
    it lt
    strlt r3, [r0], #4
    blt zero_bss

    bl main

hang:
    b hang
