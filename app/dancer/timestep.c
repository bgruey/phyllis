/*
    timestep.c

    Description for timestep.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include <math.h>
#include "dancer.h"
#include "pinio.h"

#define LOW_PASS_F 50.0
#define M_PI 3.14159265358979323846


void set_line_buffer_with_state(DancerState_t* dancer) {
    double* state = get_next_state(dancer);
    sprintf(
        dancer->line_buffer,
        "%.13e,%.5e,%.5e,%.5e,%.5e,%.5e,%.5e\n",
        state[0],
        state[1],
        state[2],
        state[3],
        state[4],
        state[5],
        state[6]
    );
}


void step_forward_buffer(DancerState_t* dancer) {
    /*
        Current means the time step that was last completed.
        Next means the time step we are currently calculating.

        This ensures that the read/write threads can continue to access
        the current state and break synchronicity with this calculation
        thread.

        Mutex in testing:
            - In order to ensure this happens serially, we lock for all calculations
            - in practice with streaming we will only want to lock for the read from the pins

        Perhaps double ptr the read pins passed to the reader thread so it actually maps
        to the current read pin state directly?
    */

    dancer->now->start_time_seconds = get_now_seconds(dancer->now);

    dancer->next_buffer_i = (dancer->buffer_i + 1) % dancer->len_buffer;
    dancer->read_now = 1;
    // pthread_cond_signal(&dancer->read_now_cond);
    // pthread_mutex_lock(&dancer->read_now_mutex);
    // while(dancer->read_now == 1 && dancer->pin_reader_thread_data->run_bool)
    //     pthread_cond_wait(&dancer->read_now_cond, &dancer->read_now_mutex);

    dancer->line_buffer[0] = '\0';
    dancer->len_line = 0;

    for (dancer->read_pin_i = 0; dancer->read_pin_i < dancer->num_read_pins; dancer->read_pin_i++) {
        set_next_read_pin_state(
            dancer,
            dancer->read_pins[dancer->read_pin_i]
        );
    }
    //fprintf(stderr, "Timestep read pin: %f\n", dancer->read_pins[0]);
    if(dancer->read_pins[0]) {  // Schmidt Trigger signal is 0.4 for high.
        dancer->pin_writer_thread_data->writer_pwm_data->sleep_high = 0.0015;
        // printf("Triggering gpio high!\n");
    }
    else
        dancer->pin_writer_thread_data->writer_pwm_data->sleep_high = 0.0015;

    // set_line_buffer_with_state(dancer);
    // // printf("%s\n", dancer->line_buffer);
    // fprintf(
    //     dancer->outfile,
    //     "%s\n",
    //     dancer->line_buffer
    // );

    dancer->buffer_i = dancer->next_buffer_i;
    // pthread_mutex_unlock(&dancer->read_now_mutex);  
}
