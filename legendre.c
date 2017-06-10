#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

double get_Legendre_coefficient(int degree, int coef);
double *Legendre_init(struct grid *thegrid, double *coefficient_list);
double *get_LGL_zeroes_weights(struct grid *thegrid, double *coefficient_list, double *zero_list);