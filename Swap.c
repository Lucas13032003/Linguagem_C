#include <stdio.h>

void inverte(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    inverte(&a, &b);

    printf("Valor de %d: \n", a);
    printf("Valor de %d: \n", b);

    return 0;
}
