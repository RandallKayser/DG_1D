#include <stdlib.h>
#include <stdio.h>
#include "legendre.h"
#include "structs.h"
#include "par.h"
int main(void) {
   
   struct grid thegrid;
   struct parlist theparlist;
   struct legendrelist thelegendrelist;

   malloc_structs(&thegrid, &theparlist, &thelegendrelist);
   print_pars(&thegrid, &theparlist);

}
