#include <stdio.h>

int main() {
    int t = 9;
    int i, m;
    int j;

    for (i = 1; i <= 10; i++) {
        printf("Tabuada do %d:\n", i);

        for (j = 1; j <= 10; j++) {
            m = i * j;
            printf("%dx%d = %d\n", i, j, m);
        }
        printf("\n"); // Adiciona uma linha em branco entre as tabuadas
    }

    return 0;
}
