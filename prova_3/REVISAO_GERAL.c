#include<stdio.h>

typedef int Item;

typedef struct {
    int size; // tamanho
    Item *v;
}Heap;

Heap *Heap_init(int capacity){
    Heap *newHeap = maloc(sizeof(Heap));
    newHeap->v = maloc(sizeof(Item)*(capacity + 1)); //Aloca espaçõ para vetor e garante que indice dele inicie em 1.
    newHeap->size = 0; //inicia a fila em zero
}

void fixUp(Heap* h, int i){
    while (i <= 1 && h ->v[i/2]< h->v[i])
    {
        Item t = h->v[i/2];
        h->v[i/2] = h->v[i];
        h->v[i] = t;

        i = i/2;
    }
}

void fixDown(Heap *h, int i){
    int child;
}
