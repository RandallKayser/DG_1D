#include "structs.h"
#include "legendre.h"
#include "par.h"
#include <stdlib.h>
void malloc_structs(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list) {
   char file[] = "parfiles/in.par";

   read_pars(the_grid, the_par_list, file);
   
   int cell_num = the_grid->x1num + 2*(the_grid->x1ghostnum);
   int var_num = the_grid->consnum + the_grid->passivenum;
   int weight_num = the_grid->spaceorder+1;
   
   the_grid->cells = malloc(sizeof(struct cell)*cell_num);
   the_grid->prim = malloc(sizeof(double)*weight_num*var_num*cell_num);
   the_grid->primrk = malloc(sizeof(double)*weight_num*var_num*cell_num);
   the_grid->cons = malloc(sizeof(double)*weight_num*var_num*cell_num);
   the_grid->consrk = malloc(sizeof(double)*weight_num*var_num*cell_num);

   the_legendre_list->coefficient_matrix = malloc(sizeof(long double)*weight_num*weight_num);
   the_legendre_list->root_matrix = malloc(sizeof(double)*weight_num*weight_num);
   the_legendre_list->weight_matrix = malloc(sizeof(double)*weight_num*weight_num);
   
   get_legendre_polynomials(the_grid->spaceorder, the_legendre_list->coefficient_matrix);
   get_roots(the_legendre_list->root_matrix, the_grid->spaceorder,
         the_legendre_list->coefficient_matrix);
   normalize_polynomials(the_grid->spaceorder, the_legendre_list->coefficient_matrix);
   get_weights(the_legendre_list->weight_matrix, the_grid->spaceorder,
         the_legendre_list->root_matrix, the_legendre_list->coefficient_matrix);
}

