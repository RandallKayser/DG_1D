enum {VAR_INT, VAR_DBL, VAR_LON};

struct grid {
    int x1num;
    int x2num;
    int x3num;

    int x1ghostnum;
    int x2ghostnum;
    int x3ghostnum;

    double x1min;
    double x1max;
    double x2min;
    double x2max;
    double x3min;
    double x3max;

    double t;
    double t_final;
    
    int checkpoint_num;

    int consnum;
    int passivenum;

    double *prim;
    double *prim1;

    double *cons;
    double *cons1;

    double *Legendre_coefficients;
    double *LGL_nodes;
    double *LGL_weights;

    int r_solver;
    int spaceorder;
    int rkmethod;

    int bc_x1_inner;
    int bc_x1_outer;
    int bc_x2_inner;
    int bc_x2_outer;
    int bc_x3_inner;
    int bc_x3_outer;

    double gamma_law_coefficient;
    double cfl_coefficient;

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