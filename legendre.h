void get_legendre_polynomials(int max_order, double* coefficient_matrix);
double evaluate_legendre_polynomial(double x, int order, int max_order, double* coefficient_matrix);
double evaluate_derivative(double x, int order,int max_order, double* coefficient_matrix);
void get_roots(double* root_matrix, int max_order, double* coefficient_matrix);
