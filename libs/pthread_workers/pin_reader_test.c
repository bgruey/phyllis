/*
    pin_reader_test.c

    Description for pin_reader_test.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include <stdio.h>
#include <stdlib.h>
#include "pthread_workers.h"
#include "signal_processors.h"


void read_data_file(
    const char* filename, 
    double** buf, 
    size_t* buf_len, 
    size_t* sample_rate
) {
    FILE* f = fopen(filename, "rb");

    fread(sample_rate, __SIZEOF_INT__, 1, f);
    fread(buf_len, __SIZEOF_INT__, 1, f);
    
    buf[0] = (double*)malloc(buf_len[0] * __SIZEOF_DOUBLE__);
    fread(buf[0], __SIZEOF_INT__, buf_len[0], f);
    fclose(f);
    printf("Read %ld at %ld sample rate from %s\n", *buf_len, *sample_rate, filename);
}


void* pin_reader_test(void* args_in) {
    /*
        pin data:
            0: time
            1: kick signal (abs by python preprocess)
            2: snare signal ( ... )
            3: kick shunted integral
            4: snare shinted integral
            5: kick Schmidt Trigger
            6: snare Schmidt Trigger
    */

    PinThreadData_t* args = (PinThreadData_t*)args_in;

    SchmidtTrigger_T* schmidt_data = schmtt_init(0.4, 0.1, 0.4, 0.05);

    double* kick_data = NULL;
    size_t kick_len, kick_sample_rate;

    double* snare_data = NULL;
    size_t snare_len, snare_sample_rate;

    read_data_file("pukkin-kick.dat", &kick_data, &kick_len, &kick_sample_rate);
    read_data_file("pukkin-snare.dat", &snare_data, &snare_len, &snare_sample_rate);
    
    if (kick_sample_rate != snare_sample_rate) {
        fprintf(
            stderr, 
            "ERROR: Sample rates mismatch in kick/snare (%ld/%ld)data!\n",
            kick_sample_rate,
            snare_sample_rate
        );
        exit(EXIT_FAILURE);
    }
    if (kick_len != snare_len) {
        fprintf(
            stderr, 
            "ERROR: Data length mismatch in kick/snare (%ld/%ld)data!\n",
            kick_len,
            snare_len
        );
        exit(EXIT_FAILURE);
    }

    args->dt = 1.0 / ((double)kick_sample_rate);
    double t = 0.0;
    double* prev_pins = (double*)calloc(args->num_pins, sizeof(double));
    
    TimeWFloat_t sleep_data;
    sleep_data.start_time_seconds = get_now_seconds(&sleep_data);
    double early_s;

    int data_i, pin_i;
    for (data_i = 0; data_i < kick_len; data_i++) {
        if (args->run_bool != 1)
            break;

        early_s = t - (sleep_data.seconds - sleep_data.start_time_seconds);
        if (early_s > 0)
            sleep_via_double(early_s, &sleep_data.now);

        args->pins[0] = (t += args->dt);
        args->pins[1] = kick_data[data_i];
        args->pins[2] = snare_data[data_i];

        for (pin_i = 0; pin_i < args->num_pins; pin_i++)
            prev_pins[pin_i] = args->pins[pin_i];


        for (pin_i = 0; pin_i < 2; pin_i++) {
            args->pins[3 + pin_i] = shunted_integrator(
                prev_pins[pin_i + 1],
                args->pins[pin_i + 1],
                args->dt,
                100.0  // lambda
            );
            args->pins[5 + pin_i] = schmtt_calculate(
                args->pins[3 + pin_i],
                schmidt_data
            );
        }

    }

    args->run_bool = 0;

    return NULL;
}
