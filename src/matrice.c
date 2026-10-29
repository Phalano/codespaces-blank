#include "../header/matrice.h"
#include <stdio.h>
#include <stdlib.h>

matrice* matrice_create(int col, int lign){
    int i;
    matrice* r = (matrice *) malloc(sizeof(matrice));
    r->lign = lign;
    r->col = col;
    r->elt = (int **) malloc((lign * col) * sizeof(int));
    for(i = 0; i < lign; i++){
        r->elt[i] = (int *) malloc(sizeof(int));
    }
    return r;
}

void matrice_free(matrice* r){
    int i;
    for(i = 0; i < r->lign; i++){
        free(r->elt[i]);
    }
    free(r->elt);
    free(r);
}

void matrice_null(matrice* r){
    int i, j;
    for(i = 0; i < r->lign; i++){
        for(j = 0; j < r->col; j++){
            r->elt[i][j] = 0;
        }
    }
}

void matrice_set(matrice* m, int i, int j, int x){
    if(i > m ->lign && j < m->col){
        m->elt[i][j] = x;
    }
}

void matrice_print(matrice* m){
    int i, j;
    for(i = 0; i < m->lign; i++){
        for(j = 0; j < m->col; j++){
            printf("%d ", m->elt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

matrice* matrice_file(FILE* fp){
    int i, j, n, m;
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    matrice* r = matrice_create(m, n);
    for(i = 0; i < r->lign; i++){
        for(j = 0; j < r->col; j++){
            fscanf(fp, "%d", &r->elt[i][j]);
        }
    }
    return r;
}