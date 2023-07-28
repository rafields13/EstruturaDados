#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	
	printf("Aoba!\n");
	
	system("pause");
	return 0;
}
