void get_legendre_polynomials(int max_order, double* coefficient_matrix);
double evaluate_legendre_polynomial(double x, int order, double* coefficient_matrix);
double* get_roots(int order, double* coefficient_matrix, double* zero_matrix);

struct polynomial {
   int order;
   double* coefficients;
};

