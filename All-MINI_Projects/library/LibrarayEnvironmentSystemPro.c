#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_BOOKS 100

// Define structure for a customer
struct Customer {
    int id;
    char name[50];
    char email[50];
};

// Define structure for a book
struct Book {
    int id;
    char title[100];
    char author[50];
    char genre[50];
    int isAvailable; // 1 if available, 0 if borrowed
};

// Function prototypes
void addCustomer(struct Customer customers[], int *numCustomers);
void addBook(struct Book library[], int *numBooks);
void displayBooks(struct Book library[], int numBooks);
void returnBook(struct Book library[], int numBooks);
void ViewMembers(struct Customer customers[], int numCustomers);

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    struct Book library[MAX_BOOKS];
    int numCustomers = 0;
    int numBooks = 0;
    char choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Customer\n");
        printf("2. Add Book\n");
        printf("3. Display Books\n");
        printf("4. Return Book\n");
        printf("5. View Members\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addCustomer(customers, &numCustomers);
                break;
            case '2':
                addBook(library, &numBooks);
                break;
            case '3':
                displayBooks(library, numBooks);
                break;
            case '4':
                returnBook(library, numBooks);
                break;
            case '5':
                ViewMembers(customers, numCustomers);
                break;
            case '6':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '6');

    return 0;
}

void addCustomer(struct Customer customers[], int *numCustomers) {
    if (*numCustomers < MAX_CUSTOMERS) {
        printf("Enter customer ID: ");
        scanf("%d", &customers[*numCustomers].id);
        printf("Enter name: ");
        scanf("%s", customers[*numCustomers].name);
        printf("Enter email: ");
        scanf("%s", customers[*numCustomers].email);
        (*numCustomers)++;
        printf("Customer added successfully.\n");
    } else {
        printf("Customer database is full. Cannot add more customers.\n");
    }
}

void addBook(struct Book library[], int *numBooks) {
    if (*numBooks < MAX_BOOKS) {
        printf("Enter book ID: ");
        scanf("%d", &library[*numBooks].id);
        printf("Enter title: ");
        scanf("%s", library[*numBooks].title);
        printf("Enter author: ");
        scanf("%s", library[*numBooks].author);
        printf("Enter genre: ");
        scanf("%s", library[*numBooks].genre);
        library[*numBooks].isAvailable = 1; // Initially, book is available
        (*numBooks)++;
        printf("Book added successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void displayBooks(struct Book library[], int numBooks) {
    if (numBooks == 0) {
        printf("Library is empty.\n");
    } else {
        printf("Books in the library:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Genre: %s\n", library[i].genre);
            if (library[i].isAvailable == 1) {
                printf("Status: Available\n");
            } else {
                printf("Status: Borrowed\n");
            }
            printf("\n");
        }
    }
}

void ViewMembers(struct Customer customers[], int numCustomers) {
    if (numCustomers == 0) {
        printf("No customers in the library.\n");
    } else {
        printf("Members in the library:\n");
        for (int i = 0; i < numCustomers; i++) {
            printf("Customer ID: %d\n", customers[i].id);
            printf("Name: %s\n", customers[i].name);
            printf("Email: %s\n", customers[i].email);
            printf("\n");
        }
    }
}

void returnBook(struct Book library[], int numBooks) {
    int bookId;
    printf("Enter the ID of the book you are returning: ");
    scanf("%d", &bookId);

    for (int i = 0; i < numBooks; i++) {
        if (library[i].id == bookId) {
            if (library[i].isAvailable == 1) {
                printf("This book is already available.\n");
            } else {
                library[i].isAvailable = 1;
                printf("Thank you for returning the book.\n");
            }
            return;
        }
    }

    printf("Book with ID %d not found in the library.\n", bookId);
}



