/*
    pin_writer.c

    Description for pin_writer.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pinio.h"
#include "pthread_workers.h"
#include "utils.h"


void* pin_writer(void* args_in) {
    PinThreadData_t* args = (PinThreadData_t*)args_in;
    PWMData_t* pwm_data = args->writer_pwm_data;

    // initalize bcm2835 library and set pin4 to output.
    if(!bcm2835_init()) {
        fprintf(stderr, "Failed to init bcm2835.\n");
        exit(EXIT_FAILURE);
    }
    bcm2835_gpio_fsel(PIN4, BCM2835_GPIO_FSEL_OUTP);

    run_inverted_pwm_on_pin(pwm_data, &args->run_bool, PIN4);
    
    return NULL;
}