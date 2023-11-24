#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um item na fila de prioridade
struct Item {
    int valor;
    int prioridade;
};

// Estrutura para representar a fila de prioridade
struct FilaPrioridade {
    struct Item* fila;
    int capacidade;
    int tamanho;
};

// Função para criar uma nova fila de prioridade
struct FilaPrioridade* criarFila(int capacidade) {
    struct FilaPrioridade* fila = (struct FilaPrioridade*)malloc(sizeof(struct FilaPrioridade));
    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->fila = (struct Item*)malloc(capacidade * sizeof(struct Item));
    return fila;
}

// Função para trocar dois itens
void trocarItens(struct Item* item1, struct Item* item2) {
    struct Item temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

// Função para subir um item na fila de prioridade
void subirItem(struct FilaPrioridade* fila, int indice) {
    int pai = (indice - 1) / 2;
    if (fila->fila[pai].prioridade > fila->fila[indice].prioridade) {
        trocarItens(&fila->fila[pai], &fila->fila[indice]);
        subirItem(fila, pai);
    }
}

// Função para descer um item na fila de prioridade
void descerItem(struct FilaPrioridade* fila, int indice) {
    int filhoEsquerda = 2 * indice + 1;
    int filhoDireita = 2 * indice + 2;
    int menor = indice;

    if (filhoEsquerda < fila->tamanho && fila->fila[filhoEsquerda].prioridade < fila->fila[menor].prioridade) {
        menor = filhoEsquerda;
    }

    if (filhoDireita < fila->tamanho && fila->fila[filhoDireita].prioridade < fila->fila[menor].prioridade) {
        menor = filhoDireita;
    }

    if (menor != indice) {
        trocarItens(&fila->fila[indice], &fila->fila[menor]);
        descerItem(fila, menor);
    }
}

// Função para adicionar um item à fila de prioridade
void adicionarItem(struct FilaPrioridade* fila, int valor, int prioridade) {
    if (fila->tamanho == fila->capacidade) {
        printf("A fila de prioridade está cheia.\n");
        return;
    }

    struct Item item;
    item.valor = valor;
    item.prioridade = prioridade;

    fila->fila[fila->tamanho] = item;
    fila->tamanho++;
    subirItem(fila, fila->tamanho - 1);
}

// Função para remover o item de maior prioridade da fila
int removerItem(struct FilaPrioridade* fila) {
    if (fila->tamanho == 0) {
        printf("A fila de prioridade está vazia.\n");
        return -1;
    }

    int valorRemovido = fila->fila[0].valor;
    fila->fila[0] = fila->fila[fila->tamanho - 1];
    fila->tamanho--;
    descerItem(fila, 0);

    return valorRemovido;
}

// Função para verificar se a fila de prioridade está vazia
int estaVazia(struct FilaPrioridade* fila) {
    return fila->tamanho == 0;
}

// Função para obter o tamanho da fila de prioridade
int tamanhoFila(struct FilaPrioridade* fila) {
    return fila->tamanho;
}

int main() {
    int codigo, prio;
    struct FilaPrioridade* fila = criarFila(5);

    for (int i = 0; i < 5; i++)
    {
    printf("Digite o código:");
    scanf("%d", & codigo);

    printf("Digite a prioridade:");
    scanf("%d", & prio);
    printf("\n");
    adicionarItem(fila, codigo, prio);
    }


    while (!estaVazia(fila)) {
        int valor = removerItem(fila);
        printf("%d ", valor); // Imprime os itens em ordem de prioridade: 20, 10, 30
    }
        printf ("\n");

    free(fila->fila);
    free(fila);

    return 0;
}