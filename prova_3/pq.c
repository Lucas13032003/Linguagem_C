#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if (less(B, A)) exch(A, B); }

typedef int Item;  // Assumindo que Item é do tipo int

struct pq_lt {
    Item *pq;
    int n;
};

void fixUp(Item *pq, int k) {
    while (k > 1 && less(pq[k / 2], pq[k])) {
        exch(pq[k], pq[k / 2]);
        k = k / 2;
    }
}

void fixDown(Item *pq, int k, int n) {
    int j;
    while (2 * k <= n) {
        j = 2 * k;
        if (j < n && less(pq[j], pq[j + 1])) {
            j++;
        }
        if (!less(pq[k], pq[j])) {
            break;
        }
        exch(pq[k], pq[j]);
        k = j;
    }
}

void pq_init(int max_N, struct pq_lt *pq) {
    pq->pq = malloc(sizeof(Item) * (max_N + 1));
    pq->n = 0;
}

int pq_empty(struct pq_lt *pq) {
    return pq->n == 0;
}

void pq_insert(struct pq_lt *pq, Item novo) {
    pq->pq[++pq->n] = novo;
    fixUp(pq->pq, pq->n);
}

Item pq_remove(struct pq_lt *pq) {
    exch(pq->pq[1], pq->pq[pq->n]);
    fixDown(pq->pq, 1, --pq->n);
    return pq->pq[pq->n + 1];
}

void pq_change(struct pq_lt *pq, int k, Item x) {
    // Verifica se o índice k é válido
    if (k < 1 || k > pq->n) {
        printf("Índice inválido\n");
        return;
    }
    // Atualiza o valor do elemento no índice k
    pq->pq[k] = x;

    // Verifica se é necessário realizar ajustes na fila (fixUp ou fixDown)
    fixUp(pq->pq, k);
    fixDown(pq->pq, k, pq->n);
}

int main() {
    struct pq_lt min_pq;
    int max_N = 100; // ajuste este valor conforme necessário

    pq_init(max_N, &min_pq);

    // Insere elementos na fila de prioridade
    pq_insert(&min_pq, 10);
    pq_insert(&min_pq, 5);
    pq_insert(&min_pq, 20);

    // Remove e imprime os elementos da fila de prioridade
    while (!pq_empty(&min_pq)) {
        printf("%d ", pq_remove(&min_pq));
    }

    // Insere mais elementos para testar a função pq_change
    pq_insert(&min_pq, 15);
    pq_insert(&min_pq, 25);
    pq_insert(&min_pq, 30);

    // Altera o valor do segundo elemento (índice 2) para 12
    pq_change(&min_pq, 2, 12);

    printf("\n");

    // Remove e imprime os elementos novamente
    while (!pq_empty(&min_pq)) {
        printf("%d ", pq_remove(&min_pq));
    }

    return 0;
}

