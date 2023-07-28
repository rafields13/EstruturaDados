#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    char p[45];

    printf("Digite uma palavra, por favor: ");
    scanf("%s", &p);

    for (int i = 0; i < strlen(p); i++) {
        printf("%c\n", p[i]);
    }

    system("pause");
    return 0;
}