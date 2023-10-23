#include<stdlib.h>
#include<stdio.h>

/*4. Fazer um programa em "C" que pergunte um valor em graus Fahrenheit e
imprime no vídeo o correspondente em graus Celsius usando as fórmulas que
seguem.

 a) Usar uma variável double para ler o valor em Fahrenheit e a fórmula
 C=(f-32.0) * (5.0/9.0).

 b) Usar uma variável int para ler o valor em Fahrenheit e a fórmula
 C=(f-32)*(5/9).*/

int main()
{
    double f;
    double c;
    int fa;
    int ce;

    printf("Digite a temperatura em Fahrenheit:\n");
    scanf("%lf", &f);

    c = (f-32.0) * (5.0/9.0)*f;

    printf("Está temperatura corresponde em graus celsius é: %.2lf\n", c);


    printf("Digite a temperatura em Fahrenheit:\n");
    scanf("%d", &fa);

    ce = (f-32)*(5/9)*fa;

    printf("Está temperatura corresponde em graus celsius é: %.2d\n", ce);



    return 0;
}

