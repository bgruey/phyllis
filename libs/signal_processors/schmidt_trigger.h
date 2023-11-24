/*
    schmidt_trigger.h

    Description for schmidt_trigger.h

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#ifndef _SCHMIDT_TRIGGER_H
#define _SCHMIDT_TRIGGER_H

#include <stdlib.h>


/**
 * @brief Definition of the Schmidt Trigger:
 *        https://en.wikipedia.org/wiki/Schmitt_trigger#Non-inverting_Schmitt_trigger
 * 
 */
typedef struct {
    int high; //  boolean, stores state
    double threshold_high;
    double threshold_low;
    double value_high;
    double value_low;
} SchmidtTrigger_T;


/**
 * @brief Initialize data for the Schmidt Trigger.
 * 
 * @param threshold_high 
 * @param threshold_low 
 * @param value_high 
 * @param value_low 
 * @return SchmidtTrigger_T* 
 */
SchmidtTrigger_T* schmtt_init(
    double threshold_high,
    double threshold_low,
    double value_high,
    double value_low
);


/**
 * @brief Calculate Schmidt Trigger output with y input and state ts.
 * 
 * @param y 
 * @param ts 
 * @return double 
 */
double schmtt_calculate(double y, SchmidtTrigger_T* ts);


#endif
