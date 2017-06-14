#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
int main(void) {
   int max_order=10;  
   double coefficient_matrix[(max_order+1)*(max_order+1)];
   double root_matrix[11*11];

   get_legendre_polynomials(max_order, coefficient_matrix);
   get_roots(root_matrix, max_order, coefficient_matrix);

   for(int i = 0; i<=max_order; i++) {
      printf("%f %f %f %f %f %f %f %f %f %f %f\n", root_matrix[i*(max_order+1)+0], root_matrix[i*(max_order+1)+1], root_matrix[i*(max_order+1)+2], root_matrix[i*(max_order+1)+3], root_matrix[i*(max_order+1)+4], root_matrix[i*(max_order+1)+5], root_matrix[i*(max_order+1)+6], root_matrix[i*(max_order+1)+7], root_matrix[i*(max_order+1)+8], root_matrix[i*(max_order+1)+9], root_matrix[i*(max_order+1)+10]);
      printf("%f %f %f %f %f %f %f %f %f %f %f\n", coefficient_matrix[i*(max_order+1)+0], coefficient_matrix[i*(max_order+1)+1], coefficient_matrix[i*(max_order+1)+2], coefficient_matrix[i*(max_order+1)+3], coefficient_matrix[i*(max_order+1)+4], coefficient_matrix[i*(max_order+1)+5], coefficient_matrix[i*(max_order+1)+6], coefficient_matrix[i*(max_order+1)+7], coefficient_matrix[i*(max_order+1)+8], coefficient_matrix[i*(max_order+1)+9], coefficient_matrix[i*(max_order+1)+10]);

   }
}
