#include<stdio.h>
#include<stdlib.h>

int main() {

    int i;

    printf("Digite uma valor:\n");
    scanf("%d", &i);

    printf("Em hexadecimal: %x\n", i);
    printf("Em octal: %o\n", i);
    
    return 0;
}
