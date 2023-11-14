#include<stdio.h>
#include<stdlib.h>


int main()
{
    int i;
    int v[5];

    for ( i = 0; i < 5; i++)
    {
        printf("Digite um Valor:\n");
        scanf("%d", & v[i]);
    }

    printf("Valores inseridos:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%d\n", v[i]);


    }
    
    
    
    return 0;
}


