#include <stdio.h>
#include "Matrix.h"

int main(){
    struct Matrix* m = createMatrix(2, 3);
    printf("%d\n", m->row);
    printf("%f\n", m->arr[5]);
    return 0;
}