#include <stdio.h>
#include "pinio.h"




void run_pwm_on_pin(PWMData_t* pwm_data, int* run_bool, uint8_t pin) {
    calc_sleep_times(pwm_data);

    while (run_bool[0]) {
        write_pin_high(pin);
        sleep_via_double(pwm_data->sleep_high, &pwm_data->sleep_data.now);
        write_pin_low(pin);
        sleep_via_double(
            pwm_data->period_seconds - pwm_data->sleep_high,
            &pwm_data->sleep_data.now
        );
    }
}