#include <stdio.h>

int somaDigitos(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + somaDigitos(n / 10);
}

int main() {
    int numero;
    scanf("%d", &numero);

    int resultado = somaDigitos(numero);

    printf("%d\n", resultado);

    return 0;
}
