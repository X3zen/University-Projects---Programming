#include <stdio.h>

int main() {

    char nome[10];
    char cognome[10];

    printf("inserire il proprio nome: ");
    scanf("%s", &nome);

    printf("\n");

    printf("inserire il proprio cognome: ");
    scanf("%s", &cognome);

    printf("\n");

    printf("Benvenuta/o %s %s", nome, cognome);

    return 0;
}