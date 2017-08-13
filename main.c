#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
#include "structs.h"
#include "par.h"
#include "init.h"

int main(void) {
   
   struct grid thegrid;
   struct parlist theparlist;
   struct legendrelist thelegendrelist;

   malloc_structs(&thegrid, &theparlist, &thelegendrelist);
   print_pars(&thegrid, &theparlist);
   build_cells_uniform(&thegrid);
   project_init_conds(&thegrid, &theparlist, &thelegendrelist);
   print_cells(&thegrid);
}
