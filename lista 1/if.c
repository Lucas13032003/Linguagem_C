#include<stdlib.h>
#include<stdio.h>

int main(){

    float valor;

    printf("Digite um valor:\n");
    scanf("%f", &valor);

    if (valor >=7.5)
    {
        printf("Aprovado\n");
    }
    else{
        printf("Reprovado\n");
    }

    return 0;
}
