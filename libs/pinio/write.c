#include "pinio.h"


void write_pin_high(uint8_t pin) {
    bcm2835_gpio_write(pin, GPIO_HIGH);
}


void write_pin_low(uint8_t pin) {
    bcm2835_gpio_write(pin, GPIO_LOW);
}