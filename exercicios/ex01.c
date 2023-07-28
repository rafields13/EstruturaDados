#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    int n1, n2, soma;

    printf("Digite um número, por favor: ");
    scanf("%d", &n1);

    printf("Digite mais um número, por favor: ");
    scanf("%d", &n2);

    soma = n1 + n2;

    printf("%d + %d = %d.\n", n1, n2, soma);

    system("pause");
    return 0;
}