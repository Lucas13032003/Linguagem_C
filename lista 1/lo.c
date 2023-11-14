#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 20;
    int b = 10;
    int m = a * b;

    printf("O valor de 20 * 10 é: %d\n", m);

    int i = 0;

    while (i <= 20) {
        printf("%d\n", i);
        if (i==5)
        {
            break;
        }
        i++;
        
    }

    return 0;
}
