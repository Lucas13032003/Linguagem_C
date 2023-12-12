#include <stdio.h>

// Função de busca binária que retorna o índice tal que arr[indice - 1] < x <= arr[indice]
int buscaBinaria(int arr[], int tamanho, int x) {
    int esquerda = 0;
    int direita = tamanho;

    while (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] <= x) {
            esquerda = meio + 1;
        } else {
            direita = meio;
        }
    }

    return esquerda;
}

int main() {
    int n, q;

    // Leitura de n e q
    scanf("%d %d", &n, &q);

    // Leitura do conjunto de dados
    int conjunto[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &conjunto[i]);
    }

    // Processamento das consultas
    for (int i = 0; i < q; i++) {
        int consulta;
        scanf("%d", &consulta);

        // Busca binária
        int indice = buscaBinaria(conjunto, n, consulta);

        // Imprime o resultado
        printf("%d\n", indice);
    }

    return 0;
}
