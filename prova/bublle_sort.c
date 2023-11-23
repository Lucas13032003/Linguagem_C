#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

void bubble_sort(Item *v, int l, int r) {
    for (int i = r; i > l; i--) {
        for (int j = l; j < i; j++) {
            if (less(v[j + 1], v[j])) {
                exch(v[j + 1], v[j]);
            }
        }
    }
}

void bubble_sort_do(int *v, int n) {
    int i, continua, t, fim = n; // Inicialização de fim

    do {
        continua = 0; // Inicialização de continua
        for (i = 0; i < fim - 1; i++) {
            if (v[i] > v[i + 1]) {
                t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}


// int main(void) {
//     Item v[1000];


//     for (int i = 0; i < 1000; i++) {
//         v[i] = rand();
//     }

//     printf("Array original:\n");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", v[i]);
//     }
//     printf("...\n");


//     bubble_sort_do(v, 999);


//     printf("\nArray ordenado:\n");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", v[i]);
//     }
//     printf("...\n");

//     return 0;
// }

int main() {
    Item v[] = {23, 4, 67, -8, 90, 5421, 92};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    // Use a versão sem recursão
    bubble_sort_do(v, 6);

    printf("\nArray ordenado por recurção: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");


    return 0;
}