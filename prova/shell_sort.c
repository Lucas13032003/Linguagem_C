#include <stdlib.h>
#include <stdio.h>

#define less(A, B) (A < B)

void shell_sort(int *v, int l, int r, int h) {
    

    for (h = 1; h <= (r - l) / 9; h = 3 * h + 1) {
        for (; h > 0; h = h / 3) {
            for (int i = l + h; i <= r; i++) {
                int j = i;
                int temp = v[i];

                while (j >= l + h && less(temp, v[j - h])) {
                    v[j] = v[j - h];
                    j = j - h;
                }

                v[j] = temp;
            }
        }
    }
}

int main(void) {
    int v[1000];

    for (int i = 0; i < 1000; i++) {
        v[i] = rand();
    }

    shell_sort(v, 0, 999, 3);

    return 0;
}
