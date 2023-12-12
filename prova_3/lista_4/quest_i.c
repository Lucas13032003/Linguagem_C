#include <stdio.h>

int main() {
    int n, q;

    // Leitura de n e q
    scanf("%d %d", &n, &q);

    // Leitura do conjunto de dados
    int conjunto[n];
    int posicoes[n + 1]; // Array para armazenar as posições dos números no conjunto

    for (int i = 0; i < n; i++) {
        scanf("%d", &conjunto[i]);
        posicoes[conjunto[i]] = i + 1; // Armazena a posição do número no conjunto
    }

    // Processamento das consultas
    for (int i = 0; i < q; i++) {
        int consulta;
        scanf("%d", &consulta);

        // Verifica se o número pertence ao conjunto e imprime a posição
        if (consulta >= 1 && consulta <= n) {
            printf("%d\n", posicoes[consulta]);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
