#include <stdio.h>
#include <string.h>

struct Employee {
    char name[45];
    float novemberSales;
    float decemberSales;
    float januarySales;
};

void registerEmployee(struct Employee employees[], int quantityEmployees) {
    for (int index = 0; index < quantityEmployees; index++) {
        printf("Enter the employee's name %d: ", index + 1);
        scanf(" %[^\n]", employees[index].name);

        printf("Enter the november sales: ");
        scanf("%f", &employees[index].novemberSales);

        printf("Enter the december sales: ");
        scanf("%f", &employees[index].decemberSales);

        printf("Enter the january sales: ");
        scanf("%f", &employees[index].januarySales);

        printf("Employee registered successfully!\n");
    }
}

float calculateScore(float sales) {
    return sales / 1000;
}

void calculateEmployeeScore(struct Employee employees[], int quantityEmployees) {
    for (int index = 0; index < quantityEmployees; index++) {
        employees[index].novemberSales = calculateScore(employees[index].novemberSales);
        employees[index].decemberSales = calculateScore(employees[index].decemberSales);
        employees[index].januarySales = calculateScore(employees[index].januarySales);
    }
}

float calculateOverallScore(float novemberSales, float decemberSales, float januarySales) {
    return novemberSales + decemberSales + januarySales;
}

void calculateOverallEmployeeScore(struct Employee employees[], int quantityEmployees) {
    for (int index = 0; index < quantityEmployees; index++) {
        employees[index].novemberSales = calculateOverallScore(employees[index].novemberSales, employees[index].decemberSales, employees[index].januarySales);
    }
}

void highestScore(struct Employee employees[], int quantityEmployees) {
    float highest = -1;
    int highestIndex = -1;

    for (int index = 0; index < quantityEmployees; index++) {
        if (employees[index].novemberSales > highest) {
            highest = employees[index].novemberSales;
            highestIndex = index;
        }
    }

    printf("Highest Score: %.2f - Employee: %s\n", employees[highestIndex].novemberSales, employees[highestIndex].name);
}

float calculateTotalSold(struct Employee employees[], int quantityEmployees) {
    float totalSold = 0;

    for (int index = 0; index < quantityEmployees; index++) {
        totalSold += employees[index].novemberSales;
    }

    return totalSold * 1000;
}

void main() {
    struct Employee employees[15];
    int quantityEmployees = 15;

    registerEmployee(employees, quantityEmployees);
    calculateEmployeeScore(employees, quantityEmployees);
    calculateOverallEmployeeScore(employees, quantityEmployees);

    printf("\nOverall employee scores:\n");
    for (int index = 0; index < quantityEmployees; index++) {
        printf("Employee: %s | Overall score: %.2f\n", employees[index].name, employees[index].novemberSales);
    }

    highestScore(employees, quantityEmployees);

    float totalSold = calculateTotalSold(employees, quantityEmployees);
    printf("Total sold: %.2f\n", totalSold);
}