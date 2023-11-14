#include <stdio.h>

float maior(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    float a, b, s;

    printf("Digite o valor de a: \n");
    scanf(" %f", &a);

    printf("Digite o valor de b: \n");
    scanf(" %f", &b);

    s = maior(a, b);

    printf("O maior valor: %.2f\n", s);

    return 0;
}
