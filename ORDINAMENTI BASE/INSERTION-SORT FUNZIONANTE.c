#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//FUNZIONE PER STAMPA DI ARRAY
void stampaArray(int array[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* allocaCopia(int array[], int n) {
    int* copiaArray=malloc(n * sizeof(int));
    if(copiaArray == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }
//COPIA DELL'ARRAY ORIGINALE
    for(int i=0; i<n; i++) {
        copiaArray[i] = array[i];
    }
    return copiaArray;
}

//FUNZIONE CHE CREA UNA COPIA DEL ARRAY CON INSERTION SORT
int* insertionSort(int array[], int n) {
    int* sorted = allocaCopia(array, n);

//ALGORITMO INSERTION SORT
    for(int i=1; i<n; i++) {
        int key = sorted[i];
        int j =i-1;

        printf("Confronto %d con la chiave %d\n", sorted[j], key);

//SPOSTA GLI ELEMENTI MAGGIORI DELLA KEY A DESTRA
        while(j>=0 && sorted[j]>key) {
            printf("Inserimento %d -> shift a destra %d\n", sorted[j+1], sorted[j]);
            sorted[j+1]=sorted[j];
            j--;
        }
        sorted[j+1]=key;

        printf("Array attuale: ");
        stampaArray(sorted, n);
        printf("Premere invio per continuare...");
        getchar();
    }
    return sorted;
}

//INIZO PROGRAMMA MAIN
int main() {
    int array[]={5,3,8,4,2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    int* ordinato = insertionSort(array, n);
    if(ordinato != NULL) {
        printf("Array ordinato (insertion-sort): ");
        stampaArray(ordinato, n);
        free(ordinato);
    }
    return 0;
}