#include<stdio.h>
#include<stdlib.h>

/*1. Faça um programa em "C" que lê dois valores e imprime:
- se o "a" valor for menor que o b, a lista de valores do primeiro até
o segundo;
- se o "primeiro" valor for menor que o segundo a imprima a lista de valores do segundo até
o primeiro em ordem decrescente;
- se ambos forem iguais a mensagem "valores iguais".*/

int main() {

    int a;
    int b;
    int i;

    printf("Digite o valor A:\n");
    scanf("%d", &a);

    printf("Digite o valor B:\n");
    scanf("%d", &b);

    if (a < b)
    {
        printf("%d é menor que %d, segue a lista em ordem crescente:\n", a, b);
        for ( i = a; i <= b; i++)
        {
            printf("%d-", i);
        }
        
    }
    else if (a >  b)
    {
        printf("Valores de %d a %d em ordem decrescente:\n", a, b);
        
        for ( i = a; i >= b; i--) {
            printf("%d ", i);
        }
    }
    else
    {
        printf("a e b são iguais\n");
    }
    
    
    
    
    return 0;
}

