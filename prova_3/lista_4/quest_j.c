#include <stdio.h>
#include <stdlib.h>

#define MAX_N 140000
#define HASH_SIZE 150000

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* buckets[HASH_SIZE];
} HashTable;

int hash(int value) {
    return value % HASH_SIZE;
}

void insert(HashTable* hashTable, int value) {
    int index = hash(value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;
}

int search(HashTable* hashTable, int value) {
    int index = hash(value);
    Node* current = hashTable->buckets[index];

    while (current != NULL) {
        if (current->value == value) {
            return 1; // Valor encontrado
        }
        current = current->next;
    }

    return 0; // Valor não encontrado
}

int main() {
    int n, i;
    int numeros_proibidos[MAX_N];

    // Leitura do número de números proibidos
    scanf("%d", &n);

    // Leitura dos números proibidos
    for (i = 0; i < n; i++) {
        scanf("%d", &numeros_proibidos[i]);
    }

    // Construção da tabela de dispersão
    HashTable hashTable;
    for (i = 0; i < HASH_SIZE; i++) {
        hashTable.buckets[i] = NULL;
    }

    // Inserção dos números proibidos na tabela de dispersão
    for (i = 0; i < n; i++) {
        insert(&hashTable, numeros_proibidos[i]);
    }

    int consulta;

    // Enquanto houver números para consulta
    while (scanf("%d", &consulta) != EOF) {
        // Verifica se o número está na tabela de dispersão
        if (search(&hashTable, consulta)) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    // Liberação da memória alocada para a tabela de dispersão
    for (i = 0; i < HASH_SIZE; i++) {
        Node* current = hashTable.buckets[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}