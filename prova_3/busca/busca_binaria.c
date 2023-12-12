#include <stdio.h>
#include <stdlib.h>

#define lesseq(A, B) ((A) <= (B))  // Supondo que você tenha uma definição para lesseq

// Supondo que você tenha uma implementação para mergesort
void mergesort(int *v, int l, int r);

int buscabinaria(int num, int *v, int l, int r) {
    if (l > r)
        return -1;

    int meio = (l + r) / 2;

    if (lesseq(v[meio], num))
        return meio;
    else
        return buscabinaria(num, v, l, meio - 1);
}

int main(void) {
    int vetor[140000];

    // Preparando para gerar números aleatórios
    srand(42);  // Usando 42 como semente, você pode escolher outra semente se desejar

    // Preenchendo o vetor com números aleatórios inferiores a 1 milhão
    for (int i = 0; i < 140000; i++)
        vetor[i] = rand() % 1000000;

    // Tenha cuidado com a chamada do MergeSort, o intervalo é FECHADO [l, r]
    // Por isso, é subtraído 1 do tamanho do vetor, para ficar [0, 139999]
    // que representa os 140000 elementos.
    mergesort(vetor, 0, 140000 - 1);

    // Fazendo 140000 buscas pelo número 1 milhão
    for (int i = 0; i < 140000; i++)
        if (buscabinaria(1000000, vetor, 0, 140000 - 1) == -1)
            printf("nao\n");
        else
            printf("sim\n");

    return 0;
}
