/*Crie um vetor de 5 elementos onde ele peça para que o usuario insira o dado. */

#include<stdio.h>

int soma(int a, int b){
    return a+b;
}

int main(){

    int a;
    int b;
    int r;

    printf("Digtite o valor de a:\n");
    scanf("%d", & a);

    printf("Digtite o valor de b:\n");
    scanf("%d", & b);

    r = soma(a,b);

    printf("Resultado: %d\n", r);

     //For com vetores e Scanf

    printf("For com vetores e Scanf\n");

    int i;
    int v[5];

    for ( i = 0; i < 5; i++)
    {
        printf("Digite o dado:\n");
        scanf("%d", &v[i]);
    }
    printf("Os dados inseriridos foram:\n");

    for ( i = 0; i < 5; i++)
    {
        printf("%d - ", v[i]);
    }
    
    
    return 0;
}