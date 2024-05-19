#include <stdio.h>
#include <stdlib.h> // Required for malloc and realloc

#define MAX_ADDRESS_LENGTH 1000

// Define a struct to hold an address
struct Address {
    char street[MAX_ADDRESS_LENGTH];
    char city[MAX_ADDRESS_LENGTH];
    char state[MAX_ADDRESS_LENGTH];
    int zip;
};

int main() {
    int n = 0; // Counter for the number of addresses
    int capacity = 1; // Initial capacity for the dynamic array
    struct Address *addresses = malloc(capacity * sizeof(struct Address));

    if (addresses == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input loop to get addresses from the user
    while (1) {
        printf("\nEnter address of person %d:\n", n + 1);
        printf("Street: ");
        scanf(" %[^\n]", addresses[n].street); // Note the space before %[^\n]
        printf("City: ");
        scanf(" %[^\n]", addresses[n].city); // Note the space before %[^\n]
        printf("State: ");
        scanf(" %[^\n]", addresses[n].state); // Note the space before %[^\n]
        printf("Zip: ");
        scanf("%d", &addresses[n].zip);

        n++; // Increment the counter for the number of addresses

        // Check if we need to reallocate memory for more addresses
        if (n >= capacity) {
            capacity *= 2; // Double the capacity
            struct Address *temp = realloc(addresses, capacity * sizeof(struct Address));
            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(addresses); // Free memory before exiting
                return 1;
            }
            addresses = temp; // Update the pointer to the newly allocated memory
        }

        // Ask the user if they want to input another address
        char choice;
        printf("\nDo you want to enter another address? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop if the user does not want to enter another address
        }
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

    // Free dynamically allocated memory
    free(addresses);

    return 0;
}