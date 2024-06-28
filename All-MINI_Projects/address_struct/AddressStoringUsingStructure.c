#include <stdio.h>

#define MAX_ADDRESS_LENGTH 100
#define MAX_USERS 1000

// Define a struct to hold an address
struct Address {
    char street[MAX_ADDRESS_LENGTH];
    char city[MAX_ADDRESS_LENGTH];
    char state[MAX_ADDRESS_LENGTH];
    int zip;
};

int main() {
    int n;

    // Prompt user to enter the number of addresses
    printf("Enter the number of persons addresses: ");
    scanf("%d", &n);

    // Ensure the number of addresses is within bounds
    if (n <= 0 || n > MAX_USERS) {
        printf("Invalid number of addresses. Please enter a number between 1 and %d.\n", MAX_USERS);
        return 1;
    }

    // Array of structs to hold the addresses
    struct Address addresses[MAX_USERS];

    // Input loop to get addresses from the user
    for (int i = 0; i < n; i++) {
        printf("\nEnter address of person %d:\n", i + 1);
        printf("Street: ");
        scanf(" %[^\n]", addresses[i].street); // Note the space before %[^\n]
        printf("City: ");
        scanf(" %[^\n]", addresses[i].city); // Note the space before %[^\n]
        printf("State: ");
        scanf(" %[^\n]", addresses[i].state); // Note the space before %[^\n]
        printf("Zip: ");
        scanf("%d", &addresses[i].zip);
    }

    // Display the addresses entered by the user
    printf("\nAddresses entered by the user:\n");
    for (int i = 0; i < n; i++) {
        printf("Address %d:\n", i + 1);
        printf("Street: %s\n", addresses[i].street);
        printf("City: %s\n", addresses[i].city);      
        printf("State: %s\n", addresses[i].state);
        printf("Zip: %d\n", addresses[i].zip);
        printf("\n");
    }

    return 0;
}
