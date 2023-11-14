#include <stdlib.h>
#include <stdio.h>

void troca(float *a, float *b){
    float c = *a;
    *a = *b;
    *b = c;
}

int main(){

    float a, b;


    printf("Digite o valor a: \n");
    scanf("%f", &a);

    printf("Digite o valor b: \n");
    scanf("%f", &b);
    printf("\n");
    printf("valor incial de a: %.2f, valor incial de b: %.2f", a, b);

    troca(&a,&b);

    printf("\n");
    printf("valor de a: %.2f, Valor de b: %.2f", a, b);


    return 0;
}