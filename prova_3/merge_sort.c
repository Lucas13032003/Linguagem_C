#include <stdlib.h>
#include <stdio.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { item t = A; A = B; B = t; }
#define cmpexch(A,B) {if (less(B, A)) exch(A, B);}

typedef int item;   

void merge(item *v, int l, int r1, int r2) {
    int k = 0;
    int i = l;
    int j = r1 + 1;
    item *v2 = malloc(sizeof(item) * (r2 - l + 1));

    while (i <= r1 && j <= r2) {
        if (lessf(v[i], v[j])) {
            v2[k++] = v[i++];
        } else {
            v2[k++] = v[j++];
        }
    }

    while (i <= r1) {
        v2[k++] = v[i++];
    }

    while (j <= r2) {
        v2[k++] = v[j++];
    }

    k = 0;

    for (i = l; i <= r2; i++) {
       v[i] = v2[k++];
    }

    free(v2);
}

void merge_sort(item *v, int l, int r) {
    if (l < r) {
        int meio = (l + r) / 2;

        merge_sort(v, l, meio);
        merge_sort(v, meio + 1, r);

        merge(v, l, meio, r);
    }
}

int main() {
    item v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    int l = 0;
    int r = n - 1;

    merge_sort(v, l, r);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
