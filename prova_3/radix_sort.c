#include <stdio.h>
#include <string.h>

#define maxstring 101
#define bitsbyte 8
#define R (1 << bitsbyte)

int digit(int x, int d) {
    // Retorna o d-ésimo byte do número x
    return (x >> (bitsbyte * d)) & (R - 1);
}

int charAt(char s[], int d) {
    if (d < strlen(s))
        return s[d];
    else
        return -1;
}

void radixMSD(char a[][maxstring], int l, int r, int d) {
    if (r <= l)
        return;

    char aux[r - l + 1][maxstring];

    int count[R + 1];
    memset(count, 0, sizeof(int) * (R + 1));

    for (int i = l; i <= r; i++)
        count[charAt(a[i], d) + 1]++;

    for (int i = 1; i <= R; i++)
        count[i] += count[i - 1];

    for (int i = l; i <= r; i++)
        strcpy(aux[count[charAt(a[i], d)]++], a[i]);

    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]);

    for (int i = 1; i <= R; i++) {
        radixMSD(a, l + count[i - 1], l + count[i] - 1, d + 1);
    }
}

void radix_sortMSD(int *v, int l, int r, int w) {
    if (r <= l || w < 0)
        return;

    int i, aux[r - l + 1], count[R + 1];
    memset(count, 0, sizeof(int) * (R + 1));

    for (i = l; i <= r; i++)
        count[digit(v[i], w) + 1]++;

    for (i = 1; i <= R; i++)
        count[i] += count[i - 1];

    for (i = l; i <= r; i++)
        aux[count[digit(v[i], w)]++] = v[i];

    for (i = l; i <= r; i++)
        v[i] = aux[i - l];

    radix_sortMSD(v, l, l + count[0] - 1, w - 1);
    for (i = 1; i <= R; i++)
        radix_sortMSD(v, l + count[i - 1], l + count[i] - 1, w - 1);
}

int main() {
    // Exemplo de uso para strings
    char strings[][maxstring] = {"abc", "xyz", "def", "uvw", "ghi"};
    int string_count = sizeof(strings) / sizeof(strings[0]);

    radixMSD(strings, 0, string_count - 1, 0);

    printf("Strings ordenadas:\n");
    for (int i = 0; i < string_count; i++) {
        printf("%s\n", strings[i]);
    }

    // Exemplo de uso para inteiros
    int ints[] = {1234, 5678, 9012, 3456, 7890};
    int int_count = sizeof(ints) / sizeof(ints[0]);

    radix_sortMSD(ints, 0, int_count - 1, 3);

    printf("Inteiros ordenados:\n");
    for (int i = 0; i < int_count; i++) {
        printf("%d\n", ints[i]);
    }

    return 0;
}
