#include <stdio.h>
#include <string.h>

void trocaXY(char *str, int index) {
    if (str[index] == '\0') {
        return; // Condição de parada: chegamos ao final da string.
    }

    if (str[index] == 'x') {
        str[index] = 'y';
    }

    trocaXY(str, index + 1); // Chamada recursiva para o próximo caractere.
}

int main() {
    char str[81]; // Supomos que a string terá no máximo 80 caracteres
    scanf("%s", str);

    trocaXY(str, 0); 

    printf("%s\n", str);

    return 0;
}
