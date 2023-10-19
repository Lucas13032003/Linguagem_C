#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int v [5] = {50, 40, 30, 20, 10};
    float m = 0;
    int i;

    for (i = 0; i < 5; i++){
        m += v[i];
    }
    
    printf("Resultado: %2.f\n", m/5);


    return 0;
}

