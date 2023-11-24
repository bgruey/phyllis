/*
    simple_filters.c

    Description for simple_filters.c

    Author: github.com/bgruey

    License:
        GNU AFFERO GENERAL PUBLIC LICENSE
        Version 3, 19 November 2007
*/
#include "math.h"


double low_pass_filter(double x, double y, double alpha) {
    return alpha * x + (1.0 - alpha) * y;
}
