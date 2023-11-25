#include <stdio.h>
#include "pinio.h"


void calc_sleep_times(PWMData_t* pwmd) {
    pwmd->sleep_high = pwmd->period_seconds * pwmd->duty_cycle_percent;
    pwmd->sleep_low = pwmd->period_seconds - pwmd->sleep_high;
}


void run_pwm_on_pin(PWMData_t* pwm_data, int* run_bool, uint8_t pin) {
    calc_sleep_times(pwm_data);
    printf("Starting pwd loop on %d\n", run_bool[0]);
    while (run_bool[0]) {
        write_pin_high(pin);
        sleep_via_double(pwm_data->sleep_high, &pwm_data->sleep_data.now);
        write_pin_low(pin);
        sleep_via_double(pwm_data->sleep_low, &pwm_data->sleep_data.now);
        calc_sleep_times(pwm_data);
    }
    printf("Ended pwd loop on %d\n", run_bool[0]);
}