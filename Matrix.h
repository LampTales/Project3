#pragma once

struct Matrix {
    int row;
    int col;
    float* arr;
};

struct Matrix* createMatrix(int row, int col); // done

// Provide a float pointer with the data in the matrix, and this function can input them to the Matrix.
struct Matrix* createMatrixWithIni(int row, int col, const float* fpointer); // done

// Please remember to delete the Matrix when you finish using it.
void deleteMatrix(struct Matrix* mpointer); // done

// If the function failed to set the value, it will return 0, else 1.
int setElement(struct Matrix* mpointer, int rowSpot, int colSpot, float value); // done

// If the function failed to set the values, it will return 0, else 1.
int reAssignAll(struct Matrix* mpointer, const float* fpointer); // done

float getElement(const struct Matrix* mpointer, int rowSpot, int colSpot); // done?

void printMatrix(const struct Matrix* mpointer); // done

struct Matrix* copyMatrix(const struct Matrix* mpointer); // done

float getMinimum(const struct Matrix* mpointer); // done

float getMaximum(const struct Matrix* mpointer); // done

// If the function failed to apply the operation, it will return 0, else 1.
int addScalar(struct Matrix* mpointer, float scalar);

// If the function failed to apply the operation, it will return 0, else 1.
int minusScalar(struct Matrix* mpointer, float scalar);

// If the function failed to apply the operation, it will return 0, else 1.
int mulScalar(struct Matrix* mpointer, float scalar);

// If the function failed to apply the operation, it will return NULL.
struct Matrix* addMatrix(const struct Matrix* mp1, const struct Matrix* mp2);
struct Matrix* subtractMatrix(const struct Matrix* mp1, const struct Matrix* mp2);
struct Matrix* multiplyMatrix(const struct Matrix* mp1, const struct Matrix* mp2);


