#include <stdio.h>
#include <string.h>

void imprimeReverso(char *str, int index) {
    if (index < 0) {
        return; // Condição de parada: todos os caracteres já foram impressos.
    }

    putchar(str[index]); // Imprime o caractere atual.
    imprimeReverso(str, index - 1); // Chama a função recursivamente para o próximo caractere.

}

int main() {
    char str[501]; // Supomos que a string terá no máximo 500 caracteres
    scanf("%s", str);

    int length = strlen(str);

    imprimeReverso(str, length - 1); // Chama a função para imprimir a string ao contrário.

    printf("\n"); // Imprime uma quebra de linha no final.

    return 0;
}
