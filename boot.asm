/* boot.asm */

/* Entry point of our kernel */
global _start

section .text
_start:
    /* Set up stack pointer */
    mov esp, stack_space

    /* Call our kernel main function */
    call kernel_main

    /* Hang the CPU */
    cli
    hlt

section .bss
    /* Define space for stack */
    stack_space resb 0x1000
