#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { int t = A; A = B; B = t; }

typedef int Item;

void fixDown(Item *v, int k, int n) {
    int j;
    while (2 * k <= n) {
        j = 2 * k;
        if (j < n && less(v[j], v[j + 1])) {
            j++;
        }
        if (!less(v[k], v[j])) {
            break;
        }
        exch(v[k], v[j]);
        k = j;
    }
}

void heapSort(Item *v, int n) {
    int k;

    // Constrói a heap
    for (k = n / 2; k >= 1; k--) {
        fixDown(v, k, n);
    }

    // Remove da heap e insere no final do array ordenado
    while (n > 1) {
        exch(v[1], v[n]);
        fixDown(v, 1, --n);
    }
}

int main() {
    Item v[] = {0, 38, 27, 43, 3, 9, 82, 10}; // O índice 0 não é utilizado
    int n = sizeof(v) / sizeof(v[0]) - 1; // Desconsidera o índice 0

    // Ordena o array usando o Heap Sort
    heapSort(v, n);

    // Imprime o array ordenado
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
