#include "math.h"


double low_pass_filter(double x, double y, double alpha) {
    return alpha * x + (1.0 - alpha) * y;
}
