#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar informações sobre uma sequência
typedef struct {
    char caractere;
    int tamanho;
    int posicao;
} Sequencia;

// Função de comparação para usar com qsort
int compararSequencias(const void *a, const void *b) {
    const Sequencia *seqA = (const Sequencia *)a;
    const Sequencia *seqB = (const Sequencia *)b;

    // Ordena por tamanho de forma decrescente
    if (seqA->tamanho > seqB->tamanho) {
        return -1;
    } else if (seqA->tamanho < seqB->tamanho) {
        return 1;
    }

    // Em caso de empate, ordena por posição de forma crescente
    return seqA->posicao - seqB->posicao;
}

// Função principal para analisar dados de degustação
void analisarDegustacao(char *string) {
    // Número máximo de caracteres na string
    int maxCaracteres = 26 * 2;  // Considerando letras maiúsculas e minúsculas

    // Inicializar array para armazenar informações sobre as sequências
    Sequencia sequencias[maxCaracteres];

    // Inicializar contadores para cada caractere
    int contadores[maxCaracteres];
    for (int i = 0; i < maxCaracteres; i++) {
        contadores[i] = 0;
    }

    // Iterar sobre a string e contar as sequências
    int posicao = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        char caractere = string[i] - 'A';  // Normalizar para índices de 0 a 25

        if (contadores[caractere] == 0) {
            // Início de uma nova sequência
            sequencias[posicao].caractere = string[i];
            sequencias[posicao].posicao = i;
            sequencias[posicao].tamanho = 1;
            contadores[caractere]++;
            posicao++;
        } else {
            // Continuação da sequência
            sequencias[posicao - 1].tamanho++;
        }
    }

    // Ordenar as sequências usando qsort
    qsort(sequencias, posicao, sizeof(Sequencia), compararSequencias);

    // Imprimir os resultados
    for (int i = 0; i < posicao; i++) {
        printf("%d %c %d\n", sequencias[i].tamanho, sequencias[i].caractere, sequencias[i].posicao);
    }
}

int main() {
    char string[100001];  // Tamanho máximo da string conforme a restrição do problema

    // Lê a string da entrada padrão
    fgets(string, sizeof(string), stdin);

    // Chama a função para analisar a degustação
    analisarDegustacao(string);

    return 0;
}
