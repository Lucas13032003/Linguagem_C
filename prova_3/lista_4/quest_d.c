#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para mesclar dois subarrays ordenados
void merge(int array[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria arrays temporários
    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Mescla os arrays temporários de volta em array[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória dos arrays temporários
    free(L);
    free(R);
}

// Função principal do Merge Sort que classifica o array[left..right] usando a mesclagem
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        // Calcula o ponto médio do array
        int mid = left + (right - left) / 2;

        // Classifica a metade esquerda e a metade direita
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(array, left, mid, right);
    }
}

int main() {
    int n;

    // Lê a quantidade de elementos
    scanf("%d", &n);

    int *numeros = (int *)malloc(sizeof(int) * n);

    // Lê os números da entrada
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Aplica o algoritmo de ordenação Merge Sort
    mergeSort(numeros, 0, n - 1);

    // Imprime os números ordenados
    for (int i = 0; i < n; i++) {
        printf("%d", numeros[i]);

        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    // Libera a memória alocada
    free(numeros);

    return 0;
}
