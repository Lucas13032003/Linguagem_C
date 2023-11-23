#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) { if (less(B, A)) exch(A, B);}
typedef int Item;

void insertion_sort(Item *v, int l, int r) {
    for (int i = r; i > l; i--) {
        cmpexch(v[i-1], v[i]);
    }
    
    for (int i = l + 2; i <= r; i++) { // Correção na inicialização do loop
        int j = i;
        Item temp = v[j];

        while (j > l && less(temp, v[j-1])) { // Correção na condição do while
            v[j] = v[j-1];
            j--;
        }

        v[j] = temp;
    }
}

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


insertion_sort(v, 0, 999);


printf("\nArray ordenado:\n");
for (int i = 0; i < 10; i++) {
    printf("%d ", v[i]);
}
printf("...\n");

return 0;
}