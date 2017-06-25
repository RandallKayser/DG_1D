void malloc_structs(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list);

void build_cells_uniform(struct grid *the_grid);

double rho_init(double *x);
double vvv_init(double *x);
double ppp_init(double *x);

void project_init_conds(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list);


