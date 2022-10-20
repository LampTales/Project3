#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

struct Matrix* createMatrix(int row, int col) {
    float* fpo = (float*)malloc(row * col * sizeof(float));
    for (int i = 0; i < row * col; i++) {
        fpo[i] = 0;
    }
    struct Matrix* mpo = (struct Matrix*) malloc (sizeof(struct Matrix));
    mpo->row = row;
    mpo->col = col;
    mpo->arr = fpo;
    return mpo;
}