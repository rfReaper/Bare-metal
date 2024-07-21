.section .text
.global _start
_start:
    ldr sp, =stack_top
    bl kernel_main
hang:
    b hang

.section .bss
.balign 4
stack:
    .skip 1024
stack_top:
