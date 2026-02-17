#include <stdio.h>

int main() {
    char ciao1[]={'C','i','a','o','\0'};        //Stringa vera e propria -- \0 è il carattere di fine stringa
    char ciao2[]={'C','i','a','o','!'};         //array di char, NON stringa
    char ciao3[]="Ciao";                        //stringa
    char ciao4[]={'C','i','a','o','!','\0'};    //stringa
    
    printf("%s", ciao1);
    printf("\n");
    printf("%s", ciao2);
    printf("\n");
    printf("%s", ciao3);
    printf("\n");
    printf("%s", ciao4);
    return 0;
}