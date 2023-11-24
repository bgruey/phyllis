#ifndef _SHUNTED_INTEGRATOR_H
#define _SHUNTED_INTEGRATOR_H


/**
 * @brief Step forward y_int in a shunted integrator.
 * 
 * @note General idea:
 *       https://en.wikipedia.org/wiki/Op_amp_integrator#Practical_circuit
 * 
 * @param y_int 
 * @param y 
 * @param dt 
 * @param lambda - Technically tied to R, C values,
 *                  but used with heuristic values ~100 for audio signals. 
 * @return double 
 */
double shunted_integrator(double y_int, double y, double dt, double lambda);

#endif