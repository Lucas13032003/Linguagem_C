#include <stdio.h>

int buscaBinaria(int *v, int inicio, int fim, int x) {
    while (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] < x) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    return inicio;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int conjunto[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &conjunto[i]);
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);

        int indice = buscaBinaria(conjunto, 0, N, x);

        printf("%d\n", indice);
    }

    return 0;
}