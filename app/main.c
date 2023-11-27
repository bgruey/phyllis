/*
    main.c

    Description for main.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "dancer/dancer.h"
#include "sleep.h"

int main(int argc, char** argv) {
    int num_points = 30000001;
    struct timespec* sleep_data = (struct  timespec*)calloc(1, sizeof(struct timespec));
    system("mpg321 pukkin-drum-and-bass.mp3 &");
    /*
        In testing, channel definitions:
            0: time
            1: kick
            2: snare

        To do:
            - Locked state at the end, need to fix that
            - Build integrator with resistor shunt
            - Build python plotter instead of libreoffice calc
    */
    DancerState_t* dancer = initialize_dancer(
        7, 2, 5,
        "./data.csv"
    );

    int i = 0;
    pthread_mutex_lock(&dancer->read_now_mutex);
    while(dancer->read_now == 1 && dancer->pin_reader_thread_data->run_bool)
        pthread_cond_wait(&dancer->read_now_cond, &dancer->read_now_mutex);
    
    while (dancer->pin_reader_thread_data->run_bool && i < num_points) {
        step_forward_buffer(dancer);

        // sleep_via_double(0.0001, sleep_data);
        if ((i % 10000) == 0)
            printf("%d: now\n", i);
        i += 1;
    }


    destroy_dancer(dancer);
    free(sleep_data);
    return 0;
}
