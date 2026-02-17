#include <stdio.h>

int modulo() {
    int a = 25;                                 //DICHIARAZIONE DELLE VARIABILI
    int b = 5;
    int c = 10;
    int d = 7;
                                                //l'operatore modulo permette di calcolare il resto della divisione
    printf("a%%b = %d\n", a%b);                 //output resto 0
    printf("a%%c = %d\n", a%c);                 //output resto 5
    printf("a%%d = %d\n", a%d);                 //output resto 4
    printf("a / d * d + a%%b = %d", a/d*d+a%b); //output resto 25
}

int main() {
    modulo();                                   // richiamo della funzione
return 0;
}