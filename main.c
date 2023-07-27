#include <stdio.h> // Biblioteca padrão para usar os comandos em C.
#include <stdlib.h> // Biblioteca para usar o "system("pause");".
#include <locale.h> // Biblioteca para usar o "setlocale(LC_ALL, "Portuguese_Brazil.1252");".

int main(void) 
{
    
    setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Comando utilizado para mostrar a acentuação e caracteres do Portugûes do Brasil.

    // Atribuindo valores para variáveis de diferentes tipos...
    int n1 = 10;
    float n2 = 10.5;
    double n3 = 1.23456;
    char letra = 'a';
    char frase[] = "Boa tarde!";

    printf("Olá, mundo!\n"); // Clássico "Olá, mundo!" para dar sorte. \n -> Pular uma linha.

    printf("%d, %.1f, %c, %s, %f.\n", n1, n2, letra, frase, n3); // Mostrando como formatar variáveis em um "printf". %.1f -> Uma casa decimal após a vírgula.
    
    // Criando diversas variáveis e utilizando-as para fazer operações aritméticas. scanf -> Escanear o que o usuário digitou.
    int v1, v2, a, s, m, d;

    printf("Digite um número inteiro, por favor: ");
    scanf("%d", &v1);

    printf("Digite mais um número inteiro, por favor: ");
    scanf("%d", &v2);

    a = v1 + v2;
    s = v1 - v2;
    m = v1 * v2;
    d = v1 / v2;

    printf("Valores utilizados: %d e %d. Adição: %d. Subtração: %d. Multiplicação: %d. Divisão: %d.\n", v1, v2, a, s, m, d);

    system("pause"); // Somente para Windows! Para não fechar a tela logo após a execução do programa.
    return 0; // Retornar a função "int main", para que o programa entenda que tudo ocorreu conforme solicitado.
}