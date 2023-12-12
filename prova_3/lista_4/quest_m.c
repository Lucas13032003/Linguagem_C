#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 80

// Estrutura para armazenar as palavras no dicionário
struct Palavra {
    char japones[MAX_LEN];
    char portugues[MAX_LEN];
};

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int M, N;
        scanf("%d %d", &M, &N);

        // Leitura do dicionário
        struct Palavra dicionario[MAX_WORDS];
        for (int i = 0; i < M; i++) {
            scanf("%s", dicionario[i].japones);
            scanf(" %[^\n]", dicionario[i].portugues);  // Lê toda a linha até a quebra de linha
        }

        // Processamento da letra da música
        for (int i = 0; i < N; i++) {
            char linha[MAX_LEN * MAX_WORDS];
            fgets(linha, sizeof(linha), stdin);

            // Tokeniza a linha em palavras
            char *token = strtok(linha, " ");
            while (token != NULL) {
                // Busca a tradução no dicionário
                int encontrado = 0;
                for (int j = 0; j < M; j++) {
                    if (strcmp(token, dicionario[j].japones) == 0) {
                        printf("%s ", dicionario[j].portugues);
                        encontrado = 1;
                        break;
                    }
                }

                // Se a palavra não foi encontrada, imprime como está
                if (!encontrado) {
                    printf("%s ", token);
                }

                token = strtok(NULL, " ");
            }

            printf("\n");  // Quebra de linha entre as linhas traduzidas
        }

        if (t < T - 1) {
            printf("\n");  // Linha em branco entre casos de teste
        }
    }

    return 0;
}
