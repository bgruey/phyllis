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
    struct timespec* sleep_data = (struct  timespec*)calloc(1, sizeof(struct timespec));

    DancerState_t* dancer = initialize_dancer(
        1, 1, 128,
        "./data.csv"
    );

    startup_actions(dancer);

    fprintf(stderr, "Starting dancer loop.\n");
    while (1) {
        step_forward_buffer(dancer);
    }

    destroy_dancer(dancer);
    free(sleep_data);
    return 0;
}
