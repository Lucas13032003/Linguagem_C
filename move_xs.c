#include <stdio.h>
#include <string.h>

void moveXs(char *str, int index, int len) {
    if (index >= len) {
        return; // Condição de parada: chegamos ao final da string
    }

    if (str[index] == 'x') {
        // Se encontrarmos um 'x', movemos os caracteres à direita uma posição para a esquerda
        for (int i = index; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = 'x'; // Colocamos 'x' no final da string
    }

    // Chamada recursiva para o próximo caractere
    moveXs(str, index + 1, len);
}

int main() {
    char str[101]; // Supomos que a string terá no máximo 100 caracteres
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove o caractere de nova linha, se presente
        len--;
    }

    moveXs(str, 0, len);

    printf("%s\n", str);

    return 0;
}
