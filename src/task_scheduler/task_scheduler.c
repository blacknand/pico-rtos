#include <stdio.h>
#include "pico/stdlib.h"

/**
 *  Pico W microcontrollers use a GPIO on the WiFi chip for the LED,
 *  so when building for Pico W, CYW43_WL_GPIO_LED_PIN will be defined
 */
#ifndef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif


int pico_led_init(void) {
#if defined(PICO_DEFAULT_LED_PIN)
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
#elif defined(CYW43_WL_GPIO_LED_PIN)
    return cyw43_arch_init();
#endif
}


void pico_set_led(bool led_on) {
#if defined(PICO_DEFAULT_LED_PIN)
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#elif defined(CYW43_WL_GPIO_LED_PIN)
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
#endif
}


void flash_pico_led(void) {
    // Arrive at time 0
    int rc = pico_led_init();
    hard_assert(rc == PICO_OK);
    for (int i = 0; i < 10; i++) {
        pico_set_led(true);
        sleep_ms(LED_DELAY_MS);
        pico_set_led(false);
        sleep_ms(LED_DELAY_MS);
    }
    return;
}


void output_task1(void) {
    // Arrive at time 1
    printf("Hello from output_task1\n");
    sleep_ms(1000);
}


void output_task2(void) {
    // Arrive at time 2
    printf("Hello from output_task2\n");
    sleep_ms(1000);
}


void output_task3(void) {
    // Arrive at time 3
    printf("Hello from output_task3\n");
    sleep_ms(1000);
}


int main() {
    // init();             // CPU round robin scheduler initialisation
    flash_pico_led();
    output_task1();
    output_task2();
    output_task3();
}
