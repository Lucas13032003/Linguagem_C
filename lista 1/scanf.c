#include<stdio.h>

int main(int id, float peso){
    id = 0;
    peso = 0.0;
    printf ("Qual é sua idade: %d.\n", id);
    printf ("Digite sua idade:\n");
    scanf ("%d", &id);

    printf ("Qual é seu peso: %f.\n", peso);
    printf ("Digite seu peso:\n");
    scanf ("%f", &peso);


    printf ("A idade informada foi: %d\n", id);
    printf ("Seu peso: %f.\n", peso);

    return 0;
}
