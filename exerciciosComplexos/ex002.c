#include <stdio.h>
#include <string.h>

struct Employee {
    char name[45];
    float novemberSales;
    float decemberSales;
    float januarySales;
};

void registerEmployee(struct Employee employees[], int *quantityEmployees) {
    if (*quantityEmployees >= 15) {
        printf("Registered employees limit reached!\n");
    }

    printf("Enter the employee's name: ");
    scanf(" %[^\n]", employees[*quantityEmployees].name);

    printf("Enter the november sales: ");
    scanf("%f", &employees[*quantityEmployees].novemberSales);

    printf("Enter the december sales: ");
    scanf("%f", &employees[*quantityEmployees].decemberSales);

    printf("Enter the january sales: ");
    scanf("%f", &employees[*quantityEmployees].januarySales);

    (*quantityEmployees)++;
    printf("Employee registered successfully!\n");
}