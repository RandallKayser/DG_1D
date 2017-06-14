#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
int main(void) {
   int max_order=10;  
   double coefficient_matrix[(max_order+1)*(max_order+1)];
   double root_matrix[11*11];
   double weight_matrix[11*11];

   get_legendre_polynomials(max_order, coefficient_matrix);
   get_roots(root_matrix, max_order, coefficient_matrix);
   get_weights(weight_matrix, max_order, root_matrix, coefficient_matrix);

   for(int i=1; i<=max_order; i++) {
      for(int j=0; j<i-1; j++) {
         printf("%f ", weight_matrix[i*(max_order+1)+j]);
      }
      printf("%f\n", weight_matrix[i*(max_order+1)+i-1]);
   }
   double (*func)(double) = &myfunc;

   printf("%.15f\n", glq(func, -1, 1, 10, max_order, weight_matrix, root_matrix));
}
