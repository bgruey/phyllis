#ifndef _SIGNAL_PROCESSORS_H
#define _SIGNAL_PROCESSORS_H

#include <stdio.h>
#include "shunted_integrator.h"

double low_pass_filter(double x_i, double y_im1, double alpha);

#endif
