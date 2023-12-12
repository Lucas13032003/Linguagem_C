#include <stdio.h>

#define MAX 10000
#define R 5

int aux[MAX];

void countingsort(int *v, int l, int r) {
    int i, count[R + 1];

    // Zerando o array de contagem
    for (i = 0; i <= R; i++)
        count[i] = 0;

    // Contagem de frequências
    for (i = l; i <= r; i++)
        count[v[i] + 1]++;

    // Posições finais
    for (i = 1; i <= R; i++)
        count[i] += count[i - 1];

    // Distribuição
    for (i = l; i <= r; i++) {
        aux[count[v[i]]] = v[i];
        count[v[i]]++;
    }

    // Cópia de volta para o array original
    for (i = l; i <= r; i++)
        v[i] = aux[i - l];
}

int main() {
    // Exemplo de uso
    int v[] = {2, 4, 1, 5, 3, 2, 4, 3, 1, 5};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // Chamando Counting Sort
    countingsort(v, 0, n - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
