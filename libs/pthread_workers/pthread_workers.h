/*
    pthread_workers.h

    Description for pthread_workers.h

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#ifndef _PTHREAD_WORKERS_H
#define _PTHREAD_WORKERS_H

#include <pthread.h>


typedef struct {
    unsigned short num_pins;
    double* pins;
    int run_bool;
    pthread_t thread;
    pthread_mutex_t* read_now_mutex;
    pthread_cond_t* read_now_cond;
    int* read_now;
    double dt; // timestep for reader in testing.
} PinThreadData_t;


// void* pin_reader(void* args_in);
void* pin_reader_test(void* args_in);
void* pin_writer(void* args_in);

int launch_pin_thread(
    pthread_attr_t* attr,
    PinThreadData_t* pin_reader_thread_data,
    void* (*thread_target)(void *)
);

#endif
