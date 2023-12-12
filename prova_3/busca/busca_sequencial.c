#include <stdio.h>
#include <stdlib.h>

int achou(int num, int *v, int l, int r) {
    for (int i = l; i <= r; i++)
        if (v[i] == num)
            return 1;
    return 0;
}

int main(void) {
    int vetor[140000];

    // preparando para gerar números aleatórios
    srand(42); // Usando 42 como semente, você pode escolher outra semente se desejar

    // preenchendo o vetor com números aleatórios inferiores a 1 milhão
    for (int i = 0; i < 140000; i++)
        vetor[i] = rand() % 10;

    // fazendo 140000 buscas pelo número 1 milhão
    for (int i = 0; i < 140000; i++)
        if (!achou(10, vetor, 0, 140000 - 1))
            printf("nao\n");
        else
            printf("sim\n");

    return 0;
}
