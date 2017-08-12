#include "structs.h"
#include "legendre.h"
#include "init.h"
#include "par.h"
#include <stdlib.h>
#include <stdio.h>

void malloc_structs(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list) {
   char file[] = "parfiles/in.par";

   read_pars(the_grid, the_par_list, file);
   
   int cell_num = the_grid->x1num;
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


void build_cells_uniform(struct grid *the_grid) {
   int cellnum = the_grid->x1num;

   the_grid->cells[0].left = NULL;
   the_grid->cells[0].right = &(the_grid->cells[1]);
   
   the_grid->cells[cellnum-1].left = &(the_grid->cells[cellnum-2]);
   the_grid->cells[cellnum-1].right = NULL;

   for(int i=1; i<cellnum-1; i++) {
      the_grid->cells[i].left = &(the_grid->cells[i-1]);
      the_grid->cells[i].right = &(the_grid->cells[i+1]);
   }

   double dx = (the_grid->x1max - the_grid->x1min) / cellnum;
  
   for(int i=0; i<cellnum; i++) {
      the_grid->cells[i].xm = (double) i*dx;
      the_grid->cells[i].xp = (double) (i+1)*dx;
      the_grid->cells[i].dA = dx*dx;
      the_grid->cells[i].dV = dx*dx*dx;
      the_grid->cells[i].cell_label = i;
   }  
}

void print_cells(struct grid *the_grid) {
   for(int i=0; i<the_grid->x1num; i++) {
      printf("This cell is: %i\n", the_grid->cells[i].cell_label);
      if(the_grid->cells[i].left != NULL) {
         printf("Left Neighbor: %i\n", (the_grid->cells[i].left)->cell_label);
      } else {
         printf("No Left Neighbor\n");
      }
      if(the_grid->cells[i].right != NULL) {
         printf("Right Neighbor: %i\n", (the_grid->cells[i].right)->cell_label);
      } else {
         printf("No Right Neighbor\n");
      }

      printf("Its Dimensions are: (xm, xp, dA, dV) = (%f, %f, %f, %f)\n",
         the_grid->cells[i].xm, the_grid->cells[i].xp,
         the_grid->cells[i].dA, the_grid->cells[i].dV);
      printf("\n\n\n");
   }
}
double DDD_init(struct grid *the_grid, double x) {
   return rho_init(the_grid, x);
}

double SSS_init(struct grid *the_grid, double x) {
   return rho_init(the_grid, x) * vvv_init(the_grid, x);
}

double EEE_init(struct grid *the_grid, double x) {
   double rho = rho_init(the_grid, x);
   double vvv = vvv_init(the_grid, x);
   double ppp = ppp_init(the_grid, x);
   double gam = the_grid->gamma_law;

   return .5*rho*vvv*vvv + ppp/(gam-1.0);
}

void project_init_conds(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list) {
   int cell_num = the_grid->x1num;
   int weight_num = the_grid->spaceorder + 1;
   int var_num = the_grid->consnum + the_grid->passivenum;
   int block_size = weight_num*var_num;
   int this_cell;
   double local_xm, local_xp;
   double *local_prims;

   for(int i=0; i<cell_num; i++) {
      this_cell = the_grid->cells[i].cell_label;
      local_xm = the_grid->cells[i].xm;
      local_xp = the_grid->cells[i].xp;
      local_prims=the_grid->prim + this_cell*block_size;   
      
      for(int weight=0; weight<weight_num; weight++) {
         local_prims[DDD*weight_num + weight] = .5 * basis_func_glq(&DDD_init, weight, local_xm, local_xp, the_grid->spaceorder, the_grid->spaceorder, the_grid, the_legendre_list); 
         local_prims[SSS*weight_num + weight] = .5 * basis_func_glq(&SSS_init, weight, local_xm, local_xp, the_grid->spaceorder, the_grid->spaceorder, the_grid, the_legendre_list); 
         local_prims[EEE*weight_num + weight] = .5 * basis_func_glq(&EEE_init, weight, local_xm, local_xp, the_grid->spaceorder, the_grid->spaceorder, the_grid, the_legendre_list); 
      }
   }
}
