void prim_to_cons(struct grid *the_grid) {

   double rhoe;
   double *prim;
   double *cons;

   cons[DDD] = prim[RHO];
   cons[SSS] = prim[RHO] * prim[VVV];
   cons[EEE] = .5 * prim[RHO] * prim[VVV] * prim[VVV] + rhoe;
}

void cons_to_prim(struct grid *the_grid) {
   prim[RHO] = cons[DDD];
   prim[VVV] = cons[SSS] / cons[DDD];
   prim[PPP] = (cons[EEE] - 0.5 * prim[RHO] * prim[VVV] * prim[VVV]) * (gammalaw - 1.0);
}


