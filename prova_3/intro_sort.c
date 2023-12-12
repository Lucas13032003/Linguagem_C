#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { int t = A; A = B; B = t; }
#define cmpexch(A, B) { if (less(B, A)) exch(A, B); }

typedef int Item;

void insertion_sort(Item *v, int l, int r) {
    for (int i = r; i > l; i--) {
        cmpexch(v[i - 1], v[i]);
    }

    for (int i = l + 2; i <= r; i++) {
        int j = i;
        Item temp = v[j];

        while (j > l && less(temp, v[j - 1])) {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = temp;
    }
}

int particiona(Item *v, int l, int r) {
    int i = l - 1, j = r;
    Item c = v[r];

    for (;;) {
        while (less(v[++i], c));
        while (less(c, v[--j])) if (j == l) break;

        if (i >= j) break;

        exch(v[i], v[j]);
    }

    exch(v[i], v[r]);

    return i;
}

void quick_sort(Item *v, int l, int r) {
    int j;
    if (r <= l) return;

    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    j = particiona(v, l, r);
    quick_sort(v, l, j - 1);
    quick_sort(v, j + 1, r);
}

void fixDown(Item *v, int k, int n) {
    int j;
    while (2 * k <= n) {
        j = 2 * k;
        if (j < n && less(v[j], v[j + 1])) {
            j++;
        }
        if (!less(v[k], v[j])) {
            break;
        }
        exch(v[k], v[j]);
        k = j;
    }
}

void heap_sort(Item *v, int n) {
    int k;

    // Constrói a heap
    for (k = n / 2; k >= 1; k--) {
        fixDown(v, k, n);
    }

    // Remove da heap e insere no final do array ordenado
    while (n > 1) {
        exch(v[1], v[n]);
        fixDown(v, 1, --n);
    }
}

void intro(int *v, int l, int r, int maxdepth) {
    if (r - l <= 15) {
        insertion_sort(v, l, r);
        return;
    } else if (maxdepth == 0) {
        heap_sort(v, r - l + 1);  // Corrigido aqui
    } else {
        cmpexch(v[l], v[(l + r) / 2]);
        cmpexch(v[l], v[r]);
        cmpexch(v[r], v[(l + r) / 2]);

        int p = particiona(v, l, r);
        intro(v, l, p - 1, maxdepth - 1);
        intro(v, p + 1, r, maxdepth - 1);
    }
}

int main() {
    // Exemplo de uso
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    int l = 0;
    int r = n - 1;

    intro(v, l, r, 2);  // Chamada corrigida aqui

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
