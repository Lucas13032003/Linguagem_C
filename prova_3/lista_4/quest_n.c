#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um candidato
struct Candidato {
    int codigo;
    int votos;
};

// Função de comparação para qsort
int compararCandidatos(const void *a, const void *b) {
    return ((struct Candidato *)b)->votos - ((struct Candidato *)a)->votos;
}

int main() {
    int senadores, depFed, depEst;
    scanf("%d %d %d", &senadores, &depFed, &depEst);

    // Inicializa a contagem de votos
    int votosValidos = 0, votosInvalidos = 0;

    // Inicializa os arrays de candidatos para cada cargo
    struct Candidato presidente = {0, 0};
    struct Candidato senador[senadores];
    struct Candidato depFed[depFed];
    struct Candidato depEst[depEst];

    // Leitura dos votos
    int voto;
    while (scanf("%d", &voto) == 1) {
        if (voto >= 0) {  // Voto válido
            votosValidos++;

            // Contabiliza os votos para cada cargo
            int partido = voto / 10000;
            if (partido == presidente.codigo) {
                presidente.votos++;
            } else if (partido > 0 && partido < 100) {
                for (int i = 0; i < senadores; i++) {
                    if (senador[i].codigo == partido) {
                        senador[i].votos++;
                        break;
                    } else if (senador[i].codigo == 0) {
                        senador[i].codigo = partido;
                        senador[i].votos = 1;
                        break;
                    }
                }
            } else if (partido >= 100 && partido < 1000) {
                for (int i = 0; i < depFed; i++) {
                    if (depFed[i].codigo == partido) {
                        depFed[i].votos++;
                        break;
                    } else if (depFed[i].codigo == 0) {
                        depFed[i].codigo = partido;
                        depFed[i].votos = 1;
                        break;
                    }
                }
            } else if (partido >= 1000 && partido < 10000) {
                for (int i = 0; i < depEst; i++) {
                    if (depEst[i].codigo == partido) {
                        depEst[i].votos++;
                        break;
                    } else if (depEst[i].codigo == 0) {
                        depEst[i].codigo = partido;
                        depEst[i].votos = 1;
                        break;
                    }
                }
            }
        } else {  // Voto inválido
            votosInvalidos++;
        }
    }

    // Ordena os candidatos por votos
    qsort(senador, senadores, sizeof(struct Candidato), compararCandidatos);
    qsort(depFed, depFed, sizeof(struct Candidato), compararCandidatos);
    qsort(depEst, depEst, sizeof(struct Candidato), compararCandidatos);

    // Verifica se há segundo turno para o presidente
    if (presidente.votos * 2 <= votosValidos) {
        printf("%d %d\n", votosValidos, votosInvalidos);
        printf("Segundo turno\n");
    } else {
        printf("%d %d\n", votosValidos, votosInvalidos);
        printf("%d\n", presidente.codigo);
        for (int i = 0; i < senadores; i++) {
            printf("%d ", senador[i].codigo);
        }
        printf("\n");
        for (int i = 0; i < depFed; i++) {
            printf("%d ", depFed[i].codigo);
        }
        printf("\n");
        for (int i = 0; i < depEst; i++) {
            printf("%d ", depEst[i].codigo);
        }
        printf("\n");
    }

    return 0;
}
