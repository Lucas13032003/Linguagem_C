#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 100;
    int y = 150;

    printf("Antes : %d %d\n", x, y);
    swap(&x, &y);
    printf("Depois : %d %d\n", x, y);

    return 0;
}
