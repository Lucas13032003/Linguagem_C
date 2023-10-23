#include<stdio.h>
#include<stdlib.h>

/*4. Fazer um programa que lê um valor, um operador (+,-,*,/) e outro valor e
imprime o resultado da expressão:
<valor 1> <operador> <valor 2>*/

int main() {
    float v1, v2, resultado;
    char operador;

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);

    printf("Digite o tipo de operação (+, -, *, /): ");
    scanf(" %c", &operador);

    printf("Digite o segundo valor: ");
    scanf("%f", &v2);

    switch (operador) {
        case '+':
            resultado = v1 + v2;
            break;
        case '-':
            resultado = v1 - v2;
            break;
        case '*':
            resultado = v1 * v2;
            break;
        case '/':
            if (v2 != 0) {
                resultado = v1 / v2;
            } else {
                printf("Não é possível dividir por 0.\n");
                return 1;
            }
            break;
        default:
            printf("Operador inválido\n");
            return 1;
    }

    printf("O resultado é: %.2f\n", resultado);

    return 0;
}
