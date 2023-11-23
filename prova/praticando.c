#include <stdlib.h>
#include <stdio.h>
#define less(A, B) (A < B)
#define exch(A, B) {int t = A; A = B; B = t;}

void selection_sort(int *v, int n){
    int i, j, troca, menor;

    for ( i = 0; i < n -1; i++){
    menor = i;
       for ( j = i+1; j < n; j++)
       {
        if (v[j]< v[menor])
        {
            menor = j;
        }
        if (i!= menor)
        {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
       }  
    } 
}

void bubble_sort(int *v, int n){
    int i, continuar, t, fim = n; // Inicialização de fim

    do
    {
        continuar = 0;
        for (i = 0; i < fim - 1; i++) { // Correção na condição do loop for
            if (v[i] > v[i + 1]) {
                t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;
                continuar = i;
            }
        }
        fim--;
    } while (continuar != 0);
}

void insertion_sort(int *v, int n){
    int i, j, aux;
    for ( i = 1; i < n; i++)
    {
        aux = v[i];
        for ( j = i; (j > 0) && (aux < v[j - 1]); j--)
        {
            v[j] = v[j-1];
        }
        
        v[j] = aux;        
    }
}

void selection(int *v, int n){
    int aux, j, i;

    for ( i = 1; i < n; i++)
    {
        aux = v[i];

        for ( j = i; (j > 0) && (aux < v[j-1]); j--)
        {
            v[j] = v[j-1];
        }
        v [j] =aux;    
    } 
}

void shell_sort_h(int *v, int l, int r, int h) {
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

void shell_sort(int *v, int l, int r, int h) {
    for (h = 1; h <= (r - l) / 9; h = 3 * h + 1) {
        for (; h > 0; h = h / 3) {
            shell_sort_h(v, l, r, h);
        }
    }
}

void shell_sort_outra(int *v, int  n){
    int j, i, h, aux;
    h = 1;

    while (h < n/3)
    {
        h = 3 * h+1;

        while (h > 0)
        {
            for ( i = h; i < n; i++)
            {
                aux = v[i];
                j = i;
                while (j>= h && aux < v[j-h])
                {
                    j = j - h; 
                }
                v[j] = aux;
            }   
        }   
    }
}

int particiona(int *v, int l, int r) {
    int aux;
    int pivo = v[l];
    while (l < r) {
        while (v[l] <= pivo) {
            l++;
        }
        while (v[r] > pivo) {
            r--;
        }
        if (l < r) {
            exch(v[l], v[r]);
        }
    }
    v[l] = v[r];
    v[r] = pivo;
    return r;
}

void quick_sort(int *v, int l, int r) {
    int pivo;

    if (r > l) {
        pivo = particiona(v, l, r);
        quick_sort(v, l, pivo - 1);
        quick_sort(v, pivo + 1, r);
    }
}


int main(void) {
    int v[] = {15, 9, 5, 3, 10};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor não ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    quick_sort(v, 0, 5);

    printf("\nArray ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;

}



// int main(void) {
//     int v[10000];

//     for (int i = 0; i < 10000; i++) {
//         v[i] = rand();
//     }

//     printf("Array original:\n");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", v[i]);
//     }
//     printf("...\n");


//     shell_sort_outra(v, 6);


//     printf("\nArray ordenado:\n");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", v[i]);
//     }
//     printf("...\n");

//     return 0;
// }