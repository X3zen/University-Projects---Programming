//FORMATTAZZIONE DELL'OUTPUT
#include <stdio.h>

int main() {

    printf("format-control-string, other-arguments");
    //la format-control-string descrive come formattare l'output
    //gli other-arguments devono corrispondere in numero e tipo presenti nella stringa e terminano con uno specificatore di conversione (d, f, s, c, x)

    printf("%d \n", 455);               //455 :: formato intero
    printf("%i \n", 455);               //455 :: formato intero
    printf("%d \n", +455);              //455 :: default il + non viene stampato
    printf("%d \n", -455);              //-455 :: formato intero negativo
    printf("%hd \n", 32000);            //32000 :: long
    printf("%ld \n", 2000000000L);      //2000000000 :: long
    printf("%o \n", 455);               //707 :: ottale
    printf("%u \n", 455);               //455 :: unsigne
    printf("%u \n", -455);              //4294966841 :: unsigne per un valore con il segno che viene mal interpretato
    printf("%x \n", 455);               //1c7 :: esadecimale
    printf("%X \n", 455);               //1c7 :: esadecimale

    //i valori in virgola mobile contengono una parte intera, un punto decimale ed una parte decimale
    //gli specificatori sono e, f, g

    printf("%e \n", 1234567,89);        //1.234568e+06 :: Esponenziale
    printf("%e \n", +1234567,89);       //1.234568e+06 :: Esponenziale
    printf("%e \n", -1234567,89);       //-1.234568e+06 :: Esponenziale con segno
    printf("%E \n", 1234567,89);        //1.234568E+06 :: le lettere sono stampate in maiuscolo
    printf("%f \n", 1234567,89);        //1234567.890000 :: float con precisione di default pari a a cifre dopo la virgola(0.000001)
    printf("%g \n", 1234567,89);        //1.23457e+06 :: viene trasformata in %f o %e in base alla magnitudine, in questo caso in %e
    printf("%G \n", 1234567,89);        //1.23457E+06 :: come sopra ma in maiuscolo

    //CARATTERI
    //Gli specificatori di conversione sono c ed s
    //c richiede un argomento di tipo char
    //s richiede come argomento un puntatore a char e stampa caratteri fino al carattere di terminazione ('\0')

    char iniziale ='A';                                     //dichiarazione di un valore char dentro a una variabile
    printf("%c \n", iniziale);                              //A :: stampa del carattere dentro la variabile dichiarata
    printf("%s \n", "questa è una stringa");                //questa è una stringa :: stampa la stringa tra i doppi apici
    
    char stringa[] = "questa è una stringa";                //dichiarazione di un array di char a cui andiamo ad assegnare una stringa tra doppi apici
    printf("%s \n", stringa);                               //questa è una stringa :: stampa dell'array dichiarato
    
    const char *stringaPtr = "anche questa è una stringa";  //passaggio di un puntatore ad una stringa
    printf("%s \n", stringaPtr);                            //anche questa è una stringa :: puntatore dichiarato sopra

    //ALTRI SPECIFICATORI
    //p: visualizza un valore puntatore in modo definito dall'implementazione
    //%: visualizza il carattere percentuale

    int x = 12345;                                  //dichiarazione di x
    int *ptr = &x;                                  //dichiarazione di un puntatore (*) a cui assegniamo l'indirizzo della variabile x
    printf("il valore di ptr è %p \n", ptr);        //0x7ffff6eb911c :: stampa del valore del puntatore
    printf("l'indirizzo di x è %p \n\n", &x);       //0x7ffff6eb911c :: stampa dell'indirizzo
    printf("stampa di un %% in una stringa \n");    //stampa di un % in una stringa :: stampa il sombolo %

    //STAMPA CON LARGHEZZE DI CAMPO
    //un intero che rappresenta la larghezza di campo è inserito tra il segno di percentuale (%) e lo specificatore (es. %4d)

    printf("%4d \n", 1);        //1
    printf("%4d \n", 12);       //12
    printf("%4d \n", 123);      //123
    printf("%4d \n", 1234);     //1234
    printf("%4d \n", 12345);    //12345
    printf("%4d \n", -1);       //-1 ::
    printf("%4d \n", -12);      //-12 ::
    printf("%4d \n", -123);     //-123 ::
    printf("%4d \n", -1234);    //-1234 ::
    printf("%4d \n", -12345);   //-12345 ::

    //STAMPA CON PRECISIONE
    //interi, la precisione indica il numero minimo di cifre da stampare
    //con e ed f la precisione è il numero di cifre che devono apparire dopo il punto decimale
    //con g la precisione è il numero di cifre significative da stampare
    //con s la precisione è il numero massimo di cartatteri scritti dall'inizio della stringa

    int i = 873;
    printf("\t%.4d \n\t %.9d \n\n", i, i);                //0873 (%.4d) - 000000873 (%.9d) :: tabulazione

    double f = 123.94536;
    printf("\t%3.f \n\t %.3e \n\t %.3g \n\n", f, f, f);  //123.945 (%.3f) - 1.239e+02 (%.3e) - 124 (%.3g) :: esponenziale

    char s[] = "tanti auguri";
    printf("\t %.11s \n", s);                            //tanti auguri :: stampata con 11 caratteri

    //COMBINAZIONE DI LARGHEZZA E PRECISIONE

    printf("%9.3f", 123.456789);                //123.456 :: 9 caratteri totali e 3 dopo la virgola

    printf("%*.*f", 7, 2, 98.736)               //in modo parametrico si inseriscono gli * nella format-control-string e mettere larcghezza e precisione nella nostra printf

    //FLAG
    //- (SEGNO MENO) : allinea a sinistra l'output all'interno del campo specificato
    //+ (SEGNO PIU') : visualizza un segno piu precedendo i valori positivi e un segno meno precedendo i valori negativi
    //spazio : stampa uno spazio prima di un valore positivo non stampato con il flag +
    //# : in ottale premette lo 0; in esadecimale premette 0x; per e/f/g forza il punto decimale senza frazione
    //0 : riempe un campo con zeri iniziali

    puts("1234567890123456789012345678901234567890");               //1234567890123456789012345678901234567890
    printf("%10s %10d %10c %10f \n\n", "hello", 7, 'a', 1.23);      //      hello        7         a  1.230000  :: incolonnati verso destra

    puts("1234567890123456789012345678901234567890");               //1234567890123456789012345678901234567890
    printf("%-10s %-10d %-10c %-10f \n\n", "hello", 7, 'a', 1.23);  //hello     7        a  1.230000            :: incolonnati verso sinistra

return 0;
}