#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[indiceMenor]) {
                indiceMenor = j;
            }
        }
        trocar(&array[i], &array[indiceMenor]);
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
    selectionSort(numeros, n);

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
