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
    
    l1->prox = NULL;
    l2->prox = NULL;
    
    while (atual != NULL) {
        celula *prox = atual->prox;
        atual->prox = NULL;
        
        if (atual->dado % 2 != 0) {
            atual_l1->prox = atual;
            atual_l1 = atual_l1->prox;
        } else {
            atual_l2->prox = atual;
            atual_l2 = atual_l2->prox;
        }
        
        atual = prox;
    }
}