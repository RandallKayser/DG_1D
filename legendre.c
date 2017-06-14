#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "legendre.h"

void get_legendre_polynomials(int max_order, double* coefficient_matrix) {
   for(int i=0; i<=2*(max_order+1); i++) {
      coefficient_matrix[i] = 0.0;
   }
   
   coefficient_matrix[0] = 1.0;
   coefficient_matrix[max_order+2] = 1.0;
   
   for(int i=1; i<max_order; i++) {
      for(int j=0; j<=i+1; j++) {
         coefficient_matrix[(i+1)*(max_order+1)+j] = (double)
            (2.0*i+1.0)/(i+1.0)*coefficient_matrix[i*(max_order+1)+j-1] -
            i/(i+1.0)*coefficient_matrix[(i-1)*(max_order+1)+j];
      }
   }

   for(int i=0; i<=max_order; i++) {
      for(int j=0; j<=i+1; j++) {
         coefficient_matrix[i*(max_order+1)+j] /= sqrt(2.0/(2.0*i+1.0));
      }
   }
}


double evaluate_legendre_polynomial(double x, int order, int max_order, double* coefficient_matrix) {
   double result=coefficient_matrix[order*(max_order+1)+order+1];

   for(int i=order; i>=0; i--) {
      result = result*x + coefficient_matrix[order*(max_order+1)+i];
   }

   return result;
}


double sign(double a) {
   if(a>0) {
      return 1.0;
   } else if(a < 0) {
      return -1.0;
   } else {
      return 0.0;
   }
}


double evaluate_derivative(double x, int order,int max_order, double* coefficient_matrix) {
   double result = order*coefficient_matrix[order*(max_order+1)+order+1];
   for(int i=order; i>=1; i--) {
      result = result*x + i*coefficient_matrix[order*(max_order+1)+i];
   }

   return result;
}


void get_roots(double* root_matrix, int max_order, double* coefficient_matrix) {
   for(int i=0; i<(max_order+1)*(max_order+1); i++) {
      root_matrix[i] = 2.0;
   }

   root_matrix[max_order+1] = 0.0;
   root_matrix[2*(max_order+1)] = -pow(3.0,-0.5);
   root_matrix[2*(max_order+1)+1] = pow(3.0,-0.5);

   double bounds[2];
   double tolerance = 1.0e-14;
   double error = 10000.0;
   double x;
   
   for(int order=3; order<=max_order; order++) {
      for(int root=0; root<order; root++) {
         error = 10000.0;
         if(root!=0 && root!=order-1) {
            bounds[0] = root_matrix[(order-1)*(max_order+1)+root-1];
            bounds[1] = root_matrix[(order-1)*(max_order+1)+root];
         } else if(root==0) {
            bounds[0] = -1.0;
            bounds[1] = root_matrix[(order-1)*(max_order+1)+root];
         } else if(root==order-1) {
            bounds[0] = root_matrix[(order-1)*(max_order+1)+root-1];
            bounds[1] = 1.0;
         }

         x = (bounds[0] + bounds[1])/2.0;
         while(error >= tolerance) {
            error = evaluate_legendre_polynomial(x, order, max_order, coefficient_matrix) /
               evaluate_derivative(x, order, max_order, coefficient_matrix);
            x -= error;
            error = fabs(error);
         }

         root_matrix[order*(max_order+1)+root] = x;
      }
   }
}

void get_weights(double* weight_matrix, int max_order, double* root_matrix, double* coefficient_matrix) {
   double xj, pj_prime;
   for(int order=1; order<=max_order; order++) {
      for(int i=0; i<order; i++) {
         xj = root_matrix[order*(max_order+1)+i];
         pj_prime = evaluate_derivative(xj, order, max_order, coefficient_matrix);
         weight_matrix[order*(max_order+1)+i] = (2.0*order+1)/((1.0-xj*xj)*pj_prime*pj_prime);
      }
   }
}


double glq(double (*func)(double), double low_bound, double high_bound, int order, int max_order, double* weight_matrix, double* root_matrix) {
   double result = 0.0;
   double xi, wi;
   for(int i=0; i<order; i++) {
      xi = root_matrix[order*(max_order+1)+i];
      wi = weight_matrix[order*(max_order+1)+i];

      result += wi*func(xi);
   }
   return result;
}


double myfunc(double x) {
   return sin(x*x)+x*cos(x);
}



