#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
#include "grid.h"
#include "par.h"
int main(void) {
   int max_order=19;  
   long double coefficient_matrix[(max_order+1)*(max_order+2)];
   double root_matrix[(max_order+1)*(max_order+1)];
   double weight_matrix[(max_order+1)*(max_order+1)];
   struct grid thegrid;
   struct parlist theparlist;
   struct legendrelist thelegendrelist;

   init_structs(&thegrid, &theparlist, &thelegendrelist);

   
/*
   get_legendre_polynomials(max_order, coefficient_matrix);
   get_roots(root_matrix, max_order, coefficient_matrix);
   normalize_polynomials(max_order, coefficient_matrix);
   get_weights(weight_matrix, max_order, root_matrix, coefficient_matrix);  
*/
   char file[] = "parfiles/in.par";

   read_pars(&thegrid, &theparlist, file);
   print_pars(&thegrid, &theparlist);
}
