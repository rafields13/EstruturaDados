#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    int matriz[3][3], i, j;

    printf("\nDigite os valores para a Matriz, por favor:\n\n");

    // Entrada de dados:
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Saída de dados:
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("\nElemento[%d][%d] <- %d.", i, j, matriz[i][j]);
        }
    }

    printf("\n"); // Pular uma linha.

    system("pause");
    return 0;
}