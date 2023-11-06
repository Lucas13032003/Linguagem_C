#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *atual = l->prox;
    celula *atual_l1 = l1;
    celula *atual_l2 = l2;

    while (atual != NULL) {
        if (atual->dado % 2 == 0) { // Número par
            atual_l2->prox = atual;
            atual_l2 = atual_l2->prox;
        } else { // Número ímpar
            atual_l1->prox = atual;
            atual_l1 = atual_l1->prox;
        }

        atual = atual->prox;
    }

    atual_l1->prox = NULL;
    atual_l2->prox = NULL;
}

void imprimir_lista(celula *l) {
    celula *atual = l->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    celula *l = (celula *)malloc(sizeof(celula));
    celula *l1 = (celula *)malloc(sizeof(celula));
    celula *l2 = (celula *)malloc(sizeof(celula));

    l->prox = NULL;
    l1->prox = NULL;
    l2->prox = NULL;

    // Inserir elementos na lista l
    int elementos[] = {10, 4, -9, 2, 7, 10};
    for (int i = 0; i < 6; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->dado = elementos[i];
        nova_celula->prox = l->prox;
        l->prox = nova_celula;
    }

    divide_lista(l, l1, l2);

    printf("l1: ");
    imprimir_lista(l1);

    printf("l2: ");
    imprimir_lista(l2);

    // Liberar a memória alocada para as listas
    celula *atual = l->prox;
    while (atual != NULL) {
        celula *proxima = atual->prox;
        free(atual);
        atual = proxima;
    }

    atual = l1->prox;
    while (atual != NULL) {
        celula *proxima = atual->prox;
        free(atual);
        atual = proxima;
    }

    atual = l2->prox;
    while (atual != NULL) {
        celula *proxima = atual->prox;
        free(atual);
        atual = proxima;
    }

    free(l);
    free(l1);
    free(l2);

    return 0;
}
