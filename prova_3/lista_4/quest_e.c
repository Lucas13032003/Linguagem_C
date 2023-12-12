#include <stdio.h>

void insercaoRecursiva(int *v, int n) {
    if (n <= 1) {
        return;
    }

    // Ordena recursivamente os n-1 elementos
    insercaoRecursiva(v, n - 1);

    // Insere o último elemento v[n-1] na posição correta
    int chave = v[n - 1];
    int j = n - 2;

    // Move os elementos maiores que a chave para a frente
    while (j >= 0 && v[j] > chave) {
        v[j + 1] = v[j];
        j--;
    }

    // Coloca a chave na posição correta
    v[j + 1] = chave;
}

void ordena(int *v, int n) {
    insercaoRecursiva(v, n);
}

int main() {
    int n;

    // Lê a quantidade de elementos
    scanf("%d", &n);

    int numeros[n];

    // Lê os números da entrada
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Chama a função de ordenação
    ordena(numeros, n);

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
