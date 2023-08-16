#include <stdio.h>
#include <string.h>

// Structure to store product information
struct Product {
    int code;
    char description[50];
    float purchasePrice;
    float sellingPrice;
    int quantityInStock;
    int minimumStock;
};

// Function to add a new product to the inventory
void addProduct(struct Product inventory[], int *numberOfProducts) {
    if (*numberOfProducts >= 40) {
        printf("Inventory is full!\n");
    }

    printf("Enter product code: ");
    scanf("%d", &inventory[*numberOfProducts].code);

    printf("Enter product description: ");
    scanf(" %[^\n]", inventory[*numberOfProducts].description);

    printf("Enter purchase price: ");
    scanf("%f", &inventory[*numberOfProducts].purchasePrice);

    printf("Enter selling price: ");
    scanf("%f", &inventory[*numberOfProducts].sellingPrice);

    printf("Enter quantity in stock: ");
    scanf("%d", &inventory[*numberOfProducts].quantityInStock);

    printf("Enter minimum stock: ");
    scanf("%d", &inventory[*numberOfProducts].minimumStock);

    (*numberOfProducts)++;
    printf("Product added successfully!\n");
}

// Function to calculate and display profit from selling a product
void calculateProfit(struct Product inventory[], int numberOfProducts) {
    int productCode;
    printf("Enter product code: ");
    scanf("%d", &productCode);

    for (int index = 0; index < numberOfProducts; index++) {
        if (inventory[index].code == productCode) {
            float profit = (inventory[index].sellingPrice - inventory[index].purchasePrice) * inventory[index].quantityInStock;
            float profitPercentage = (profit / (inventory[index].purchasePrice * inventory[index].quantityInStock)) * 100;

            printf("Profit from selling product %s: %.2f\n", inventory[index].description, profit);
            printf("Profit percentage: %.2f%%\n", profitPercentage);
        }

        if (inventory[index].code != productCode) {
            printf("Product not found!\n");
        }
    }
}

// Function to display products below minimum stock
void displayLowStockProducts(struct Product inventory[], int numberOfProducts) {
    printf("Products with quantity below minimum stock:\n");

    for (int index = 0; index < numberOfProducts; index++) {
        if (inventory[index].quantityInStock < inventory[index].minimumStock) {
            printf("Product: %s | Quantity in stock: %d | Minimum stock: %d\n", inventory[index].description, inventory[index].quantityInStock, inventory[index].minimumStock);
        }
    }
}

void main() {
    struct Product inventory[40];
    int numberOfProducts = 0;
    int option;

    do {
        printf("\nOptions menu:\n");
        printf("1. Add product\n");
        printf("2. Calculate profit\n");
        printf("3. Display products below minimum stock\n");
        printf("4. Exit\n");
        printf("Enter the desired option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(inventory, &numberOfProducts);
                break;
            case 2:
                calculateProfit(inventory, numberOfProducts);
                break;
            case 3:
                displayLowStockProducts(inventory, numberOfProducts);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 4);
}