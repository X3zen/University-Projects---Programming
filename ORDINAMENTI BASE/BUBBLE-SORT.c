#include <stdio.h>
#include <stdbool.H>

//FUNZIONE DI ORDINAMENTO BUBBLESORT
int bubblesort (int array[], int n) {
    int* sorted = allocaCopia(array, n);    //CHIAMATA AD UNA FUNZIONE INTERNA CHE ALLOCA LO SPAZIO PER FARE UNA COPIA DELL'ARRAY

//ORDINAMENTO BUBBLESORT
    bool scambiato;
    int temp;
    do {                                    //CICLO SU TUTTI GLI ELEMENTI FINCHE' CI SONO SCAMBI DA EFFETTUARE
        scambiato = false;
        for (int = i,; i < n; i++) {
            if (sorted[i] > sorted[i+1]) {  //SE I DUE ELEMENTI SUCCESSIVI NON SONO IN ORDINE TRA LORO LI SCAMBIA
                temp = sorted[i];
                sorted[i] = sorted[i+1];
                sorted[i+1] = temp;
                scambiato = true;
            }
        }
    }   while (scambiato);
            return sorted;
}