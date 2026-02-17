#include <stdio.h>

int main() {
    int num1;           //assegnamento variabili
    int num2=0;         //assegnamento variabile con inizializzazione
    int sum;            
    
    printf("Questo programma fa la somma di due numeri!! \n");  //stampa a schermo
    printf("inserire il primo numero: \n");
    scanf("%d", &num1);                                         //lettura dell'input, %d indica che si aspetta un intero come input || & indica l'operatore address-of,
                                                                //serve a indicare l'indirizzo di memoria corrispondente alla variabile %d
    printf("inserire il secondo numero: \n");
    scanf("%d", &num2);
    
    sum = num1 + num2;                                          //calcolo della somma che la mette nella variabile sum
    
    printf("la somma dei numeri inseriti e': %d", sum);         //restituzione in output della variabile sum

    return 0;
}