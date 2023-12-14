#include <stdio.h>

void insereOrdenado(int *v, int n, int elemento) {
    if (n <= 0 || elemento >= v[n - 1]) {
        v[n] = elemento;
        return;
    }

    if (elemento < v[n - 1]) {
        int temp = v[n - 1];
        v[n - 1] = elemento;
        v[n] = temp;
        insereOrdenado(v, n - 1, elemento);
    }
}

void ordena(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int elementoAtual = v[i];
        insereOrdenado(v, i, elementoAtual);
    }
}