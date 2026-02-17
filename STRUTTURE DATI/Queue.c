#include <stdio.h>
#include <stdbool>

#define MAX 100         //DIMENSIONE MASSIMA ARRAY

typedef struct {
    int data [MAX];     //ARRAY
    int front;          //INDICE DEL PRIMO ELEMENTO
    int rear;           //INDICE DEL'ULTIMO ELEMENTO
} Queue;

//FUNZIONE ISEMPTY
bool isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

//FUNZIONE ISFULL
bool isFull(Queue *q) {
    return q->rear == MAX - 1;
}

//FUNZIONE FRONT
int front(Queue *q) {
    if (isEmpty (Queue *q)) {
        printf("Errore: Queue vuota\n");
        return 1;
    }
    return q->data[q->front];
}

//FUNZIONE DEQUEUE
int dequeue(Queue *q) {
    if (isEmpty (Queue *q)) {
        printf("Errore: Queue vuota\n");
        return 1;
    }
    return q->data[(q->front)++];    
}

//FUNZIONE ENQUEUE
    void enqueue(Queue *q, int value) {
        if (isFull(q)) {
            printf("Errore: Queue piena\n");
            return;
        }
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->data[++(q->rear)] = value;
    }