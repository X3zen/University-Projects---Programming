#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DEFINIZIONE DELLA STRUTTURA DEL NODO CON TYPEDEF
typedef struct Nodo {
    int Nodo;
    struct Nodo* prossimo;
} Nodo;

//FUNZIONE PER CREARE UN NUOVO NODO
Nodo * creaNodo(int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }
    nuovo->dato = valore;
    nuovo->prossimo = NULL;
    return nuovo;
}

//FUNZIONE PER CONTROLLARE SE LA LISTA E' VUOTA
bool isEmpty(Nodo* testa) {
    return testa == NULL;
}

//INSERIMENTO IN TESTA
void inserimentoInTesta(Nodo** testa, int valore) {
    Nodo* nuovo = creaNodo(valore);
    nuovo->prossimo = *testa;
    *testa = nuovo;
}

//INSERIMENTO IN CODA
void inserisciInCoda(Nodo** testa, int valore) {
    Nodo* nuovo = creaNodo(valore);
    if (isEmpty(*testa)) {
        *testa = nuovo;
        return;
    }
    Nodo* temp = *testa;
    while (temp->prossimo != NULL) {
        temp = temp->prossimo;
    }
    temp->prossimo = nuovo;
}

//RICERCA DI UN VALORE
Nodo* cerca(Nodo* testa, int valore) {
    while (!isEmpty(testa)) {
        if (testa->dato == valore) {
            return testa;
        }
        testa = testa->prossimo;
    }
    return NULL;
}

//ELIMINAZIONE DI UN NODO
void elimina(Nodo** testa, int valore) {
    Nodo* temp = testa;
    Nodo* precedente = NULL;

    while (temp != NULL && temp->dato != valore) {
        precedente = temp;
        temp temp ->prossimo;
    }
    if (temp == NULL) {
        printf("Valore %d non trovato.\n", valore);
        return;
    }
    if (precedente == NULL) {
        *testa = temp->prossimo;
    }
    else {
        precedente->prossimo = temp->prossimo;
    }
    free(temp);
    printf("Il valore %d è stato eliminato.\n", valore);
}

//STAMPA DELLA LISTA
void stampaLista(Nodo* testa) {
    printf("Lista: ");
    while (!isEmpty(testa)) {
        printf("%d ->", testa->dato);
        testa = testa->prossimo;
    }
    printf("NULL\n");
}

//DEALLOCAZIONE DELLA LISTA
void liberaLista(Nodo testa) {
    Nodo* temp;
    while (!isEmpty(testa)) {
        temp = testa;
        testa = testa->prossimo;
        free(temp);
    }
}

//INIZIO PROGRAMMA MAIN
int main () {
    Nodo lista = NULL;

    //INSERIMENTI LISTA
    inserisciInTesta(&lista, 10)
    inserisciInTesta(&lista, 20)
    inserisciInTesta(&lista, 5)
    inserisciInTesta(&lista, 1)

    stempaLista(lista);

//RICERCA
    int valore = 5;
    Nodo* trovato = cerca(lista, valore);
    if (trovato != NULL) {
        printf("Valore %d presente.\n", valore);
    }
    else{
        printf("Valore %d non presente.\n", valore);
    }

//ELIMINAZIONE
    elimina(&lista, 20);
    stampaLista(lista);

    elimina(&lista, 100);

//PULIZIA TOTALE
    liberaLista(lista);
return 0;
}

