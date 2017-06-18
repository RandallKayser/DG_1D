void get_legendre_polynomials(int max_order, long double *coefficient_matrix);
void normalize_polynomials(int max_order, long double *coefficient_matrix);
long double evaluate_legendre_polynomial(long double x, int order, int max_order, long double *coefficient_matrix);
long double evaluate_derivative(long double x, int order,int max_order, long double *coefficient_matrix);
void get_roots(double *root_matrix, int max_order, long double *coefficient_matrix);
void get_weights(double *weight_matrix, int max_order, double *root_matrix, long double *coefficient_matrix);
double glq(double (*func)(double), double low_bound, double high_bound, int order, int max_order,double *weight_matrix, double *root_matrix);

struct legendrelist {
   long double *coefficient_matrix;
   double *root_matrix;
   double *weight_matrix;
};

