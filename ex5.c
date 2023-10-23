#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* 5. Fazer um programa em "C" que solicite 2 números e informe:
   a) A soma dos números;
   b) O produto do primeiro número pelo quadrado do segundo;
   c) O quadrado do primeiro número;
   d) A raiz quadrada da soma dos quadrados;
   e) O seno da diferença do primeiro número pelo segundo;
   f) O módulo do primeiro número.
*/

int main() {
    float a, b;
    float soma, produto, quadrado, raiz, seno, modulo;

    printf("Digite o primeiro número:\n");
    scanf("%f", &a);

    printf("Digite o segundo número:\n");
    scanf("%f", &b);

    soma = a + b;
    produto = a * (b * b);
    quadrado = a * a;
    raiz = sqrt(a * a + b * b);
    seno = sin(a - b);
    modulo = fabs(a);

    printf("Soma: %f\n", soma);
    printf("O produto do primeiro número pelo quadrado do segundo: %f\n", produto);
    printf("O quadrado do primeiro número: %f\n", quadrado);
    printf("A raiz quadrada da soma dos quadrados: %f\n", raiz);
    printf("O seno da diferença do primeiro número pelo segundo: %f\n", seno);
    printf("O módulo do primeiro número: %f\n", modulo);

    return 0;
}
