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
#include "../utils/utils.h"
#include "pthread_workers.h"


void* pin_writer(void* args_in) {
    PinThreadData_t* args = (PinThreadData_t*)args_in;

    struct timespec* sleep_data = (struct timespec*)calloc(1, sizeof(struct timespec));
    
    while(args->run_bool)
        sleep_via_double(
            0.5,
            sleep_data
        );
    
    return NULL;
}