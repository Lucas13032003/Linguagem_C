#include <stdio.h>

#define chave(A) (A.chave)

typedef int Chave;

typedef struct ItemDado {
    Chave chave;
    char info[100];
} Item;

Item* busca_binaria(Item* v, int l, int r, Chave k) {
    if (l >= r)
        return NULL;

    int m = (l + r) / 2;

    if (k == chave(v[m]))
        return &v[m];

    if (k < chave(v[m]))
        return busca_binaria(v, l, m - 1, k);

    return busca_binaria(v, m + 1, r, k);
}
int main() {
    // Exemplo de array ordenado para teste
    Item array[] = {0
        // {1, "LV"},
        // {2, "LO"},
        // {3, "RIBAS"},
        // {4, "IZA"},
        // {5, "MARY"},
        // {6, "CERZINHA"},
        // {0,"..X.."}
        // Adicione mais elementos conforme necessário
    };

    int tamanho = sizeof(array) / sizeof(array[0]);

    Chave chaveProcurada;
    printf("Digite a chave a ser procurada: ");
    scanf("%d", &chaveProcurada);

    Item* resultado = busca_binaria(array, 0, tamanho - 1, chaveProcurada);

    if (resultado != NULL) {
        printf("Chave encontrada! Informação: %s\n", resultado->info);
    } else {
        printf("Chave não encontrada.\n");
    }

    return 0;
}
