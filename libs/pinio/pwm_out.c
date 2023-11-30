#include <stdio.h>
#include "pinio.h"


void run_inverted_pwm_on_pin(PWMData_t* pwm_data, int* run_bool, uint8_t pin) {
    double sleep_high = pwm_data->sleep_high;
    fprintf(stderr, "Starting PWM with period %f\n", pwm_data->period_seconds);
    while (run_bool[0]) {
        // fprintf(stderr, "PWM for %f\n", sleep_high);
        write_pin_low(pin);
        sleep_via_double(sleep_high, &pwm_data->sleep_data.now);
        write_pin_high(pin);
        sleep_via_double(
            pwm_data->period_seconds - sleep_high,
            &pwm_data->sleep_data.now
        );
        // if (sleep_high != pwm_data->sleep_high)
        //     fprintf(stderr, "PWM: %f -> %f\n", sleep_high, pwm_data->sleep_high);

        sleep_high = pwm_data->sleep_high;
    }
    fprintf(stderr, "inverted wpm run_bool off.\n");
}


void run_pwm_on_pin(PWMData_t* pwm_data, int* run_bool, uint8_t pin) {
    double sleep_high = pwm_data->sleep_high;

    while (run_bool[0]) {
        write_pin_high(pin);
        sleep_via_double(sleep_high, &pwm_data->sleep_data.now);
        write_pin_low(pin);
        sleep_via_double(
            pwm_data->period_seconds - sleep_high,
            &pwm_data->sleep_data.now
        );
        sleep_high = pwm_data->sleep_high;
    }
}