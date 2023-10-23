#include<stdio.h>
#include<stdlib.h>

/*3. Fazer um programa em "C" que lê o preço de um produto e inflaciona esse
preço em 10% se ele for menor que 100 e em 20% se ele for maior ou igual a
100.
OBS: não use o comando "if" ou o operador de condição "?".*/

int main() {

    float preco;
    float inflacao;

    printf("Digite o valor do prduto: $ ");
    scanf("%f", &preco);

    inflacao = (preco < 100)*0.10 + (preco >= 100)*0.20;

    preco = preco + (preco*inflacao);

    printf("O valor do produto será: $ %2.f\n", preco);

    
    return 0;
}

