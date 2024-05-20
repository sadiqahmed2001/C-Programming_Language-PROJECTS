#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Book
struct Book {
    char title[100];
    char author[100];
    int pages;
};

// Function to add a new book
void addBook(struct Book *books, int *numBooks) {
    printf("Enter book title: ");
    scanf(" %[^\n]", books[*numBooks].title);
    printf("Enter author: ");
    scanf(" %[^\n]", books[*numBooks].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[*numBooks].pages);
    (*numBooks)++;
    printf("Book added successfully.\n");
}

// Function to display all books
void displayBooks(struct Book *books, int numBooks) {
    printf("\nLibrary Books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("\n");
    }
}

// Function to search for a book by title
void searchBook(struct Book *books, int numBooks, char *searchTitle) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to delete a book by title
void deleteBook(struct Book *books, int *numBooks, char *deleteTitle) {
    int found = 0;
    for (int i = 0; i < *numBooks; i++) {
        if (strcmp(books[i].title, deleteTitle) == 0) {
            // Shift elements to the left to overwrite the deleted book
            for (int j = i; j < *numBooks - 1; j++) {
                strcpy(books[j].title, books[j + 1].title);
                strcpy(books[j].author, books[j + 1].author);
                books[j].pages = books[j + 1].pages;
            }
            (*numBooks)--;
            found = 1;
            printf("Book deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Book books[100];
    int numBooks = 0;
    int choice;
    char searchTitle[100];
    char deleteTitle[100];

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2:
                displayBooks(books, numBooks);
                break;
            case 3:
                printf("Enter title to search: ");
                scanf(" %[^\n]", searchTitle);
                searchBook(books, numBooks, searchTitle);
                break;
            case 4:
                printf("Enter title to delete: ");
                scanf(" %[^\n]", deleteTitle);
                deleteBook(books, &numBooks, deleteTitle);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}