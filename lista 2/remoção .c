#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

// Declaração da função antes de usá-la no main
int desenfileira(fila *f, int *y);

int desenfileira(fila *f, int *y) {
    if (f == NULL || f->dados == NULL || f->p == f->u) {
        // Verifica se a fila é válida ou está vazia
        return 0;
    }

    // Remove o elemento da fila e salva em y
    *y = f->dados[f->p];
    // Atualiza o ponteiro de início (p) para o próximo elemento
    f->p = (f->p + 1) % f->N;
    
    return 1; // Remoção bem sucedida
}

int main() {
    // Exemplo de uso
    fila minhaFila;
    minhaFila.N = 5; // Tamanho inicial da fila
    minhaFila.dados = (int*)malloc(minhaFila.N * sizeof(int));
    minhaFila.p = minhaFila.u = 0; // Inicializa ponteiros de início e fim

    // Insira elementos na fila...

    int elementoRemovido;
    int remocaoBemSucedida = desenfileira(&minhaFila, &elementoRemovido);

    if (remocaoBemSucedida) {
        printf("Elemento removido: %d\n", elementoRemovido);
    } else {
        printf("Fila vazia ou inválida.\n");
    }

    // Libera a memória alocada para a fila
    free(minhaFila.dados);

    return 0;
}
