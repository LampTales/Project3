#pragma once

struct Matrix {
    int row;
    int col;
    float* arr;
};

struct Matrix* createMatrix(int row, int col); // done

struct Matrix* createMatrixWithIni(int row, int col, const float* fpointer); // done

void deleteMatrix(struct Matrix* mpointer); // done

int setElement(struct Matrix* mpointer, int rowSpot, int colSpot, float value); // done
int reAssignAll(struct Matrix* mpointer, const float* fpointer);
struct Matrix* copyMatrix(const struct Matrix* mpointer);
struct Matrix* addMatrix(const struct Matrix* mp1, const struct Matrix* mp2);
struct Matrix* subtractMatrix(const struct Matrix* mp1, const struct Matrix* mp2);
struct Matrix* multiplyMatrix(const struct Matrix* mp1, const struct Matrix* mp2);
void addScalar(struct Matrix* mpointer, float scalar);
void minusScalar(struct Matrix* mpointer, float scalar);
void mulScalar(struct Matrix* mpointer, float scalar);
float getMinimum(const struct Matrix* mpointer);
float getMaximum(const struct Matrix* mpointer);
