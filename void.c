#include <stdio.h>

void for_vet_1(int n, int v[]){
    int i;
    for ( i = 0; i < n; i++) {
        printf("%d - ", v[i]);
    }
    printf("\n\n");
}
void for_vet_2(int v[5]){
    int i;
    for ( i = 0; i < 5; i++) {
        printf("%d - ", v[i]);
    }
    printf("\n\n");
}
void for_vet_3(int *v, int n){
    int i;
    for ( i = 0; i < n; i++) {
        printf("%d - ", v[i]);
    }
    printf("\n\n");
}

int main() {

    int v[5] = {1,2,3,4,5};

    printf("\n\n");

    puts("for_vetor_1:\n");
    for_vet_1(5, v);
    
    puts("for_vetor_2:\n");
    for_vet_2(v);

    puts("for_vetor_3:\n");
    for_vet_3(v, 5);

    return 0;
}



