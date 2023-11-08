#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *temp = le->prox; // Começa no primeiro nó, pulando o nó cabeça
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }

    if (le->dado != 0) {
        printf("%d -> ", le->dado);
    }

    imprime_rec(le->prox);
}
