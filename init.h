void init_structs(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list);

double rho_init(struct cell the_cell);
double vvv_init(struct cell the_cell);
double ppp_init(struct cell the_cell);

void project_init_conds(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list);
