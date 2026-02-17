#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//FUNZIONE DI STAMPA PER ARRAY
void stampaArray (int array[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* allocaCopia(int array[], int n) {
    int* copiaArray = malloc(n * sizeof(int));
    if (copiaArray == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }
//COPIA ARRAY ORIGINALE
    for (int i=0; i<n; i++) {
        copiaArray[i] = array[i];
    }
    return copiaArray;
}

//FUNZIONE DI ORDINAMENTO BUBBLESORT
int* bubbleSort(int array[], int n) {
    int* sorted = allocaCopia(array, n);
//ORDINAMENTO BUBBLESORT
    bool scambiato;
    int temp;
    do {
        scambiato = false;
        for (int i=0; i<n-1; i++) {
            if (sorted[i] > sorted[i+1]) {
                printf("scambio %d con %d\n", sorted[i], sorted[i+1]);
                temp = sorted[i];
                sorted[i] = sorted[i+1];
                sorted[i+1] = temp;
                scambiato = true;
            }
        }
        printf("Array attuale: ");
        stampaArray(sorted, n);
        printf("premi invio per continuare...");
        getchar();
    } while (scambiato);
return sorted;
}

//INIZIO PROGRAMMA
int main() {
    int array[] = {5,3,8,4,2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale");
    stampaArray(array, n);

    int* ordinato  = bubbleSort(array, n);
    if (ordinato != NULL) {
        printf("Array ordinato: ");
        stampaArray(ordinato, n);
        free(ordinato);
    }
}