#include <stdio.h>

// Function to display the menu and return the price of selected tea
float displayMenu() {
    printf("\nMenu:\n");
    printf("1. Black Tea - $3.00\n");
    printf("2. Green Tea - $4.00\n");
    printf("3. Masala Chai - $3.50\n");
    printf("4. Quit\n");

    int choice;
    float price = 0;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            price = 3.00;
            break;
        case 2:
            price = 4.00;
            break;
        case 3:
            price = 3.50;
            break;
        case 4:
            printf("Thank you for visiting!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return price;
}

int main() {
    int quantity;
    float total = 0;

    printf("\nWelcome to the APNA--Tea Store!\n");

    while (1) {
        float price = displayMenu();

        if (price == 0)
            break;

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total += price * quantity;

        printf("Item added to cart!\n");
    }

    printf("\n*******************************\n");
    printf("Total bill: $%.2f\n", total);
    printf("*******************************\n");
    printf("\n THANKYOU--->VISIT AGAIN  :)----!!");

    return 0;
}