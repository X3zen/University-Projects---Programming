#include <stdio.h>

int MCD (int u, int v) {    //calore di ritorno int
    int temp;
    while (v!=0){
        temp=u%v;
        u=v;
        v=temp;
    }
    return u;               
}
    int main (void) {
        int result;
        result = MCD(150,35);
        printf("il Massimo comun divisiore di 150 e 35 è %i\n", result);
        result = MCD (1026, 405);
        printf("il Massimo comun divisiore di 1026 e 405 è %i\n", result);
        printf("il Massimo comun divisiore di 83 e 240 è %i\n", MCD(83, 240));
        return 0;
    }