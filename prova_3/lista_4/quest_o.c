#include <stdio.h>
#include <stdlib.h>

// Função para comparar inteiros (utilizada pelo qsort)
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para verificar se um número já existe em um vetor
int contem(int *vetor, int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1; // Retorna 1 se o número já existe
        }
    }
    return 0; // Retorna 0 se o número não existe
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Ordena o vetor
    qsort(vetor, n, sizeof(int), comparar);

    // Se a quantidade de elementos for ímpar, adiciona 1 bilhão ao final
    if (n % 2 != 0) {
        vetor[n] = 1000000000;
        n++;
    }

    int nmur[2 * n];
    int tamanho_nmur = 0;

    // Calcula a soma de números adjacentes
    for (int i = 0; i < n; i += 2) {
        nmur[tamanho_nmur++] = vetor[i] + vetor[i + 1];
    }

    // Reinserindo os números
    for (int i = 0; i < tamanho_nmur; i++) {
        if (!contem(vetor, n, nmur[i])) {
            vetor[n++] = nmur[i];
        }
    }

    // Ordena novamente o vetor resultante
    qsort(vetor, n, sizeof(int), comparar);

    // Imprime os elementos nos índices de quatro em quatro
    for (int i = 0; i < n; i += 4) {
        printf("%d\n", vetor[i]);
    }

    // Imprime o número de elementos únicos do vetor resultante
    printf("Elementos: %d\n", n);

    return 0;
}
