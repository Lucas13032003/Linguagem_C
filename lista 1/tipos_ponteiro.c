#include <stdio.h>

int main() {
    int x;
    double y = 20.8;
    char z = 'a';

    int *px = &x;
    double *py = &y;
    char *pz = &z;

    printf("Valores: %d, %.2lf, %c\n", *px, *py, *pz);
    printf("Endereços: %p, %p, %p\n", px, py, pz);

    return 0;
}
