#define UART0_BASE 0x20201000

void uart_init() {
    volatile unsigned int *uart0_cr = (unsigned int *)(UART0_BASE + 0x30);
    volatile unsigned int *uart0_ibrd = (unsigned int *)(UART0_BASE + 0x24);
    volatile unsigned int *uart0_fbrd = (unsigned int *)(UART0_BASE + 0x28);
    volatile unsigned int *uart0_lcrh = (unsigned int *)(UART0_BASE + 0x2C);
    volatile unsigned int *uart0_icr = (unsigned int *)(UART0_BASE + 0x44);

    *uart0_cr = 0x00000000;

    *uart0_icr = 0x7FF;

    *uart0_ibrd = 1;  
    *uart0_fbrd = 40;

    *uart0_lcrh = 0x70;

    *uart0_cr = 0x301;
}

void uart_putc(char c) {
    volatile unsigned int *uart0_fr = (unsigned int *)(UART0_BASE + 0x18);
    volatile unsigned int *uart0_dr = (unsigned int *)(UART0_BASE + 0x00);

    while (*uart0_fr & 0x20) {}
    *uart0_dr = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

void kernel_main() {
    uart_init();
    uart_puts("Hello, Kernel World!\n");
    
    while (1) {
    }
}
