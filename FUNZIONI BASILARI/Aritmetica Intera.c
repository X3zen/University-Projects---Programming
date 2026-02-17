#include <stdio.h>

int aritmeticaIntera() {
    int a = 25;                 //VAR intera
    int b = 2;                  //VAR intera
    float c = 25.0;             //VAR float 
    float d = 2.0;              //VAR float 

    printf("6 + a / 5 * b = %d\n", 6+a/5*b);    // ogni volta un espressione è composta da 2 interi, C esegue l'operazione usando l'aritmetica intera
    printf("a / b * b = %i\n", a/b*b);          //da 24 perchè il risultato con la virgola non viene salvato in INT
    printf("c / d * d = %f\n", c/d*d);          
    printf("-a = %d\n", -a);                    //il valore della VAR a viene negato usando l'operatore unario meno (-)
}

int main() {
    aritmeticaIntera();                         //Richiamo della funzione
    return 0;
}
