/*
    pin_reader.c

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


void* pin_reader(void* args_in) {
    uint8_t pin = RPI_GPIO_P1_07;
    PinThreadData_t* args = (PinThreadData_t*)args_in;

    fprintf(stderr, "Starting pin_reader for pin %d.\n", pin);
    // initalize bcm2835 library
    if(!bcm2835_init()) {
        fprintf(stderr, "Failed to init bcm2835.\n");
        exit(EXIT_FAILURE);
    }
    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(pin, BCM2835_GPIO_PUD_UP);

    double last_val = 700;
    while (args->run_bool) {
        args->pins[0] = (double)bcm2835_gpio_lev(pin);

        // if (1)  // args->pins[0] != last_val )
        fprintf(stderr, "READ: %f\n", args->pins[0]);
        
        last_val = args->pins[0];
    }
    
    return NULL;
}