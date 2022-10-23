#include <stdio.h>
#include "Matrix.h"



int main() {
    float array[] = {1, 2, 3, 4, 5, 6};
    float arrayw[] = {2, 3, 4, 5, 6, 7};
    // float arrayx[] = {2, 3, 4, 5};
    float* fp = array;
    float* fpw = arrayw;
    struct Matrix* m = createMatrixWithIni(2, 3, fp);
    struct Matrix* w = createMatrixWithIni(3, 2, fpw);
    struct Matrix* x = createMatrix(2, 2);
    struct Matrix* ans = createMatrix(2, 2);
    printf("ans = \n");
    printMatrix(ans);
    // printError(setElement(m, 7, 8, 0.5));
    // printError(setElement(m, 1, 2, 0.5));
    printError(multiplyMatrix(m, x, ans));

    printError(multiplyMatrix(m, w, ans));
    printf("ans = \n");
    printMatrix(ans);
    printError(multiplyMatrix(m, ans, ans));
    deleteMatrix(&ans);
    printError(multiplyMatrix(m, w, ans));

    deleteMatrix(&m);
    deleteMatrix(&w);
    deleteMatrix(&x);
    return 0;
}