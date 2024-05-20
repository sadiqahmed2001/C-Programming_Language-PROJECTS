#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define structure for a contact
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    char product[100];
};

// Function prototypes
void addContact(struct Contact contacts[], int *numContacts);
void displayContacts(struct Contact contacts[], int numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    char choice;

    do {
        printf("\nCustomer Details\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addContact(contacts, &numContacts);
                break;
            case '2':
                displayContacts(contacts, numContacts);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '3');

    return 0;
}

void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", contacts[*numContacts].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[*numContacts].phone);
        printf("Enter email: ");
        scanf("%s", contacts[*numContacts].email);
        printf("Enter product: ");
        scanf("%s", contacts[*numContacts].product);
        (*numContacts)++;
        printf("Contact added successfully.\n");
    } else {
        printf("Address book is full. Cannot add more contacts.\n");
    }
}

void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Address book is empty.\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < numContacts; i++) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("Product: %s\n", contacts[i].product);
            printf("\n");
        }
    }
}