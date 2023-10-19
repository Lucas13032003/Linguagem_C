#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char resposta;
    printf("..........Primeiro for..........\n");

    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    printf("..........Segundo for..........\n");

    for (i = 0; i < 10; i++) {
        if (i == 5)
        {
            continue;
        }
        printf("%d\n", i);
        
    }


    
    return 0;
}
