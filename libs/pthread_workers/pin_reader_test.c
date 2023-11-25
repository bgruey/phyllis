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


size_t read_sample(
    FILE* kick_file,
    FILE* snare_file, 
    double* pins,
    double time
) {
    // current time
    pins[2] = time;

    // kick
    size_t nread = fread(&pins[0], __SIZEOF_DOUBLE__, 1, kick_file);
    if (nread != 1)
        return 0;

    // snare
    nread += fread(&pins[1], __SIZEOF_DOUBLE__, 1, snare_file);
    if (nread != 2)
        return 0;
    //printf("%f: %f, %f\n", pins[0], pins[1], pins[2]);
    return nread;
}


double get_timestep(FILE* kick, FILE* snare) {
    int kick_sample_rate, snare_sameple_rate;
    fread(&kick_sample_rate, __SIZEOF_INT__, 1, kick);
    fread(&snare_sameple_rate, __SIZEOF_INT__, 1, snare);
    if( kick_sample_rate != snare_sameple_rate) {
        fprintf(
            stderr, 
            "ERROR: Sample rates mismatch in kick/snare (%d/%d)data!\n",
            kick_sample_rate,
            snare_sameple_rate
        );
        exit(EXIT_FAILURE);
    }

    double dt = 1.0 / ((double)kick_sample_rate);
    printf("%f from %d, %d\n", dt, kick_sample_rate, snare_sameple_rate);
    return dt;
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
    int i = 0;
    PinThreadData_t* args = (PinThreadData_t*)args_in;
    double* prev_pins = (double*)calloc(args->num_pins, sizeof(double));

    FILE* kick_file = fopen("kick5k.dat", "rb");
    FILE* snare_file = fopen("snare5k.dat", "rb");

    SchmidtTrigger_T* schmidt_data = schmtt_init(0.4, 0.1, 0.4, 0.05);

    args->dt = get_timestep(kick_file, snare_file);
    double t = 0.0;
    
    size_t num_read = read_sample(kick_file, snare_file, args->pins, t);

    while (args->run_bool && num_read == 2) {
        pthread_mutex_lock(args->read_now_mutex);

        while(args->read_now[0] == 0 && args->run_bool)
            pthread_cond_wait(args->read_now_cond, args->read_now_mutex);

        for (i = 0; i < args->num_pins; i++)
            prev_pins[i] = args->pins[i];

        num_read = read_sample(
            kick_file, 
            snare_file, 
            args->pins, 
            t += args->dt
        );

        for (i = 0; i < args->num_pins; i++) {
            args->pins[3 + i] = shunted_integrator(
                prev_pins[i + 1],
                args->pins[i + 1],
                args->dt,
                100.0  // lambda
            );
            args->pins[5 + i] = schmtt_calculate(
                args->pins[3 + i],
                schmidt_data
            );
        }
        
        args->read_now[0] = 0;

        pthread_mutex_unlock(args->read_now_mutex);
        pthread_cond_signal(args->read_now_cond);
    }

    args->run_bool = 0;
    fclose(kick_file);
    fclose(snare_file);

    return NULL;
}
