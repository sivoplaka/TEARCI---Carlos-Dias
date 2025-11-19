#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int sum = a + b;

    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    printf("Soma de a e b: %d\n", sum);

    // Ponto de depuração
    for (int i = 0; i < 5; i++) {
        printf("i: %d\n", i);
    }

    return 0;
}