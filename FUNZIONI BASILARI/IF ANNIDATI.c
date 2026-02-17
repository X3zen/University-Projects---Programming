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
    if (voto == 1) {
        printf("hai preso uno... sei uno sfigato!!");
    }
    else {
        if(voto == 2) {
            printf("due? ma sei serio??!");
        }
        else {
            if (voto == 3) {
                printf("ti conviene studiare che sei a metà dalla sufficenza!!");
            }
            else {
                if(voto == 4) {
                    printf("vedo che siamo fan di khada jhin");
                }
                else {
                    if (voto == 5) {
                        printf("siamo a metà del traguardo, adesso ti manca l'altra metà");
                    }
                    else {
                        if (voto == 6) {
                            printf("almeno il minino indispensabile lo hai fatto... GG");
                        }
                        else {
                            if(voto == 7) {
                                printf("hai già una media più alta della mia :')");
                            }
                            else {
                                if(voto == 8) {
                                    printf("vedo che abbiamo studiato");
                                }
                                else {
                                    if (voto == 9) {
                                        printf("scommetto che sei uno di quelli che dice di non essere pronto per la verifica");
                                    }
                                    else {
                                        if (voto == 10) {
                                            printf("vabbè fra, sei escanor, l'essere perfetto... non so che dire");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
return 0;
}