// ✅ Working LED Blink on NUCLEO-F411RE (onboard LED = PA5)

#include <stdint.h>

#define RCC_AHB1ENR   (*(volatile uint32_t*)0x40023830)
#define GPIOA_MODER   (*(volatile uint32_t*)0x40020000)
#define GPIOA_ODR     (*(volatile uint32_t*)0x40020014)

static void delay_ms(uint32_t ms) {
    for (volatile uint32_t i = 0; i < (ms * 8000); i++) {
        __asm__("nop");
    }
}

int main(void) {
    // Enable clock for GPIOA
    RCC_AHB1ENR |= (1 << 0);

    // Configure PA5 as output (01)
    GPIOA_MODER &= ~(3 << (5 * 2)); // Clear mode bits
    GPIOA_MODER |=  (1 << (5 * 2)); // Set output mode

    while (1) {
        GPIOA_ODR ^= (1 << 5);  // Toggle LED
        delay_ms(1000);         // 1 second delay
    }
}

