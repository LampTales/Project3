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
    if (row <= 0 || col <= 0 || fpointer == NULL) {
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

int setElement(struct Matrix* mpointer, int rowSpot, int colSpot, float value) {
    if (mpointer == NULL || rowSpot <= 0 || rowSpot > mpointer->row || colSpot <= 0 || colSpot > mpointer->col) {
        return 0;
    }
    if (mpointer->arr == NULL) {
        float* fpo = (float*)malloc(mpointer->row * mpointer->col * sizeof(float));
        for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
            fpo[i] = 0;
        }
        mpointer->arr = fpo;
    }
    mpointer->arr[(rowSpot - 1) * mpointer->col + colSpot - 1] = value;
    return 1;
}

float getElement(const struct Matrix* mpointer, int rowSpot, int colSpot) {
    if (mpointer == NULL || rowSpot <= 0 || rowSpot > mpointer->row || colSpot <= 0 || colSpot > mpointer->col || mpointer->arr == NULL) {
        // How can I report this?
        return 0;
    }
    return mpointer->arr[(rowSpot - 1) * mpointer->col + colSpot - 1];
}

int reAssignAll(struct Matrix* mpointer, const float* fpointer) {
    if (fpointer == NULL || mpointer == NULL || mpointer->row <= 0 || mpointer->col <= 0) {
        return 0;
    }
    if (mpointer->arr == NULL) {
        float* fpo = (float*)malloc(mpointer->row * mpointer->col * sizeof(float));
        mpointer->arr = fpo;
    }
    for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
        mpointer->arr[i] = fpointer[i];
    }
    return 0;
}

struct Matrix* copyMatrix(const struct Matrix* mpointer) {
    if (mpointer == NULL || mpointer->row <= 0 || mpointer->col <= 0 || mpointer->arr == NULL) {
        return NULL;
    }
    struct Matrix* m = createMatrixWithIni(mpointer->row, mpointer->col, mpointer->arr);
    return m;
}
