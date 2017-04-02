#include <stdio.h>
#include <string.h>
#include "par.h"

int readvar(char filename[], char key[], int vtype, void *ptr) {
    FILE *f = fopen(filename, "r");

    char line[256];
    char word[256];
    int found = 0;

    while(fgets(line,256,f) != NULL) {
        sscanf(line, "%s ", word);
        if(strcmp(word,key) == 0) {
            found = 1;
            break;
        }
    }

    fclose(f);
    if(!found) {
        return 0;
    }

    char *sval = line + strlen(key) + strspn(line+strlen(key)," \t:=");

    if(vtype == VAR_DBL) {
        double val;
        sscanf(sval, "%lf", &val);
        *((double *)ptr) = val;

    } else if(vtype == VAR_INT) {
        int val;
        sscanf(sval, "%d", &val);
        *((int *)ptr) = val;

    } else if(vtype == VAR_LON) {
        long val;
        sscanf(sval, "%ld", &val);
        *((long *)ptr) = val;

    } else {
        strcpy((char *) ptr, sval);
    }

    return 0;
}

void read_pars(struct grid *thegrid, char filename[]) {
    readvar(filename, "x1num", VAR_INT, &(thegrid->x1num));
    readvar(filename, "x2num", VAR_INT, &(thegrid->x2num));
    readvar(filename, "x3num", VAR_INT, &(thegrid->x3num));

    readvar(filename, "x1ghostnum", VAR_INT, &(thegrid->x1ghostnum));
    readvar(filename, "x2ghostnum", VAR_INT, &(thegrid->x2ghostnum));
    readvar(filename, "x3ghostnum", VAR_INT, &(thegrid->x3ghostnum));

    readvar(filename, "x1max", VAR_DBL, &(thegrid->x1max));
    readvar(filename, "x1min", VAR_DBL, &(thegrid->x1min));
    readvar(filename, "x2max", VAR_DBL, &(thegrid->x2max));
    readvar(filename, "x2min", VAR_DBL, &(thegrid->x2min));
    readvar(filename, "x3max", VAR_DBL, &(thegrid->x3max));
    readvar(filename, "x3min", VAR_DBL, &(thegrid->x3min));

    readvar(filename, "t_init",  VAR_DBL, &(thegrid->t));
    readvar(filename, "f_final", VAR_DBL, &(thegrid->t_final));
    readvar(filename, "checkpoint_num",  VAR_INT, &(thegrid->checkpoint_num));

    readvar(filename, "consnum",  VAR_INT, &(thegrid->consnum));
    readvar(filename, "passivenum",  VAR_INT, &(thegrid->passivenum));
    
    readvar(filename, "r_solver", VAR_INT, &(thegrid->r_solver));
    readvar(filename, "spaceorder", VAR_INT, &(thegrid->spaceorder));
    readvar(filename, "rkmethod", VAR_INT, &(thegrid->rkmethod));
    
    readvar(filename, "bcx1inner", VAR_INT, &(thegrid->bc_x1_inner));
    readvar(filename, "bcx1outer", VAR_INT, &(thegrid->bc_x1_outer));
    readvar(filename, "bcx2inner", VAR_INT, &(thegrid->bc_x2_inner));
    readvar(filename, "bcx2outer", VAR_INT, &(thegrid->bc_x2_outer));
    readvar(filename, "bcx3inner", VAR_INT, &(thegrid->bc_x3_inner));
    readvar(filename, "bcx3outer", VAR_INT, &(thegrid->bc_x3_outer));

    readvar(filename, "gamma_law_coefficient",  VAR_DBL, &(thegrid->gamma_law_coefficient));
    readvar(filename, "cfl_coefficient",  VAR_DBL, &(thegrid->cfl_coefficient));

    readvar(filename, "InitPar1",     VAR_DBL, &(thegrid->InitPar1));
    readvar(filename, "InitPar2",     VAR_DBL, &(thegrid->InitPar2));
    readvar(filename, "InitPar3",     VAR_DBL, &(thegrid->InitPar3));
    readvar(filename, "InitPar4",     VAR_DBL, &(thegrid->InitPar4));
    readvar(filename, "InitPar5",     VAR_DBL, &(thegrid->InitPar5));
    readvar(filename, "InitPar6",     VAR_DBL, &(thegrid->InitPar6));
    readvar(filename, "InitPar7",     VAR_DBL, &(thegrid->InitPar7));
    readvar(filename, "InitPar8",     VAR_DBL, &(thegrid->InitPar8));
    readvar(filename, "InitPar9",     VAR_DBL, &(thegrid->InitPar9));
    readvar(filename, "InitPar10",     VAR_DBL, &(thegrid->InitPar10));
}

void print_pars(struct grid *thegrid) {
    printf("===Input Parameters===\n");
    printf("x1num: %d\n", thegrid->x1num);
    printf("x2num: %d\n", thegrid->x2num);
    printf("x3num: %d\n", thegrid->x3num);

    printf("x1ghostnum: %d\n", thegrid->x1ghostnum);
    printf("x2ghostnum: %d\n", thegrid->x2ghostnum);
    printf("x3ghostnum: %d\n", thegrid->x3ghostnum);

    printf("x1min: %f\n", thegrid->x1min);
    printf("x1max: %f\n", thegrid->x1max);
    printf("x2min: %f\n", thegrid->x2min);
    printf("x2max: %f\n", thegrid->x2max);
    printf("x3min: %f\n", thegrid->x3min);
    printf("x3max: %f\n", thegrid->x3max);
    
    printf("t_init: %f\n", thegrid->t);
    printf("t_final: %f\n", thegrid->t_final);
    printf("checkpoint_num: %d\n", thegrid->checkpoint_num);

    printf("consnum: %d\n", thegrid->consnum);
    printf("passivenum: %d\n", thegrid->passivenum);
    
    printf("r_solver: %d\n", thegrid->r_solver);
    printf("spaceorder: %d\n", thegrid->spaceorder);
    printf("rkmethod: %d\n", thegrid->rkmethod);

    printf("bc_x1_inner: %d\n", thegrid->bc_x1_inner);
    printf("bc_x1_outer: %d\n", thegrid->bc_x1_outer);
    printf("bc_x2_inner: %d\n", thegrid->bc_x2_inner);
    printf("bc_x2_outer: %d\n", thegrid->bc_x2_outer);
    printf("bc_x3_inner: %d\n", thegrid->bc_x3_inner);
    printf("bc_x3_outer: %d\n", thegrid->bc_x3_outer);


    printf("gamma_law_coefficient: %f\n", thegrid->gamma_law_coefficient);
    printf("cfl_coefficient: %f\n", thegrid->cfl_coefficient);

    printf("InitPar1: %g\n", thegrid->InitPar1);
    printf("InitPar2: %g\n", thegrid->InitPar2);
    printf("InitPar3: %g\n", thegrid->InitPar3);
    printf("InitPar4: %g\n", thegrid->InitPar4);
    printf("InitPar5: %g\n", thegrid->InitPar5);
    printf("InitPar6: %g\n", thegrid->InitPar6);
    printf("InitPar7: %g\n", thegrid->InitPar7);
    printf("InitPar8: %g\n", thegrid->InitPar8);
    printf("InitPar9: %g\n", thegrid->InitPar9);
    printf("InitPar10: %g\n", thegrid->InitPar10);
    printf("\n");
}