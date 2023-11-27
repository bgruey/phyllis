/*
    shunted_integrator.c

    Description for shunted_integrator.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include <math.h>


double shunted_integrator(double y_int, double y, double dt, double lambda) {
    return y_int*exp(-lambda * dt) + y * dt;
}
