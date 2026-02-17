#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* insertionSortCopy (const int arr[], int n) {
    int* sorted = malloc(n * sizeof(int));          //ALLOCAZIONE DELLA MEMORIA CON MALLOC
    if(sorted==NULL) {
        return NULL;                                //GESTIONE ERRORE DI ALLOCAZIONE
    }
//COPIA DELL'ARRAY ORIGINALE PER MANTENERE L'INFO ORIGINALE
    for(int i=0; i<n; i++) {
        sorted[i] = arr[i];
    }
//ALGORITMO INSERTION-SORT
    for(int i=1; i<n; i++) {
        int key=sorted[i];
        int j=i-1;
        while(j>=0 && sorted[j] > key) {        //PER TUTTI GLI ELEMENTI DELL'ARRAY SELEZIONA UNA CHIAVE LA CONFRONTA CON TUTTI GLI
            sorted[j+1]=sorted[j];              //ELEMENTI SUCCESSIVI (DUE CICLI ANNIDATI)  --  COMPLESSITA' O(N^2)
            j--;                                //SHIFTA TUTTI GLI ELEMENTI MAGGIORI DELLA CHIAVE VERSO DESTRA
        }
        sorted[j+1] = key;
    }
    return sorted;
}