/*
    sleep.h

    Library of sleep functions.

    Author: github.com/bgruey

    Livesnse: GNU AFFERO GENERAL PUBLIC LICENSE
                Version 3, 19 November 2007
*/
#ifndef _SLEEP_H
#define _SLEEP_H

#include <time.h>
#include <errno.h>    


/**
 * @brief Sleep for sleep_s seconds.
 * 
 * Adapted from https://stackoverflow.com/a/1157217.
 *
 * @param sleep_s 
 * @param ts 
 * @return int 
 */
int sleep_via_double(double sleep_s, struct timespec* ts);

#endif
