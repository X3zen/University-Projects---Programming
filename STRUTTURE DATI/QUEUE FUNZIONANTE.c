#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

bool isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue (Queue *q, int value) {
    if (isFull(q)) {
        printf("Errore: Queue Piena\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->data[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Errore: Queue vuota\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(Queue *q) {
    if (isEmpty (q)) {
        printf("Queue Vuota\n");
        return;
    }
    printf("il contenuto della Queue è (dalla testa alla coda):\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

//INIZIO PROGRAMMA
int main () {
    Queue q;
    initQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);

    printQueue(&q);

return 0;
}