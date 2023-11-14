#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *nova_celula = malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro: Não foi possível alocar memória para a nova célula.\n");
        exit(EXIT_FAILURE);
    }
    nova_celula->dado = x;
    nova_celula->prox = le->prox;
    le->prox = nova_celula;
}

void insere_antes(celula *le, int x, int y) {
    celula *nova_celula = malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro: Não foi possível alocar memória para a nova célula.\n");
        exit(EXIT_FAILURE);
    }
    nova_celula->dado = x;

    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL && atual->dado != y) {
        anterior = atual;
        atual = atual->prox;
    }

    nova_celula->prox = atual;
    anterior->prox = nova_celula;
}