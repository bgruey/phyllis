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
    int i;
    for (i = 0; i < 5; i++) {
        dancer->read_pins[0] = 0.0015;
        sleep_via_double(0.75, dancer->sleep_data);
        dancer->read_pins[0] = 0.002;
        sleep_via_double(0.75, dancer->sleep_data);
        dancer->read_pins[0] = 0.001;
        sleep_via_double(0.75, dancer->sleep_data);
    }
}