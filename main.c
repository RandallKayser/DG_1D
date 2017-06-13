#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
int main(void) {
    double coefficient_matrix[11*12];
    int max_order=10;

    get_legendre_polynomials(max_order, coefficient_matrix);

    for(int i = 0; i<=max_order; i++) {
       printf("%f %f %f %f %f %f %f %f %f %f %f\n", coefficient_matrix[i*11+0], coefficient_matrix[i*11+1], coefficient_matrix[i*11+2], coefficient_matrix[i*11+3], coefficient_matrix[i*11+4], coefficient_matrix[i*11+5], coefficient_matrix[i*11+6], coefficient_matrix[i*11+7], coefficient_matrix[i*11+8], coefficient_matrix[i*11+9], coefficient_matrix[i*11+10]);
    }
    
}
