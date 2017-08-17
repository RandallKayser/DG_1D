#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
#include "structs.h"
#include "par.h"
#include "init.h"

void main(void) {
   
   struct grid thegrid;
   struct parlist theparlist;
   struct legendrelist thelegendrelist;
    
   malloc_structs(&thegrid, &theparlist, &thelegendrelist);

   double *coefficients = thelegendrelist.coefficient_matrix;
   double *roots = thelegendrelist.root_matrix;
   double *weights = thelegendrelist.weight_matrix;
//   for(int i = 0; i<10; i++) {
//      printf("%f %f\n", i*2.0/9.0-1.0, evaluate_legendre_polynomial(i*2.0/9.0-1.0, 3, thegrid.spaceorder, coefficients));
//   }
   for(int i=0; i<thegrid.spaceorder; i++) {
      for(int j=0; j<thegrid.spaceorder; j++) {
         printf("%e ", roots[i*thegrid.spaceorder+j]);
      }
      printf("\n");
   }
//   print_pars(&thegrid, &theparlist);
/*   build_cells_uniform(&thegrid);
   project_init_conds(&thegrid, &theparlist, &thelegendrelist);
   print_cells(&thegrid);
*/
   

}
