/*
    simple_filters.h

    Description for simple_filters.h

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#ifndef _SIMPLE_FILTERS_H
#define _SIMPLE_FILTERS_H


/**
 * @brief Simple low pass filter
 * 
 * @note Implemented from https://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization
 * 
 * @param x - current input of time series
 * @param y - previous output of filter
 * @param alpha - defined by cutoff frequency
 * @return double 
 */
double low_pass_filter(double x, double y, double alpha);

#endif