#include <stdio.h>
#include <stdbool.h>

int main() {

    int integervar=100;                         //dichiarazione intero
    float floatvar=331.79f;                     //dichiarazione float
    double doublevar=8.44e+11;                  //dichiarazione double esponenziale
    _Bool boolvar=0;                            //dichiarazione booleana falsa

    printf("integervar = %i\n", integervar);    //%i per gli interi                 =100
    printf("floatvar = %f\n", floatvar);        //%f per i float                    =331.790009
    printf("doublevar = %e\n", doublevar);      //%e per annotazione esponenziale   =8.40000e+11
    printf("doublevar = %g\n", doublevar);      //%g selezione auto tra %f & %e     =8.44e+11
    printf("boolvar = %i\n", boolvar);          //%i perchè è 0 o 1                 =0

    return 0;
}