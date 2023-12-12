#include <stdio.h>
#include <stdlib.h>

struct Instrucao {
    int codigo;
    char palavraChave[16];
};

int main() {
    int n;
    scanf("%d", &n);

    // Aloca dinamicamente o array de instruções
    struct Instrucao *instrucoes = (struct Instrucao *)malloc(n * sizeof(struct Instrucao));

    // Carrega as instruções na memória
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &instrucoes[i].codigo, instrucoes[i].palavraChave);
    }

    int consulta;

    // Processa as consultas
    while (scanf("%d", &consulta) != EOF) {
        int encontrado = 0;

        // Verifica se o código está presente nas instruções
        for (int i = 0; i < n; i++) {
            if (consulta == instrucoes[i].codigo) {
                printf("%s\n", instrucoes[i].palavraChave);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("undefined\n");
        }
    }

    // Libera a memória alocada
    free(instrucoes);

    return 0;
}
