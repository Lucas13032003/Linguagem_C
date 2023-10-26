#include <stdio.h>
# include <stdlib.h> 
#include <string.h>
#include <locale.h>

#define TAM 50

struct tipo_pessoa {
    int idade;
    float peso;
    char nome[TAM];
};

typedef struct tipo_pessoa tipo_pessoa;

int main() {
    setlocale(LC_ALL, "Portuguese");

    tipo_pessoa dados = {0, 0.0, "teste"};

    // Criando e inicializando:
    printf("Início:\n");
    printf("Dado idade: %d\n", dados.idade);
    printf("Dado peso: %.2f\n", dados.peso); // Corrigido o formato da impressão
    printf("Dado Nome: %s\n", dados.nome);
    printf("\n");

    // Atribuindo valores aos campos
    dados.idade = 20;
    dados.peso = 85.5;
    strcpy(dados.nome, "LV_$$");

    printf("Atribuindo:\n");
    printf("Dado idade: %d\n", dados.idade);
    printf("Dado peso: %.2f\n", dados.peso); // Corrigido o formato da impressão
    printf("Dado Nome: %s\n", dados.nome);
    printf("\n");

    // Solicitando via teclado
    printf("Informe seus dados:\n");
    printf("\n");
    printf("Insira sua idade: \n");
    scanf("%d", &dados.idade);
    fflush(stdin);
    printf("Insira seu peso: \n");
    scanf("%f", &dados.peso); // Corrigido o formato do scanf para ler um float
    fflush(stdin);
    printf("Insira seu nome: \n");
    scanf("%s", dados.nome); // Não é necessário o "&" para arrays de caracteres
    fflush(stdin);

    // Imprimir
    printf("Dado idade: %d\n", dados.idade);
    printf("Dado peso: %.2f\n", dados.peso);
    printf("Dado Nome: %s\n", dados.nome);

    return 0;
}
