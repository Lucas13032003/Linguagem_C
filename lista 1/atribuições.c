#include<stdio.h>
#include<stdlib.h>

int main(){
    int dado = 10;
    
    printf("Antes do incremento:%d\n", dado);
    
    dado++;
    printf ("Depois do incremento: %d\n", dado);

    dado--;
    printf ("Depois do decremento: %d\n", dado);

    dado+=3;
    printf("Depois do incremento genérico: %d\n", dado);

    dado-=2;
    printf("Depois do decremento genérico: %d\n", dado);

    dado*=10;
    printf("Depois da multiplicação genérica: %d\n", dado);
  
    return 0;
}
