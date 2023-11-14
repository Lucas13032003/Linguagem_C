#include<stdio.h>
#include<stdlib.h>

int v [5];
float m;
int i;
float s = 0;

int main()
{

    // v[0] = 10;
    // v[1] = 20;
    // v[2] = 30;
    // v[3] = 40;
    // v[4] = 50;

    // m = (v[0]+v[1]+v[2]+v[3]+v[4])/5;

    // printf("Resultado: %2.f\n", m);

// ---------------------------------Utilizando o for------------------------------------------

    int v[5] = {10, 20, 30, 40, 50};
    for ( i = 0; i < 5; i++)
        s += v[i];
    {
        printf("Resultado %2.f\n", s/5);
    }
    


    return 0;
}

