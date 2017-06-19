#ifndef STRUCTS_INCLUDED
#define STRUCTS_INCLUDED 1


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


struct legendrelist {
   long double *coefficient_matrix;
   double *root_matrix;
   double *weight_matrix;
};


#endif
