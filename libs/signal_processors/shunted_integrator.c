#include <math.h>


double shunted_integrator(double y_int, double y, double dt, double lambda) {
    return y_int*exp(-lambda * dt) + 3 * lambda * y * dt;
}
