#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if (less(B, A)) exch(A, B); }

void soma(int a, int b, int *result) {
    *result = a + b;
}

void mult(int a, int b, int *result) {
    *result = a * b;
}

int main() {
    int a, b, result_s, result_m;
    a = 2;
    b = 10;

    soma(a, b, &result_s);
    mult(a, b, &result_m);

    printf("%d\n", result_s);
    printf("%d\n", result_m);

    return 0;
}
