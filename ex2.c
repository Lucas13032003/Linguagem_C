//1. Fazer um programa em C que pergunta um valor em metros e imprime o correspondente em decímetros, centímetros e milímetros.

#include<stdlib.h>
#include<stdio.h>
#define decímetros 10
#define centímetros 100
#define milímetros 1000

int main() {
    float m, d, c, mi;
    
    printf("Digita o valor em metro:\n");
    scanf ("%f", &m);

    printf("..................Converção..................\n");

    d = m * decímetros;
    c = m * centímetros;
    mi = m * milímetros;

    printf("Decímetro:%2.f\n", d);
    printf("Centímetro:%2.f\n", c);
    printf("Milímetro:%2.f\n", mi);


    
    return 0;
}
