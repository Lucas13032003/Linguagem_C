#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                trocar(&array[j], &array[j + 1]);
            }
        }
    }
}


int main() {
    int numeros[1000];
    int n = 0;

    // Lê os números da entrada padrão
    while (scanf("%d", &numeros[n]) != EOF) {
        n++;
    }

    // Aplica o algoritmo de ordenação bolha
    bubbleSort(numeros, n);

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
