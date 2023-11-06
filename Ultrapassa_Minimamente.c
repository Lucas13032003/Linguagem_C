#include <stdio.h>

int main() {
    int limite;
    scanf("%d", &limite);

    int valor;
    int soma = 0;
    int encontrado = 0;

    while (1) {
        scanf("%d", &valor);

        if (valor == 0) {
            break;
        }

        if (soma + valor >= limite) {
            encontrado = valor;
            soma = 0;
        } else {
            soma += valor;
        }
    }

    printf("%d\n", encontrado);

    return 0;
}
