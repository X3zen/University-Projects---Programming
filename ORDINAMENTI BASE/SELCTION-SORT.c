#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* selectionSort (int array[], n) {
    int* sorted = allocaCopia(array, n);

//ALGORITMO DEL SELECTION SORT
    int i;
    int j;
    int min;
    int temp;
    for (i=0; i<n-1; i++) {         //PER TUTTI GLI ELEMENTI DELL'ARRAY CERCA L'ELEMENTO MINIMO
        min = i;                    //NON ORDINATO PIU' IN CODA E LO CONFRONTA CON TUTTI GLI
        for(j=i+1; j<n; j++) {      //ELEMENTI SUCCESSIVI USANDO 2 CICLI ANNIDATI -- COMPLESSITA' O(N^2)
            if (sorted[j] < sorted[min]) {
                min = j;
            }
        }
//SCAMBIA IL MINIMO CON L'ELEMENTO IN POSIZIONE I
        temp = sorted[i];
        sorted[i] = sorted[min];
        sorted[min] = temp;
    }
return sorted;
}