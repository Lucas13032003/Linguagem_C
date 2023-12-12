#include <stdlib.h>
#include <stdio.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A,B) {if (less(B, A)) exch(A, B);}
 
typedef int Item; // Defina o tipo de dado Item conforme sua necessidade

int separa(Item *v, int l, int r) {
    int tam = r - l + 1;
    Item c = v[r]; // Elemento comparativo
    int c_pos; // Posição onde o elemento comparativo será colocado
    
    Item *menores = malloc(sizeof(Item) * tam);
    Item *maiores = malloc(sizeof(Item) * tam);
    int imenor = 0, imaiores = 0;

    for (int i = l; i < r; i++) {
        if (v[i] < c) {
            menores[imenor++] = v[i];
        } else {
            maiores[imaiores++] = v[i];
        }
    }

    int i = l;
    for (int j = 0; j < imenor; j++) {
        v[i++] = menores[j];
    }

    c_pos = i;
    v[i++] = c; // Adiciona o elemento comparativo no lugar certo

    for (int j = 0; j < imaiores; j++) {
        v[i++] = maiores[j];
    }

    free(menores);
    free(maiores);

    return c_pos;
}
int separa_2(Item *v, int l, int r) {
    Item c = v[r];
    int j = l;

    for (int k = l; k < r; k++) {
        if (less(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }
    }

    exch(v[j], v[r]);

    return j;
}

int separa_3(Item *v, int l, int r) {
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

void quick_sort (Item *v, int l, int r){
    int j;
    if (r <= l) return;
    {
        cmpexch(v[(l+r)/2], v[r]);
        cmpexch(v[l], v[(l+r)/2]);
        cmpexch(v[r], v[(l+r)/2]);
        j = separa_2(v, l, r);
        quick_sort(v, l, j-1);
        quick_sort(v, j+1, r);
    }
}

int main() {
    // Exemplo de uso
    int v[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(v) / sizeof(v[0]);

    int l = 0;
    int r = n - 1;

    printf("Array não ordenado:\n");    
    for (int i = 0; i < r; i++)
    {
        printf("%d ", v[i]);
    }
    
    printf("\n");
    printf("\n");

    quick_sort(v, l, r);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}