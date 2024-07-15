/*
    now.h

    Description for now.h

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#ifndef _NOW_H
#define _NOW_H

// For clock macros in clock_gettime in time.h
#define _POSIX_C_SOURCE 200809L
#include <time.h>

#define TO_NS_DECIMAL 1.0e-9

/**
 * @brief Wrapper for timespec (time.h) plus seconds and start_time_seconds doubles.
 * 
 */
typedef struct TimeWFloat_t {
    struct timespec now;
    double seconds;
    double start_time_seconds;
} TimeWFloat_t;


/**
 * @brief Update the now object with current time and return seconds.
 * 
 * @param now 
 * @return double 
 */
double get_now_seconds(TimeWFloat_t* now);


/**
 * @brief Update the now object and return get_seconds_fraction.
 * 
 * @param now 
 * @param max_window 
 * @return double 
 */
double get_now_seconds_fraction(TimeWFloat_t* now, double max_window);


/**
 * @brief Return the fractional part of now within the max_window.
 * 
 * @note So if the max_window is 0.5 and the current seconds is 0.75,
 *   the result will be 0.25. max_window should be seconds per beat,
 *   a value less than 1.
 *
 * @param now 
 * @param max_window 
 * @return double 
 */
double get_seconds_fraction(TimeWFloat_t* now, double max_window);

#endif
