#include <stdio.h>
#include <stdbool.h>

#define MAX_CITIES 100
#define INF 1000000

typedef struct {
    int data[MAX_CITIES];
    int front;
    int rear;
} Queue;

void create(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int item) {
    q->data[++q->rear] = item;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

int roadsRequired[MAX_CITIES]; // Vetor de contagem de estradas
int visited[MAX_CITIES];      // Vetor de cidades visitadas

void initArrays() {
    for (int i = 0; i < MAX_CITIES; i++) {
        roadsRequired[i] = INF;
        visited[i] = false;
    }
}

void findShortestPath(int start, int destination) {
    Queue q;
    create(&q);
    enqueue(&q, start);
    roadsRequired[start] = 0;
    visited[start] = true;

    while (!isEmpty(&q)) {
        int city = dequeue(&q);

        if (city == destination) {
            break;
        }

        // Simule aqui a descoberta das cidades vizinhas e suas estradas

        // Por exemplo, você pode usar um loop para percorrer as cidades vizinhas
        // e atualizar as estradas necessárias e visitar cidades se encontrar um caminho mais curto.

        // roadsRequired[neighborCity] = min(roadsRequired[neighborCity], roadsRequired[city] + 1);
        // visited[neighborCity] = true;

        // Em seguida, enfileire a cidade vizinha se ainda não foi visitada.
        // enqueue(&q, neighborCity);
    }
}

int main() {
    int startCity, destinationCity;

    // Leia o ponto de partida e o destino da entrada
    scanf("%d %d", &startCity, &destinationCity);

    initArrays();
    findShortestPath(startCity, destinationCity);

    // Saída: menor número de estradas para chegar ao destino
    printf("Menor número de estradas para chegar a %d: %d\n", destinationCity, roadsRequired[destinationCity]);

    return 0;
}
