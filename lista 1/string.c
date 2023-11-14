#include <stdio.h>

int main() {
    char s[10];

    printf("Digite algo relevante:\n");
    scanf("%9s", s);
    while (getchar() != '\n'); // Limpa o buffer de entrada após o scanf

    printf("%s\n", s);

    printf("Digite algo novamente:\n");
    scanf(" %9[^\n]s", s);
    while (getchar() != '\n'); // Limpa o buffer de entrada novamente

    printf("%s\n", s);

    return 0;
}
