#include <stdio.h>
#include "Matrix.h"

int main() {
    float array[] = {1, 2, 3, 4, 5, 6};
    float* fp = array;
    struct Matrix* m = createMatrixWithIni(2, 3, fp);
    struct Matrix* n = copyMatrix(m);
    // Where is this function?
    // printf("%d\n", _msize(m->arr));
    // struct Matrix* m = createMatrix(2, 3);
    // struct Matrix* m = NULL;
    // printf("%d\n", m->row);
    setElement(m, 2, 2, 2.46);
    printf("%f\n", m->arr[4]);
    printf("%f\n", n->arr[4]);
    // printf("%f\n", m->arr[5]);
    deleteMatrix(m);
    deleteMatrix(n);
    return 0;
}