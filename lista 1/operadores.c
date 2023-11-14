#include<stdio.h>
#include<stdlib.h>

int main(){
    int A, B, soma, subr, mult, div;
    printf ("Digite o primeiro valor:\n");
    scanf ("%d", &A);
    
    printf ("Digite o segundo valor:\n");
    scanf ("%d", &B);

    soma = A+B;
    subr = A-B;
    mult = A*B;
    div = A/B;

    printf ("Resultados:\n");
    printf ("Soma: %p\n", &soma);
    printf ("Subtração: %d\n", subr);
    printf ("Multiplicação: %d\n", mult);
    printf ("Divisão: %d\n", div);
    
    return 0;
}
