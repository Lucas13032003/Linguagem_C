#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    }

    return buscar(raiz->direita, chave);
}

No* encontrarMenorNo(No* no) {
    No* atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        // Nó com apenas um filho ou nenhum filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos: encontra o sucessor in-order (menor nó na subárvore direita)
        No* temp = encontrarMenorNo(raiz->direita);

        // Copia o conteúdo do sucessor para este nó
        raiz->chave = temp->chave;

        // Remove o sucessor
        raiz->direita = remover(raiz->direita, temp->chave);
    }
    return raiz;
}

void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Árvore em ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    int chaveRemover = 50;
    raiz = remover(raiz, chaveRemover);
    printf("Árvore após remover %d: ", chaveRemover);
    percorrerEmOrdem(raiz);
    printf("\n");

    // Liberar memória (pode ser feito recursivamente)
    free(raiz);

    return 0;
}
