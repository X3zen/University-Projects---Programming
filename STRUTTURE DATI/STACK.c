#include <stdio.h>          //LIBRERIE RICHIESTE PER LE SEGUENTI FUNZIONI
#include <stdbool.h>

#define MAX 100     //dimensione massima dello stack

typedef struct {    //Typedef è una parola chiave usata per assegnare dei nomi alternativi a dei tipi di dato esistenti
                    //Struct serve per definire un tipo di dato composto, ovvero un struttura dati
    int data [MAX]; //Array per contenere gli elementi
    int top;        //Indice dell'elemento in cima
} Stack;


//FUNZIONE ISEMPTY
bool isEmpty(stack *s) {    //Controlla il componente -top- è -1
    return s->top == -1;
}

//Funzione ISFULL
bool isFull(Stack *s) {     //Controlla il componente -top- è MAX - 1
    return s->top == MAX - 1;
}

//FUNZIONE PEEK
int peek(stack *s) {
    if(isEmpty(s)) {        //Controllo se lo stack è vuoto così evidando che la lettura di un elemento non presente in memoria generi un blocco
        printf("Errore: Stack Vuoto\n");
        return -1;
    }
    return s->data[s->top]; //ritorna l'elemento in cima alla pila identificato da s->top
}

//FUNZIONE POP
int pop(Stack *s) {
    if(isEmpty(s)) {        //Controllo per assicurarmi di non rimuovere un elemnto dallo stack vuoto così da generare comportamenti non prevedibili
        printf("Errore: stack vuoto\n");
        return -1;  //Valore di errore
    }
    return s->data[(s->top)--];
}

//FUNZIONE PUSH
void push (Stack *s, int value) {
    if (isFull(s)) {
        printf("Errore: stack pieno\n");
        return;
    }
    s->data[++(s->top)] = value;    //Incrementa il valore della componente top nella struttura dati
}