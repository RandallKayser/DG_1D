#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "par.h"

enum{VAR_INT, VAR_LON, VAR_DBL};

int readvar(char filename[], char key[], int vtype, void *ptr) {
   FILE *f = fopen(filename, "r");

   char line[512];
   char word[512];
   int found = 0;

   while(fgets(line,512,f) != NULL) {
      sscanf(line, "%s", word);
      if(strcmp(word,key) == 0) {
         found = 1;
         break;
      }
   }

   fclose(f);
   if(!found) {
       return 0;
   }

   char *sval;
   sval = line + strlen(key) + strspn(line+strlen(key)," =\t");
   if(vtype == VAR_DBL) {
      double val;
      sscanf(sval, "%lf", &val);
      *((double *)ptr) = val;

   } else if(vtype == VAR_INT) {
      int val;
      sscanf(sval, "%d", &val);
      *((int *) ptr) = val;

   } else if(vtype == VAR_LON) {
      long val;
      sscanf(sval, "%ld", &val);
      *((long *)ptr) = val;

   } else {
      strcpy((char *) ptr, sval);
   }

   return 0;
}

void read_pars(struct grid *the_grid, struct parlist *the_par_list, char filename[]) {
    readvar(filename, "x1num:", VAR_INT, &(the_grid->x1num));
    readvar(filename, "x1max:", VAR_DBL, &(the_grid->x1max));
    readvar(filename, "x1min:", VAR_DBL, &(the_grid->x1min));

    readvar(filename, "t_init:",  VAR_DBL, &(the_grid->t));
    readvar(filename, "t_final:", VAR_DBL, &(the_grid->t_final));
    readvar(filename, "checkpoint_num:",  VAR_INT, &(the_par_list->checkpoint_num));

    readvar(filename, "consnum:",  VAR_INT, &(the_grid->consnum));
    readvar(filename, "passivenum:",  VAR_INT, &(the_grid->passivenum));
    
    readvar(filename, "r_solver:", VAR_INT, &(the_grid->r_solver));
    readvar(filename, "spaceorder:", VAR_INT, &(the_grid->spaceorder));
    readvar(filename, "rkmethod:", VAR_INT, &(the_grid->rkmethod));
    
    readvar(filename, "bcx1inner:", VAR_INT, &(the_grid->bc_x1_inner));
    readvar(filename, "bcx1outer:", VAR_INT, &(the_grid->bc_x1_outer));

    readvar(filename, "InitPar1:",     VAR_DBL, &(the_par_list->InitPar1));
    readvar(filename, "InitPar2:",     VAR_DBL, &(the_par_list->InitPar2));
    readvar(filename, "InitPar3:",     VAR_DBL, &(the_par_list->InitPar3));
    readvar(filename, "InitPar4:",     VAR_DBL, &(the_par_list->InitPar4));
    readvar(filename, "InitPar5:",     VAR_DBL, &(the_par_list->InitPar5));
    readvar(filename, "InitPar6:",     VAR_DBL, &(the_par_list->InitPar6));
    readvar(filename, "InitPar7:",     VAR_DBL, &(the_par_list->InitPar7));
    readvar(filename, "InitPar8:",     VAR_DBL, &(the_par_list->InitPar8));
    readvar(filename, "InitPar9:",     VAR_DBL, &(the_par_list->InitPar9));
    readvar(filename, "InitPar10:",    VAR_DBL, &(the_par_list->InitPar10));

    readvar(filename, "gamma_law:",           VAR_DBL, &(the_par_list->gamma_law));
    readvar(filename, "cfl_coefficient:",     VAR_DBL, &(the_par_list->cfl_coefficient));
    
}

void print_pars(struct grid *the_grid, struct parlist *the_par_list) {
    printf("===Input Parameters===\n");
    printf("x1num: %d\n", the_grid->x1num);
    printf("x1min: %f\n", the_grid->x1min);
    printf("x1max: %f\n", the_grid->x1max);
   
    printf("t_init: %f\n", the_grid->t);
    printf("t_final: %f\n", the_grid->t_final);
    printf("checkpoint_num: %d\n", the_par_list->checkpoint_num);

    printf("consnum: %d\n", the_grid->consnum);
    printf("passivenum: %d\n", the_grid->passivenum);
    
    printf("r_solver: %d\n", the_grid->r_solver);
    printf("spaceorder: %d\n", the_grid->spaceorder);
    printf("rkmethod: %d\n", the_grid->rkmethod);

    printf("bc_x1_inner: %d\n", the_grid->bc_x1_inner);
    printf("bc_x1_outer: %d\n", the_grid->bc_x1_outer);

    printf("gamma_law_coefficient: %f\n", the_par_list->gamma_law);
    printf("cfl_coefficient: %f\n", the_par_list->cfl_coefficient);

    printf("InitPar1: %g\n", the_par_list->InitPar1);
    printf("InitPar2: %g\n", the_par_list->InitPar2);
    printf("InitPar3: %g\n", the_par_list->InitPar3);
    printf("InitPar4: %g\n", the_par_list->InitPar4);
    printf("InitPar5: %g\n", the_par_list->InitPar5);
    printf("InitPar6: %g\n", the_par_list->InitPar6);
    printf("InitPar7: %g\n", the_par_list->InitPar7);
    printf("InitPar8: %g\n", the_par_list->InitPar8);
    printf("InitPar9: %g\n", the_par_list->InitPar9);
    printf("InitPar10: %g\n", the_par_list->InitPar10);
    printf("\n");
}
