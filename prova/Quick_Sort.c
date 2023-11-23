#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

int separa(int *v, int l, int r) {
    int pivo = v[r];
    int j = l;

    for (int k = l; k < r; k++) {
        if (lesseq(v[k], pivo)) {
            exch(v[j], v[k]);
            j++;
        }
    }

    exch(v[j], v[r]);

    return j;
}

void quicksort(int *v, int l, int r) {
    if (l >= r)
        return;

    int p = separa(v, l, r);

    quicksort(v, l, p - 1);
    quicksort(v, p + 1, r);
}

int main() {
    int v[5] = {15, 9, 5, 3, 10};

    quicksort(v, 0, 4);

    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
