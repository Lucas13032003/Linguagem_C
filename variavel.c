#include<stdio.h>
#define texto "Entrada e sída de dados"

int main(int argc, char const *argv[])
{
    printf("%s\n", texto);

    int idade = 0;
    float altura = 0.0;
    char nome [10] = "";

    printf ("Qual é a sua idade?\n");
    scanf ("%d", &idade);

    printf ("Qual é a sua altura?\n");
    scanf ("%f", &altura);

    printf ("Qual é o seu nome?\n");
    scanf ("%s", &nome,"\n");
    printf("...................DADOS INFORMADOS...................\n");
    printf ("Nome:%s.\n", nome);
    printf ("Idade:%d.\n", idade);
    printf ("Altura:%.2f.\n", altura);

    return 0;
}
