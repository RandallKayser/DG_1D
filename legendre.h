#include "structs.h" 
void get_legendre_polynomials(int max_order, double *coefficient_matrix);

void normalize_polynomials(int max_order, double *coefficient_matrix);

double evaluate_legendre_polynomial(double x, int order, int max_order, double *coefficient_matrix);

double evaluate_derivative(double x, int order,int max_order, double *coefficient_matrix);

void get_roots(double *root_matrix, int max_order, double *coefficient_matrix);

void get_weights(double *weight_matrix, int max_order, double *root_matrix, double *coefficient_matrix);

double glq(double (*func)(double), double low_bound, double high_bound, int order, int max_order,double *weight_matrix, double *root_matrix);

double basis_func_glq(double (*func)(struct grid *, double), int basis_num, double low_bound, double high_bound, int order, int max_order, struct grid *the_grid, struct legendrelist *the_legendre_list);
