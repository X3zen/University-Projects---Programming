#include <stdio.h>
#include <string.h>

int main () {
    int voto;
    int i = 0;

    while (i==0){
    printf("inserire il voto preso: ");
    scanf("%d", &voto);

        if (voto >10) {
            printf("il valore da voi immesso non è valido, per favore reinseritelo \n");
        }
            else {
                i++;
            }
    }

    if (voto >= 6) {                                //SELEZIONE DELL'IF, SE VERO ESEGUE QUELLO CHE HA NEL SUO INTERNO
        printf("hai superato l'esame :) ");
    }
        else {                                      //ELSE, SE LA CONDIZIONE DEL IF NON VIENE RISPETATA ESEGUIRA' L'ALTRIMENTI
            printf("non hai superato l'esame :'(");
        }
 return 0;
}

//IF si può anche scrivere:
//printf((condizione)? "azione se la cond è vera" : "azione se la cond è falsa");