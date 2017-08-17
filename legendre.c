#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "legendre.h"
#define sign(X) ((X > 0) - (X < 0))

void get_legendre_polynomials(int max_order, long double* coefficient_matrix) {
   for(int i=0; i<max_order*max_order; i++) {
      coefficient_matrix[i] = 0.0;
   }
   
   coefficient_matrix[0] = 1.0;
   coefficient_matrix[max_order+1] = 1.0;
   
   for(int i=1; i<max_order-1; i++) {
      coefficient_matrix[(i+1)*max_order] = 
         (long double) -i/(i+1)*coefficient_matrix[(i-1)*max_order];

      for(int j=1; j<=i+1; j++) {
         coefficient_matrix[(i+1)*max_order+j] = (long double)
            (2.0*i+1.0)/(i+1.0)*coefficient_matrix[i*max_order+j-1] -
            i/(i+1.0)*coefficient_matrix[(i-1)*max_order+j];
      }
   }
}


void normalize_polynomials(int max_order, long double* coefficient_matrix) {
   for(int i=0; i<max_order; i++) {
      for(int j=0; j<=i; j++) {
         coefficient_matrix[i*max_order+j] /= sqrtl(2.0/(2.0*i+1.0));
      }
   }
}


long double evaluate_legendre_polynomial(long double x, int order, int max_order, long double* coefficient_matrix) {
   long double result=coefficient_matrix[order*max_order+order];

   for(int i=order; i>0; i--) {
      result = result*x + coefficient_matrix[order*max_order+i-1];
   }

   return result;
}


long double evaluate_derivative(long double x, int order, int max_order, long  double* coefficient_matrix) {
   long double result = order*coefficient_matrix[order*max_order+order];
   for(int i=order; i>1; i--) {
      result = result*x + i*coefficient_matrix[order*max_order+i-1];
   }

   return result;
}


void bisection(double *bounds, int root, int order, int max_order, long double *coefficient_matrix, double* root_matrix) {
   double high = bounds[1];
   double low = bounds[0];
   double result = (bounds[1]+bounds[0])/2.0;

   double high_val = evaluate_legendre_polynomial(high, order, max_order, coefficient_matrix);
   double low_val = evaluate_legendre_polynomial(low, order, max_order, coefficient_matrix);;
   double result_val = evaluate_legendre_polynomial(result, order, max_order, coefficient_matrix);

   double high_sign = (double) sign(high_val);
   double low_sign = (double) sign(low_val);
   double result_sign = sign(result_val);
   
   double tolerance = 1.0e-14;
   
   while(high-low > tolerance) {
      if(high_sign == low_sign) {
         printf("no root???\n");
      }
      

      if(result_sign == high_sign) {
         high = result;
         high_val = evaluate_legendre_polynomial(result, order, max_order, coefficient_matrix);
         high_sign = sign(high_val);

      } else if(result_sign == low_sign) {
         low = result;
         low_val = evaluate_legendre_polynomial(result, order, max_order, coefficient_matrix);
         low_sign = sign(low_val);
      }

      result = (high + low)/2.0;
      result_val = evaluate_legendre_polynomial(result, order, max_order, coefficient_matrix);
      result_sign = (double) sign(result_val);
   }
   root_matrix[order*max_order + root] = result;
}


void get_roots(double* root_matrix, int max_order, long double* coefficient_matrix) {
   for(int i=0; i<max_order*max_order; i++) {
      root_matrix[i] = 2.0;
   }

   root_matrix[max_order] = 0.0;
   root_matrix[2*max_order] = -pow(3.0,-0.5);
   root_matrix[2*max_order+1] = pow(3.0,-0.5);

   double bounds[2];
   double tolerance = 1.0e-14;
   double error = 10000.0;
   double x;
   int iterations=0;
   
   for(int order=3; order<max_order; order++) {
      for(int root=0; root<order; root++) {
         error = 10000.0;
         iterations=0;
         if(root!=0 && root!=order-1) {
            bounds[0] = root_matrix[(order-1)*max_order+root-1];
            bounds[1] = root_matrix[(order-1)*max_order+root];
         } else if(root==0) {
            bounds[0] = -1.0;
            bounds[1] = root_matrix[(order-1)*max_order+root];
         } else if(root==order-1) {
            bounds[0] = root_matrix[(order-1)*max_order+root-1];
            bounds[1] = 1.0;
         }

         x = (bounds[0] + bounds[1])/2.0;
         printf("%f\n", x);
         while(error >= tolerance && iterations<=200) {
            error = evaluate_legendre_polynomial(x, order, max_order, coefficient_matrix) /
               evaluate_derivative(x, order, max_order, coefficient_matrix);
            x -= error;
            printf("%f\n", x); 
            error = fabsl(error);
            iterations++;
         }
         if(iterations<200) {
            root_matrix[order*max_order+root] = x;
         } else {
            bisection(bounds, root, order, max_order, coefficient_matrix, root_matrix);
         }
      }
   }
}

void get_weights(double *weight_matrix, int max_order, double *root_matrix, long double *coefficient_matrix) {
   double xj, pj_prime;
   for(int order=1; order<=max_order; order++) {
      for(int i=0; i<order; i++) {
         xj = root_matrix[order*max_order+i];
         pj_prime = evaluate_derivative(xj, order, max_order, coefficient_matrix);
         weight_matrix[order*max_order+i] = (2.0*order+1)/((1.0-xj*xj)*pj_prime*pj_prime);
      }
   }
}


double glq(double (*func)(double), double low_bound, double high_bound, int order, int max_order, double *weight_matrix, double *root_matrix) {
   double result = 0.0;
   double xi, wi;
   double scale = (high_bound-low_bound)/2.0;
   double shift = (high_bound+low_bound)/2.0;

   for(int i=0; i<order; i++) {
      xi = root_matrix[order*max_order+i];
      wi = weight_matrix[order*max_order+i];

      result += wi*func(scale*xi+shift);
   }
   result *= scale;
   return result;
}


double basis_func_glq(double (*func)(struct grid *, double), int basis_num, double low_bound, double high_bound, int order, int max_order, struct grid *the_grid, struct legendrelist *the_legendre_list) {
   double result = 0.0;
   double xi, wi;
   double scale = (high_bound-low_bound)/2.0;
   double shift = (high_bound+low_bound)/2.0;
   double leg_poly;
   long double *coefficientmatrix = the_legendre_list->coefficient_matrix;
   double *rootmatrix = the_legendre_list->root_matrix;
   double *weightmatrix = the_legendre_list->weight_matrix;
   for(int i=0; i<order; i++) {
      xi = rootmatrix[order*max_order+i];
      wi = weightmatrix[order*max_order+i];
      printf("xi = %lf wi = %lf\n", xi, wi);
      leg_poly = evaluate_legendre_polynomial(xi, basis_num, max_order, coefficientmatrix);

      result += wi*func(the_grid, scale*xi+shift) * leg_poly;
   }

   result *= scale;
   return result;
}
