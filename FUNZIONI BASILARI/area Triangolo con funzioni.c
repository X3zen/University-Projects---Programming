#include <stdio.h>

int inputDati() {
    int base;
    int altezza;
    int area;
    const int calc = 2;

    printf("inserire base: ");
    scanf("%d", &base);

    printf("\ninserire altezza: ");
    scanf("%d", altezza);

    area = (base * altezza) / 2;

    printf("il risultato è: %d", area);
}

int main () {
    inputDati();
    return 0;
}