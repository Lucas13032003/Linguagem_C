#include <stdio.h>

int teste_de_ponteiros() {
    int x;
    int y;
    int *p;
    p = &x;
    x = 10;
    y = 20;
    *p = y;
    printf("x = %i, y = %i\n", x, y);

    int i;
    int v[5] = {1, 2, 3, 4, 5};
    int *t = v;
    for (i = 0; i < 5; i++) {
        printf("%i\n", *t);
        t++; // Você pode incrementar o ponteiro para acessar o próximo elemento.
    }
};

int main() {
    printf("Hello World!\n");
    teste_de_ponteiros(); // Chama a função teste_de_ponteiros.
    return 0;
}
