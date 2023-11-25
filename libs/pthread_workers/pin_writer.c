/*
    pin_writer.c

    Description for pin_writer.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include <stdlib.h>
#include <time.h>

#include "pinio.h"
#include "pthread_workers.h"
#include "utils.h"


void* pin_writer(void* args_in) {
    PinThreadData_t* args = (PinThreadData_t*)args_in;
    PWMData_t* pwm_data = args->writer_pwm_data;

    pwm_data->period_seconds = 0.020;
    pwm_data->duty_cycle_percent = 0.25;

    run_pwm_on_pin(pwm_data, PIN4);
    
    return NULL;
}