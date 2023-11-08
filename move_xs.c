#include <stdio.h>
#include <string.h>

void moveXToEnd(char *str, int index, int len) {
    if (index >= len) {
        return;
    }

    if (str[index] == 'x') {
        memmove(&str[index], &str[index + 1], len - index - 1);
        str[len - 1] = 'x';
        moveXToEnd(str, index, len - 1);
    } else {
        moveXToEnd(str, index + 1, len);
    }
}

int main() {
    char str[101];
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    moveXToEnd(str, 0, len);
    printf("%s\n", str);

    return 0;
}