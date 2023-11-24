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