#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DEFINIZIONE DELLA STRUTTURA NODO
struct Nodo {
    int dato;               //INTERO IN QUESTO CASO MA PUO' ESSERE DI QUALSIASI TIPO
    struct Nodo* prossimo;  //UN PUNTATORE AL NODO SUCCESSIVO, INDIRIZZO DELLA LOCAZIONE DI MEMORIA FISICA DEL NODO || NODO* E' UN PUNTATORE A SE STESSO
};                          //LA DEFINIZIONE DEL PUNTATORE ALLA STESSA STRUTTURA E' FONDAMENTALE PER ASSICURARE CHE LA DEFINIZIONE SIA AUTOREFERENZIALE

//FUNZIONE ISEMPTY
//CONTROLLA SOLO IL PUNTATORE DEL PRIMO ELEMENTO DELLA LISTA E' NULL. SE IL PRIMO E' NULL NON ESISTONO ALTRI ELEMENTI
//NON ESISTE UN ISFULL PERCHE' E' POSSIBILE CREARE SEMPRE NUOVE DIMENSIONI 

bool isEmpty(Nodo* testa) {
    return testa == NULL;
}

//FUNZIONE CREANODO

Nodo* creaNodo (int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));          //ALLOCAZIONE DELLO SPAZIO IN MEMORIA TRAMIME "MALLOC" CHE RESTITUISCE L'INDIRIZZO FISICO DELLA MEMORIA
    if (nuovo == NULL) {
        printf("Errore di allocazione memoria.\n");     //ERRORE: SE L'ALLOCAZIONE RITORNA UN NULL IL DATO NON E' STATO MEMORIZZATO
        exit(1);
    }
    nuovo->dato = valore;           //SE NON CI SONO ERRORI IL NUOVO NODO CONTIENE IL VALORE NELLA COMPNENTE DATO DELLA STRUTTURA MA NULL AL PUNTATORE AL NODO SUCCESSIVO (NON ESISTE ANCORA)
    nuovo->prossimo = NULL;
    return nuovo;
}

//FUNZIONE INSERISCIINTESTA

void inserisciInTesta(Nodo** testa, int valore) {
    Nodo* nuovo = creaNodo(valore);                     //CREA UN NODO TRAMITE LA FUNZIONE PRECEDENTE CREANODO
    nuovo->prossimo = *testa;                           //AL NODO APPENA CREATO ASSEGNA IL PUNTATORE ALLA TESTA DELLA LISTA
    *testa = nuovo;                                     //ALLA PRECEDENTE TESTA ASSEGNA IL PUNTARE AL NODO APPENA CREATO
}

//FUNZIONE INSERISCIINCODA

void inserisciInCoda(Nodo** testa, int valore) {
    Nodo* nuovo = creaNodo(valore);                     //CREA UN NUOVO NODO
    if (*testa == NULL) {                               //SE LA LISTA E' VUOTA, IL NUOVO NODO E' LA TESTA
        *testa = nuovo;
        return;
    }
    Nodo* temp = *testa;                                //ALTRIMENTI E' NECESSARIO SCORRERE LA LISTA FINO ALLA CODA ED RIASSEGNARE IL PUNTATORE
    while (temp->prossimo != NULL) {
        temp = temp->prossimo;
    }
    temp->prossimo = nuovo;
}

//FUNZIONE ELIMINA

void elimina(Nodo** testa, int valore) {
    Nodo* temp = *testa;                    //TEMP = ELEMENTO CORRENTE
    Nodo* precedente = NULL;                //PRECEDENTE = NULL ALLA PRIMA ITERAZIONE

    While (temp != NULL && temp ->dato != valore) {     //CERCA L'ELEMENTO DA ELIMINARE SCORRENDO LA LISTA
        precedente = temp;
        temp = temp->prossimo;
    }

    if (temp == NULL) {                                 //SE TEMP E' NULL IL VALROE CERCATO NON ESISTE
        printf("Valore %d non trovato.\n", valore);
        return;
    }

    if (precedente == NULL) {                           //SE PRECEDENTE E' NULL, L'ELEMENTO DA ELIMINARE E' LA TESTA
        *testa = temp->prossimo;
    }
    else {                                              //SI ELIMINA L'ELEMENTO SEMPLICEMENTE RIASSEGNANDO I PUNTATORI
        precedente->prossimo = temp->prossimo;
    }

    free(temp);                                         //LIBERA LA MEMORIA COL COMANDO FREE
    printf("Valore %d eliminato.\n", valore);           //STAMPA DEL SUCCESSO DELL'OPERAZIONE
}