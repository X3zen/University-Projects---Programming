#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data [MAX];
    int top;
} Stack;

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Errore: Stack pieno \n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Errore: Stack vuoto \n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if(isEmpty(s)) {
        printf("Errore: Stack vuoto \n");
        return -1;
    }
    return s->data[(s->top)];
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Lo stack è vuoto");
        return;
    }
    printf("Contenuto dello Stack (dalla base alla cima): \n");
    for (int i=0; i<=s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    //INIZIALIZZAZIONE DELLO STACK
    s.top = -1;

    //INSERIMENTO ELEMENTI
    push (&s, 10);
    push (&s, 20);
    push (&s, 30);

    //STAMPA DELLO STACK
    printStack(&s);

    //VISUALIZZAZIONE DELL'ELEMENTO IN CIMA
    int topElement = peek(&s);
    printf("Elemento in cima (PEEK): %d\n", topElement);

    //RIMOZIONE DELL'ELEMENTO IN CIMA
    int removed = pop(&s);
    printf("Elemento rimosso (POP): %d\n", removed);

    //STAMPA DELLO STACK POST POP
    printStack(&s);

return 0;
}