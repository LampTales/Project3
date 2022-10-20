#pragma once

struct Matrix {
    int row;
    int col;
    float* arr;
};

struct Matrix* createMatrix(int row, int col);

struct Matrix* createMatrixWithIni(int row, int col, const float* fpointer);

struct Matrix* deleteMatrix(struct Matrix* mpointer);
