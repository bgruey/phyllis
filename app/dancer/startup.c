/*
    startup.c

    Description for timestep.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include "dancer.h"

void startup_actions(DancerState_t* dancer) {
    fprintf(stderr, "Startup Actions.\n");
    int i;
    for (i = 0; i < 5; i++) {
        fprintf(stderr, "Start loop %d\n", i);
        dancer->pin_writer_thread_data->writer_pwm_data->sleep_high = 0.0015;
        sleep_via_double(1, &dancer->sleep_data->now);
        dancer->pin_writer_thread_data->writer_pwm_data->sleep_high = 0.001;
        sleep_via_double(1, &dancer->sleep_data->now);
        dancer->pin_writer_thread_data->writer_pwm_data->sleep_high = 0.002;
        sleep_via_double(1, &dancer->sleep_data->now);
    }
}