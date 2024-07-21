#define UART0_BASE 0x101f1000

void uart_init() {
    volatile unsigned int *uart0_cr = (unsigned int *)(UART0_BASE + 0x30);
    *uart0_cr = 0x00000003; 
}

void uart_putc(char c) {
    volatile unsigned int *uart0_dr = (unsigned int *)(UART0_BASE + 0x00);
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
