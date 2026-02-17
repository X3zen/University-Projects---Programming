#include <stdio.h>

int main () {
    int giorno;
    int i=0;

    while (i==0) {
        printf("inserire il giorno desiderato (da 1 a 7): \n");
        scanf("%d", &giorno);
        if (giorno > 7 || giorno < 1) {
            printf("il giorno da lei selezionato non è valido. Prego riprovi\n");
        }
        else {
            i++;
        }
    }

    switch (giorno) {
        case 1:
        printf("lunedi");
        break;

        case 2:
        printf("martedi");
        break;

        case 3:
        printf("mercoledi");
        break;

        case 4:
        printf("giovedi");
        break;

        case 5:
        printf("venerdi");
        break;

        case 6:
        printf("sabato");
        break;

        case 7:
        printf("domenica");
    }
return 0;
}