#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

void selection_sort(Item *v, int l, int r) {
    if (l == r) return;
    int menor = l;
    for (int j = l + 1; j <= r; j++) {
        if (less(v[j], v[menor])) {
            menor = j;
        }
    }
    exch(v[menor], v[l]);

    selection_sort(v, l + 1, r);
}

void selection_sem_recursao(Item *v, int l, int r) {
    for (int i = l; i < r; i++) {
        int menor = i;
        for (int j = i + 1; j <= r; j++) {
            if (less(v[j], v[menor])) {
                menor = j;
            }
        }
        exch(v[menor], v[i]);
    }
}

// // int main() {
//     Item v[] = {30, 45, 60, 10, 10, 5, 92};
//     int n = sizeof(v) / sizeof(v[0]);

//     printf("Array original: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", v[i]);
//     }

//     // Use a versão sem recursão
//     selection_sort(v, 0, n - 1);

//     printf("\nArray ordenado por recurção: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", v[i]);
//     }
//     printf("\n");

//     selection_sem_recursao(v, 0, n - 1);
//     printf("\nArray ordenado sem recurção: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", v[i]);
//     }
//     printf("\n");


//     return 0;
// }

int main(void) {
Item v[1000];


for (int i = 0; i < 1000; i++) {
    v[i] = rand();
}

printf("Array original:\n");
for (int i = 0; i < 10; i++) {
    printf("%d ", v[i]);
}
printf("...\n");


selection_sem_recursao(v, 0, 999);


printf("\nArray ordenado:\n");
for (int i = 0; i < 10; i++) {
    printf("%d ", v[i]);
}
printf("...\n");

return 0;
}