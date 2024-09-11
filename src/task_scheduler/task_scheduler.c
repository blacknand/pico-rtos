#include <stdio.h>
#include "pico/stdlib.h"


#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif


void pico_led_init(void) {
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}


void flash_pico_led(void) {
    // Arrive at time 0
    for (int i = 0; i < 10; i++) {
        pico_set_led(true);
        sleep_ms(LED_DELAY_MS);
        pico_set_led(false);
        sleep_ms(LED_DELAY_MS);
    }
}


void output_task1(void) {
    // Arrive at time 1
    print("Hello from output_task1\n");
    sleep_ms(1000);
}


void output_task2(void) {
    // Arrive at time 2
    print("Hello from output_task2\n");
    sleep_ms(1000);
}


void output_task3(void) {
    // Arrive at time 3
    print("Hello from output_task3\n");
    sleep_ms(1000);
}





int main() {

}
