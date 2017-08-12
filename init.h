void malloc_structs(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list);

void build_cells_uniform(struct grid *the_grid);
void print_cells(struct grid *the_grid);

double rho_init(struct grid *the_grid, double x);
double vvv_init(struct grid *the_grid, double x);
double ppp_init(struct grid *the_grid, double x);

double DDD_init(struct grid *the_grid, double x);
double SSS_init(struct grid *the_grid, double x);
double EEE_init(struct grid *the_grid, double x);

void project_init_conds(struct grid *the_grid, struct parlist *the_par_list, struct legendrelist *the_legendre_list);


