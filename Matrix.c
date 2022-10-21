#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "innerTools.h"

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
    if (isLegalMatrix(mpointer) == 0 || hasSuchSpot(mpointer, rowSpot, colSpot) == 0) {
        return 0;
    }
    if (mpointer->arr == NULL) {
        float* fpo = (float*)malloc(mpointer->row * mpointer->col * sizeof(float));
        for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
            fpo[i] = 0;
        }
        mpointer->arr = fpo;
    }
    mpointer->arr[(rowSpot - 1) * (mpointer->col) + colSpot - 1] = value;
    return 1;
}

float getElement(const struct Matrix* mpointer, int rowSpot, int colSpot) {
    if (isLegalMatrixWithData(mpointer) == 0 || hasSuchSpot(mpointer, rowSpot, colSpot) == 0) {
        printf("From call of Matrix::getElement : No such element exist, 0 is return!\n");
        return 0;
    }
    return mpointer->arr[(rowSpot - 1) * (mpointer->col) + colSpot - 1];
}

int reAssignAll(struct Matrix* mpointer, const float* fpointer) {
    if (fpointer == NULL || isLegalMatrix(mpointer) == 0) {
        return 0;
    }
    if (mpointer->arr == NULL) {
        float* fpo = (float*)malloc(mpointer->row * mpointer->col * sizeof(float));
        mpointer->arr = fpo;
    }
    for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
        mpointer->arr[i] = fpointer[i];
    }
    return 1;
}

struct Matrix* copyMatrix(const struct Matrix* mpointer) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        return NULL;
    }
    struct Matrix* m = createMatrixWithIni(mpointer->row, mpointer->col, mpointer->arr);
    return m;
}

void printMatrix(const struct Matrix* mpointer) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        return;
    }
    for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
        printf("%f\t", mpointer->arr[i]);
        if ((i + 1) % mpointer->col == 0) {
            printf("\n");
        }
    }
}

float getMinimum(const struct Matrix* mpointer) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        printf("From call of Matrix::getMinimum : no elements exist, 0 is return!\n");
        return 0;
    }
    float ans = mpointer->arr[0];
    for (int i = 1; i < (mpointer->row) * (mpointer->col); i++) {
        if (mpointer->arr[i] < ans) {
            ans = mpointer->arr[i];
        }
    }
    return ans;
}

float getMaximum(const struct Matrix* mpointer) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        printf("From call of Matrix::getMinimum : no elements exist, 0 is return!\n");
        return 0;
    }
    float ans = mpointer->arr[0];
    for (int i = 1; i < (mpointer->row) * (mpointer->col); i++) {
        if (mpointer->arr[i] > ans) {
            ans = mpointer->arr[i];
        }
    }
    return ans;
}
