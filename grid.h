<<<<<<< HEAD
#ifndef GRID_INCLUDED
#define GRID_INCLUDED 1
enum {VAR_INT, VAR_DBL, VAR_LON};


struct grid {
    int x1num;

    int x1ghostnum;

    double x1min;
    double x1max;

    double t;
    double t_final;
    
    int checkpoint_num;

    int consnum;
    int passivenum;

    double *prim;
    double *prim1;

    double *cons;
    double *cons1;

    int r_solver;
    int spaceorder;
    int rkmethod;

    int bc_x1_inner;
    int bc_x1_outer;
   
};

#endif
