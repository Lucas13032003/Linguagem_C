#include <stdio.h>
#include <string.h>

int countPairs(char *str, int length, int index) {
    if (index >= length - 2) {
        return 0; // A recursão termina quando o índice não pode mais formar pares.
    }

    if (str[index] == str[index + 2]) {
        return 1 + countPairs(str, length, index + 1);
    } else {
        return countPairs(str, length, index + 1);
    }
}

int main() {
    char str[201]; // Supomos que a string terá no máximo 200 caracteres
    scanf("%s", str);

    int length = strlen(str);
    int pairs = countPairs(str, length, 0);

    printf("%d\n", pairs);

    return 0;
}
