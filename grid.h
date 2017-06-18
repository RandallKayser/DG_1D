#ifndef GRID_INCLUDED
#define GRID_INCLUDED 1

struct grid {
   int x1num;
   int x1ghostnum;
   double x1min;
   double x1max;

   double t;
   double t_final;
    
   int consnum;
   int passivenum;
   
   struct cell *cells;

   double *prim;
   double *primrk;

   double *cons;
   double *consrk;

   int r_solver;
   int spaceorder;
   int rkmethod;

   int bc_x1_inner;
   int bc_x1_outer;
   
   double gamma_law;
   double cfl_coefficient;
};

struct cell {
   double xm;
   double xp;
   double dA;
   double dV;
}; 
    

#endif


