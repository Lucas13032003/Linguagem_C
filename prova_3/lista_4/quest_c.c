#include <stdio.h>

void insertionSort(int array[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }
}

int main() {
    int numeros[50000];
    int n = 0;

    // Lê os números da entrada padrão
    while (scanf("%d", &numeros[n]) != EOF) {
        n++;
    }

    // Aplica o algoritmo de ordenação por inserção
    insertionSort(numeros, n);

    // Imprime os números ordenados
    for (int i = 0; i < n; i++) {
        printf("%d", numeros[i]);

        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
