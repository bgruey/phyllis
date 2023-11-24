#include "now.h"


double get_now_seconds(TimeWFloat_t* now) {
    clock_gettime(CLOCK_MONOTONIC, &now->now);

    now->seconds = now->now.tv_sec + now->now.tv_nsec * TO_NS_DECIMAL - now->start_time_seconds;
    return now->seconds;
}


double get_now_seconds_fraction(TimeWFloat_t* now, double max_window) {
    /*
        Fractional part of the current second, within the max_window.

        
    */
    get_now_seconds(now);
    return get_seconds_fraction(now, max_window);
}


double get_seconds_fraction(TimeWFloat_t* now, double max_window) {
    double local_seconds = now->seconds - (long)now->seconds;
    while (local_seconds > max_window)
        local_seconds -= max_window;
    return local_seconds;
}
