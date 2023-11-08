#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *atualL1 = l1->prox;
    celula *atualL2 = l2->prox;
    celula *atualL3 = l3;

    while (atualL1 != NULL && atualL2 != NULL) {
        if (atualL1->dado <= atualL2->dado) {
            atualL3->prox = atualL1;
            atualL1 = atualL1->prox;
        } else {
            atualL3->prox = atualL2;
            atualL2 = atualL2->prox;
        }
        atualL3 = atualL3->prox;
    }

    if (atualL1 != NULL) {
        atualL3->prox = atualL1;
    } else if (atualL2 != NULL) {
        atualL3->prox = atualL2;
    }
}

void imprimir_lista(celula *l) {
    celula *atual = l->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}