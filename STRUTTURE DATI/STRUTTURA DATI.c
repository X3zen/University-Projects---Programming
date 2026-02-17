#include <stdio.h>
#include <stdbool.h>

struct Studente {           //definizione di struttura Studente 
    char nome[50];
    int matricola;
    float votoEsame;
    bool esameSuperato;
};

int main () {

    struct Studente s1 = {"Luca Rossi", 123456, 28.5, true};

    printf("Nome: %s\n", s1.nome);
    printf("matricola: %d\n", s1.matricola);
    printf("Voto Esame: %1f\n", s1.votoEsame);
    printf("Esame Superato: %s\n", s1.esameSuperato ? "si" : "no");
}