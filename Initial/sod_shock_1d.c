#include "../structs.h"

double rho_init(struct grid *the_grid, double x) {
   double midpoint = (the_grid->x1min + the_grid->x1max) / 2.0;
   if(x<=midpoint) {
      return 10.0;
   } else {
      return 1.0;
   }
}


double vvv_init(struct grid *the_grid, double x) {
   return 0.0;
}


double ppp_init(struct grid *the_grid, double x) {
   double midpoint = (the_grid->x1min + the_grid->x1max) / 2.0;
   if(x<=midpoint) {
      return 50.0/3.0;
   } else {
      return 5.0/3.0;
   }
}



