#include<stdio.h>
#include<stdlib.h>

int main(){
    int d;
    printf ("Digite um número de 1 ao 7:\n");
    scanf ("%d", &d);
    switch (d) {
    case  1:
        printf ("Domingo\n", d);
    break;
    case  2:
        printf ("Segunda\n", d);
    break;
    case  3:
        printf ("Terça\n", d);
    break;
    case  4:
        printf ("Quarta\n", d);
    break;
    case  5:
        printf ("Quinta\n", d);
    break;
    case  6:
        printf ("Sexta\n", d);
    break;
    case  7:
        printf ("Sábado\n", d);
    break;

    default:
    printf("Valor invalido\n");
        break;
    }
    return 0;
}
