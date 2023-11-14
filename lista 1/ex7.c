#include<stdio.h>

/*2. Fazer um programa que imprime a tabela ASCII (código decimal, código hexa,
caracter) para os códigos de 0 a 127.*/

int main() {
    
    int i; 


    printf("| Decimal | Hexa | Caracter |\n");
    printf("|---------|------|----------|\n");
    for ( i = 0; i <=127; i++)
    {
        printf("|%8d | %4X | %10c|\n", i, i, i);

    }
    
    
    return 0;
}
