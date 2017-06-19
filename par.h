#include "structs.h"

int readvar(char filename[], char key[], int vtype, void *ptr);
void read_pars(struct grid *the_grid, struct parlist *the_par_list, char filename[]);
void print_pars(struct grid *the_grid, struct parlist *the_par_list);

