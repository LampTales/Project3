#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

struct Matrix* createMatrix(int row, int col) {
    if (row <= 0 || col <= 0) {
        return NULL;
    }

    float* fpo = (float*)malloc(row * col * sizeof(float));
    for (int i = 0; i < row * col; i++) {
        fpo[i] = 0;
    }
    struct Matrix* mpo = (struct Matrix*)malloc(sizeof(struct Matrix));
    mpo->row = row;
    mpo->col = col;
    mpo->arr = fpo;
    return mpo;
}

// How can I create the pointer to pass the data correctly?
struct Matrix* createMatrixWithIni(int row, int col, const float* fpointer) {
    if (row <= 0 || col <= 0 || fpointer != NULL) {
        return NULL;
    }

    float* fpo = (float*)malloc(row * col * sizeof(float));
    for (int i = 0; i < row * col; i++) {
        fpo[i] = fpointer[i];
    }
    struct Matrix* mpo = (struct Matrix*)malloc(sizeof(struct Matrix));
    mpo->row = row;
    mpo->col = col;
    mpo->arr = fpo;
    return mpo;
}

void deleteMatrix(struct Matrix* mpointer) {
    if (mpointer == NULL) {
        return;
    }
    if (mpointer->arr != NULL) {
        free(mpointer->arr);
    }
    free(mpointer);
    return;
}