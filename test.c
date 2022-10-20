#include <stdio.h>
#include "Matrix.h"

int main(){
    // float array[] = {1, 2, 3, 4, 5, 6};
    // struct Matrix* m = createMatrixWithIni(2, 3, array);
    struct Matrix* m = createMatrix(2, 3);
    // struct Matrix* m = NULL;
    // printf("%d\n", m->row);
    deleteMatrix(m);
    printf("%f\n", m->arr[5]);
    printf("%d\n", m->row);
    return 0;
}