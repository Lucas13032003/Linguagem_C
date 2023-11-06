#include <stdio.h>
#include <string.h>

int maiorSubstring(char *str, char *sub, int str_index, int sub_index, int max_length) {
    if (str[str_index] == '\0') {
        return max_length;
    }

    if (str[str_index] == sub[sub_index]) {
        if (sub[sub_index + 1] == '\0') {
            int new_length = sub_index + 1;
            return maiorSubstring(str, sub, str_index + 1, 0, (new_length > max_length) ? new_length : max_length);
        } else {
            return maiorSubstring(str, sub, str_index + 1, sub_index + 1, max_length);
        }
    } else {
        return maiorSubstring(str, sub, str_index + 1, 0, max_length);
    }
}

int main() {
    char str[101]; // Supomos que 'str' terá no máximo 100 caracteres.
    char sub[101]; // Supomos que 'sub' terá no máximo 100 caracteres.

    scanf("%s", str);
    scanf("%s", sub);

    int str_length = strlen(str);
    int sub_length = strlen(sub);
    int result = maiorSubstring(str, sub, 0, 0, 0);

    printf("%d\n", (result >= sub_length) ? result : 0);

    return 0;
}
