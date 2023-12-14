#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char caractere;
    int tamanho;
    long int posicao;
} Sequencia;

int compararSequencias(const void *a, const void *b) {
    const Sequencia *seqA = (const Sequencia *)a;
    const Sequencia *seqB = (const Sequencia *)b;

    if (seqA->tamanho != seqB->tamanho) {
        return seqB->tamanho - seqA->tamanho;
    } else {
        return seqA->posicao - seqB->posicao;
    }
}

void analisarDados(char *entrada) {
    int tamanho = 0;
    while (entrada[tamanho] != '\n') {
        tamanho++;
    }

    Sequencia *sequencias = (Sequencia *)malloc(tamanho * sizeof(Sequencia));

    int numSequencias = 0;
    int i = 0;
    while (i < tamanho) {
        sequencias[numSequencias].posicao = i;
        sequencias[numSequencias].caractere = entrada[i];
        sequencias[numSequencias].tamanho = 1;

        while (i + 1 < tamanho && entrada[i] == entrada[i + 1]) {
            sequencias[numSequencias].tamanho++;
            i++;
        }

        numSequencias++;
        i++;
    }

    qsort(sequencias, numSequencias, sizeof(Sequencia), compararSequencias);

    for (int j = 0; j < numSequencias; j++) {
        printf("%d %c %ld\n", sequencias[j].tamanho, sequencias[j].caractere, sequencias[j].posicao);
    }

    free(sequencias);
}

int main() {
    char entrada[1000001];
    fgets(entrada, sizeof(entrada), stdin);

    analisarDados(entrada);

    return 0;
}