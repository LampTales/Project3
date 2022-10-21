#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "innerTools.h"

int addScalar(struct Matrix* mpointer, float scalar) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        return 0;
    }
    for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
        mpointer->arr[i] = mpointer->arr[i] + scalar;
    }
    return 1;
}

int minusScalar(struct Matrix* mpointer, float scalar) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        return 0;
    }
    for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
        mpointer->arr[i] = mpointer->arr[i] - scalar;
    }
    return 1;
}

int mulScalar(struct Matrix* mpointer, float scalar) {
    if (isLegalMatrixWithData(mpointer) == 0) {
        return 0;
    }
    for (int i = 0; i < (mpointer->row) * (mpointer->col); i++) {
        mpointer->arr[i] = mpointer->arr[i] * scalar;
    }
    return 1;
}

struct Matrix* addMatrix(const struct Matrix* mp1, const struct Matrix* mp2) {
    if (isLegalMatrixWithData(mp1) || isLegalMatrixWithData(mp2) || mp1->row != mp2->row || mp1->col != mp2->col) {
        return NULL;
    }
    struct Matrix* ansM = createRawMatrix(mp1->row, mp1->col);
    for (int i = 0; i < (mp1->row) * (mp2->col); i++) {
        ansM->arr[i] = mp1->arr[i] + mp2->arr[i];
    }
    return ansM;
}

struct Matrix* subtractMatrix(const struct Matrix* mp1, const struct Matrix* mp2) {
    if (isLegalMatrixWithData(mp1) || isLegalMatrixWithData(mp2) || mp1->row != mp2->row || mp1->col != mp2->col) {
        return NULL;
    }
    struct Matrix* ansM = createRawMatrix(mp1->row, mp1->col);
    for (int i = 0; i < (mp1->row) * (mp2->col); i++) {
        ansM->arr[i] = mp1->arr[i] - mp2->arr[i];
    }
    return ansM;
}