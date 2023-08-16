#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char clientName[45];
    float balance;
};

void registerAccount(struct BankAccount bankAccounts[], int *quantityAccounts) {
    if (*quantityAccounts >= 15) {
        printf("Registered account limit reached!\n");
    }

    printf("Enter account number: ");
    scanf("%d", &bankAccounts[*quantityAccounts].accountNumber);

    for (int index = 0; index < *quantityAccounts; index++) {
        if (bankAccounts[index].accountNumber == bankAccounts[*quantityAccounts].accountNumber) {
            printf("Account with that number already exists!\n");
        }
    }

    printf("Enter the customer's name: ");
    scanf(" %[^\n]", bankAccounts[*quantityAccounts].clientName);

    printf("Enter the balance: ");
    scanf("%f", &bankAccounts[*quantityAccounts].balance);

    (*quantityAccounts)++;
    printf("Account registered successfully!\n");
}

void viewAllClientAccounts(struct BankAccount bankAccounts[], int quantityAccounts) {
    char findClientName[45];
    printf("Enter the customer's name: ");
    scanf(" %[^\n]", findClientName);

    printf("Customer accounts %s: \n", findClientName);
    for (int index = 0; index < quantityAccounts; index++) {
        if (strcmp(findClientName, bankAccounts[index].clientName) == 0) {
            printf("Acount: %d | Balance: %.2f\n", bankAccounts[index].accountNumber, bankAccounts[index].balance);
        }
    }
}

void deleteLowestBalanceAccount(struct BankAccount bankAccounts[], int *quantityAccounts) {
    if (*quantityAccounts == 0) {
        printf("No registered account!\n");
    }

    int lowestBalanceIndex = 0;
    for (int index = 0; index < *quantityAccounts; index++) {
        if (bankAccounts[index].balance < bankAccounts[lowestBalanceIndex].balance) {
            lowestBalanceIndex = index;
        }
    }

    for (int index = lowestBalanceIndex; index <= *quantityAccounts - 1; index++) {
        bankAccounts[index] = bankAccounts[index + 1];
    }

    (*quantityAccounts)--;
    printf("Account with lower balance deleted!\n");
}

void main() {
    struct BankAccount bankAccounts[15];
    int quantityAccounts = 0;
    int option;

    do {
        printf("\nOptions menu:\n");
        printf("1. Register accounts\n");
        printf("2. View all accounts for a given customer\n");
        printf("3. Delete the account with the lowest balance\n");
        printf("4. Exit\n");
        printf("Enter the desired option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerAccount(bankAccounts, &quantityAccounts);
                break;
            case 2:
                viewAllClientAccounts(bankAccounts, quantityAccounts);
                break;
            case 3:
                deleteLowestBalanceAccount(bankAccounts, &quantityAccounts);
                break;
            case 4:
                printf("Closing the program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 4);
}