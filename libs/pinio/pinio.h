#ifndef _PINIO_H
#define _PINIO_H

#include <bcm2835.h>

#define PIN4 RPI_GPIO_P1_07

#define GPIO_HIGH 0x1
#define GPIO_LOW 0x0


void write_pin_high(uint8_t pin);


void write_pin_low(uint8_t pin);

#endif
