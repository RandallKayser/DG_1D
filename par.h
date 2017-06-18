#include "grid.h"
struct parlist {
   double gamma_law;
   double cfl_coefficient;   

   int checkpoint_num;

   double InitPar1;
   double InitPar2;
   double InitPar3;
   double InitPar4;
   double InitPar5;
   double InitPar6;
   double InitPar7;
   double InitPar8;
   double InitPar9;
   double InitPar10;
};

int readvar(char filename[], char key[], int vtype, void *ptr);
void read_pars(struct grid *the_grid, struct parlist *the_par_list, char filename[]);
void print_pars(struct grid *the_grid, struct parlist *the_par_list);

