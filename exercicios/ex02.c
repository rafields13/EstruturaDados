#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    int n;

    printf("Digite um número, por favor: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("O número %d é par!\n", n);
    } else {
        printf("O número %d é ímpar!\n", n);
    }

    system("pause");
    return 0;
}