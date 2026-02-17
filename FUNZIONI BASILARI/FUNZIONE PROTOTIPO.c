#include <stdio.h>

int maximum (int a, int b, int c) {
    int max = a;

    if (b > max) {
        max = b;
    }
    if (c > max) {
            max = c;
    }
return max;
}

int main (){
    int num1;
    int num2;
    int num3;

    printf("inserire tre numeri: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("\nIl massimo dei numeri è: %d", maximum(num1, num2, num3));
return 0;
}