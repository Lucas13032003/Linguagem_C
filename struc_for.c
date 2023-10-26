#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 50
#define PES 3

struct tipo_pessoa {
    int idade;
    float peso;
    char nome[TAM];
};

typedef struct tipo_pessoa tipo_pessoa;

int main() {
    setlocale(LC_ALL, "Portuguese");

    tipo_pessoa lista[PES];
    int i;

    for (i = 0; i < PES; i++) {
        puts("\n");
        printf("Insira os dados para a Pessoa %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", lista[i].nome);

        printf("Peso: ");
        scanf("%f", &lista[i].peso);

        printf("Idade: ");
        scanf("%d", &lista[i].idade);
    }
    puts("\n");
    printf("Seus dados:\n");

    for (i = 0; i < PES; i++) {
        printf("------------------------ Pessoa %d -------------------------------\n", i+1 );
        printf("Nome: %s\n", lista[i].nome);
        printf("Peso: %.2f\n", lista[i].peso);
        printf("Idade: %d\n", lista[i].idade);
        printf("------------------------ Finalizado -------------------------------\n\n");
    }

    return 0;
}
