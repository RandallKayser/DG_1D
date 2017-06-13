#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "legendre.h"

void get_legendre_polynomials(int max_order, double* coefficient_matrix) {
   for(int i=0; i<=2*(max_order+1); i++) {
      coefficient_matrix[i] = 0.0;
   }
   
   coefficient_matrix[0] = 1.0;
   coefficient_matrix[max_order+2] = 1.0;
   
   for(int i=1; i<=max_order; i++) {
      for(int j=0; j<=i+1; j++) {
         coefficient_matrix[(i+1)*(max_order+1)+j] = (double)
            (2.0*i+1.0)/(i+1.0)*coefficient_matrix[i*(max_order+1)+j-1] -
            i/(i+1.0)*coefficient_matrix[(i-1)*(max_order+1)+j];
      }
   }
}
