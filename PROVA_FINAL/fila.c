#include <stdio.h>
#include <stdlib.h>

// Supondo a definição do tipo Item
typedef struct {
    // Defina a estrutura do tipo Item conforme necessário
    int dado;  // Exemplo: um campo de dados inteiro
} Item;

typedef struct {
    Item *item;
    int primeiro;
    int ultimo;
} Fila;

Fila *criar(int maxN) {
    Fila *p = malloc(sizeof *p);
    p->item = malloc(maxN * sizeof(Item));
    p->primeiro = 0;
    p->ultimo = 0;
    return p;
}

int vazia(Fila *f) {
    return f->primeiro == f->ultimo;
}

int desenfileira(Fila *f) {
    if (vazia(f)) {
        // Tratar subfluxo (fila vazia)
        fprintf(stderr, "Erro: fila vazia\n");
        exit(EXIT_FAILURE);
    }
    return f->item[f->primeiro++].dado;
}

void enfileira(Fila *f, int y) {
    // Supondo que Item tenha um campo de dados
    f->item[f->ultimo++].dado = y;
}

int main() {
    Fila *fila1 = criar(100);
    Fila *fila2 = criar(400);

    // Exemplo de uso: operações de enfileirar e desenfileirar
    enfileira(fila1, 10);
    enfileira(fila1, 20);

    printf("Elemento desenfileirado da fila1: %d\n", desenfileira(fila1));

    enfileira(fila2, 30);
    enfileira(fila2, 40);

    printf("Elemento desenfileirado da fila2: %d\n", desenfileira(fila2));

    // Não se esqueça de liberar a memória alocada quando terminar
    free(fila1->item);
    free(fila1);

    free(fila2->item);
    free(fila2);

    return 0;
}
