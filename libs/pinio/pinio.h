#ifndef _PINIO_H
#define _PINIO_H

#include <bcm2835.h>

#include "utils.h"

#define PIN4 RPI_GPIO_P1_07

#define GPIO_HIGH 0x1
#define GPIO_LOW 0x0


typedef struct {
    // Input values
    double period_seconds;
    double duty_cycle_percent;

    // Calculated values
    double sleep_high;
    double sleep_low;

    TimeWFloat_t sleep_data;
} PWMData_t;


void write_pin_high(uint8_t pin);


void write_pin_low(uint8_t pin);


void run_pwm_on_pin(PWMData_t* pwm_data, int* run_bool, uint8_t pin);

#endif
