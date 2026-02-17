#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//FUNZIONE PER STAMPA ARRAY
void stampaArray(int array[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* allocaCopia(int array[], int n) {
    int* copiaArray = malloc(n * sizeof(int));
    if (copiaArray == NULL) {
        printf("Errore di allocazione memoria\n");
        return NULL;
    }
//COPIA ARRAY ORIGINALE
    for(int i=0; i<n; i++) {
        copiaArray[i] = array[i];
    }
    return copiaArray;
}

//FUNZIONE DI ORDINAMENTO SELECTION SORT
    int* selectionSort(int array[], int n) {
    int* sorted = allocaCopia(array, n);

//ORDINAMENTO SELECTION-SORT
    int j;
    int min;
    int i;
    int temp;
    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(sorted[j] < sorted[min]) {
                min = j;
            }
        }
//SCAMBIO IL MINIMO CON L'ELEMENTO IN POSIZIONE I
        temp = sorted[i];
        sorted[i] = sorted[min];
        sorted[min] = temp;
        printf("Scambio %d con %d\n", sorted[i], sorted[min]);
        printf("Array attuale: ");
        stampaArray(sorted, n);
        printf("premi invio per continuare...");
        getchar();
    }
    return sorted;
}

//INZIO PROGRAMMA MAIN
int main() {
    int array[]={5,3,8,4,2};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array originale: ");
    stampaArray(array, n);

    int* ordinato = selectionSort(array, n);
    if(ordinato != NULL) {
        printf("Array ordinato (Selection sort): ");
        stampaArray(ordinato, n);
        free(ordinato);
    }
    return 0;
}