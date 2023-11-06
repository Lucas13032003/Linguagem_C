#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *atual = le->prox;
    while (atual != NULL) {
        if (atual->dado == x) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; // Elemento não encontrado na lista.
}

celula *busca_rec(celula *le, int x) {
    if (le == NULL) {
        return NULL; // Lista vazia.
    }

    if (le->dado == x) {
        return le;
    }

    return busca_rec(le->prox, x);
}

int main() {
    celula *le = (celula *)malloc(sizeof(celula));
    le->prox = NULL; // Inicializa a lista vazia.

    // Inserir elementos na lista
    for (int i = 1; i <= 5; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = i;
        nova_celula->prox = le->prox;
        le->prox = nova_celula;
    }

    int elemento = 3;
    celula *resultado = busca(le, elemento);

    if (resultado != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultado->dado);
    } else {
        printf("Elemento %d não encontrado na lista.\n", elemento);
    }

    resultado = busca_rec(le, elemento);

    if (resultado != NULL) {
        printf("Elemento %d encontrado na lista (recursivo).\n", resultado->dado);
    } else {
        printf("Elemento %d não encontrado na lista (recursivo).\n", elemento);
    }

    // Liberar a memória alocada para a lista encadeada
    celula *atual = le;
    while (atual != NULL) {
        celula *proxima = atual->prox;
        free(atual);
        atual = proxima;
    }

    return 0;
}
