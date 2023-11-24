#ifndef _SCHMIDT_TRIGGER_H
#define _SCHMIDT_TRIGGER_H

#include <stdlib.h>
#include <stdio.h>


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
 * @brief Calculate Schmidt Trigger output with y input.
 * 
 * @param y 
 * @param ts 
 * @return double 
 */
double schmtt_calculate(double y, SchmidtTrigger_T* ts);


#endif
