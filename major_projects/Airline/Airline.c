// #include<stdio.h>       
// #include<stdlib.h>
// #include<conio.h>
// #include<string.h>
// #include<Windows.h>


// struct mufti_airline
// {
//     char passport[6];
//     char name[15];
//     char destination[15];
//     int seat_num;
//     char email[15];
//     struct mufti_airline *following;
// }
// *begin, *stream;
// struct mufti_airline *dummy;


// void main()
// {
//     void reserve(int x), cancel(), display(), savefile();  //function prototypes
//     int choice;
//     begin = stream = NULL;  //initialize the struct pointers to NULL
//     int num = 1;
//     do
//     {

//         printf("\n\n\t\t ********************************************************************");
//         printf("\n\t\t                   welcome to AL-HABIBI airline system                   ");
//         printf("\n\t\t   *******************************************************************");
//         printf("\n\n\n\t\t Please enter your choice from below (1-4):");
//         printf("\n\n\t\t 1. Reservation");
//         printf("\n\n\t\t 2. Cancel");
//         printf("\n\n\t\t 3. DISPLAY RECORDS");
//         printf("\n\n\t\t 4. EXIT");
//         printf("\n\n\t\t feel free to contact ");
//         printf("\n\n\t\t Enter your choice :");



//         scanf("%d", &choice); fflush(stdin);
//         system("cls");
//         switch (choice)
//         {
//         case 1:
//             reserve(num);
//             num++;
//             break;
//         case 2:
//             cancel();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//         {
//                   savefile();
//                   break;
//         }
//         default:
//             printf("\n\n\t SORRY INVALID CHOICE!");
//             printf("\n\n\t PLEASE CHOOSE FROM 1-4");
//             printf("\n\n\t Do not forget to chose from 1-4");
//         }
//         getch();
//     } while (choice != 4);
// }
// // ************************GOOD LUCK MUFTI*****************************
// void details()
// {
//     printf("\n\t Enter your passport number:");
//     gets(stream->passport); fflush(stdin);   //reads a line from stdin and stores it into the string pointed
//     printf("\n\t Enter your  name:");
//     gets(stream->name); fflush(stdin);
//     printf("\n\t Enter your email address:");
//     gets(stream->email); fflush(stdin);
//     printf("\n\t Enter the Destination : ");
//     gets(stream->destination); fflush(stdin);
// }


// // ************************************GOOD LUCK MUFTI************************************
// void details();

// void reserve(int x)
// {
//     stream = begin;
//     if (begin == NULL)
//     {
//         // first user
//         begin = stream = (struct mufti_airline*)malloc(sizeof(struct mufti_airline));
//         details();
//         stream->following = NULL;
//         printf("\n\t Seat booking successful!");
//         printf("\n\t your seat number is: Seat A-%d", x);
//         stream->seat_num = x;
//         return;
//     }
//     else if (x > 15) // FULL SEATS
//     {
//         printf("\n\t\t Seat Full.");
//         return;
//     }
//     else
//     {
//         // next user
//         while (stream->following)
//             stream = stream->following;
//         stream->following = (struct mufti_airline *)malloc(sizeof(struct mufti_airline));
//         stream = stream->following;
//         details();
//         stream->following = NULL;
//         printf("\n\t Seat booking succesful!");
//         printf("\n\t your seat number is: Seat A-%d", x);
//         stream->seat_num = x;
//         return;
//     }
// }
// // ************************GOOD LUCK MUFTI********************************


// void savefile()
// {
//     FILE *fpointer = fopen("mufti records", "w");
//     if (!fpointer)
//     {
//         printf("\n Error in opening file!");
//         return;
//         Sleep(800);
//     }
//     stream = begin;
//     while (stream)
//     {
//         fprintf(fpointer, "%-6s", stream->passport);
//         fprintf(fpointer, "%-15s", stream->name);
//         fprintf(fpointer, "%-15s", stream->email);
//         fprintf(fpointer, "%-15s", stream->destination);
//         fprintf(fpointer, "\n");
//         stream = stream->following;
//     }
//     printf("\n\n\t Details have been saved to a file (mufti records)");
//     fclose(fpointer);
// }
// //********************************GOOD LUCK MUFTI***************************************

// void display()
// {
//     stream = begin;
//     while (stream)
//     {
//         printf("\n\n Passport Number : %-6s", stream->passport);
//         printf("\n         name : %-15s", stream->name);
//         printf("\n      email address: %-15s", stream->email);
//         printf("\n      Seat number: A-%d", stream->seat_num);
//         printf("\n     Destination:%-15s", stream->destination);
//         printf("\n\n++*=====================================================*++");
//         stream = stream->following;
//     }

// }
// //*****************************GOOD LUCK MUFTI*************************************

// void cancel()
// {
//     stream = begin;
//     system("cls");
//     char passport[6];
//     printf("\n\n Enter passort number to delete record?:");
//     gets(passport); fflush(stdin);
//     if (strcmp(begin->passport, passport) == 0)
//     {
//         dummy = begin;
//         begin = begin->following;
//         free(dummy);
//         printf(" booking has been deleted");
//         Sleep(800);
//         return;

//     }

//     while (stream->following)
//     {
//         if (strcmp(stream->following->passport, passport) == 0)
//         {
//             dummy = stream->following;
//             stream->following = stream->following->following;
//             free(dummy);
//             printf("has been deleted ");
//             getch();
//             Sleep(800);
//             return;
//         }
//         stream = stream->following;
//     }
//     printf("passport number is wrong please check your passport");

// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Structure to store passenger details
struct Passenger {
    char passport[6];
    char name[15];
    char email[15];
    char destination[15];
    int seat_num;
    struct Passenger *next;
};

// Global variable to keep track of the head of the linked list
struct Passenger *head = NULL;

// Function prototypes
void reserve(int);
void cancel();
void display();
void savefile();
void details();

int main() {
    int choice;
    int num = 1;
    do {
        system("cls");
        printf("\n\n\t\t ********************************************************************");
        printf("\n\t\t                   Welcome to Ahmed's Airline Reservation System                   ");
        printf("\n\t\t   *******************************************************************");
        printf("\n\n\n\t\t Please enter your choice from below (1-4):");
        printf("\n\n\t\t 1. Reservation");
        printf("\n\n\t\t 2. Cancel");
        printf("\n\n\t\t 3. Display Records");
        printf("\n\n\t\t 4. Exit");
        printf("\n\n\t\t Enter your choice: ");

        scanf("%d", &choice); fflush(stdin);
        switch (choice) {
            case 1:
                reserve(num);
                num++;
                break;
            case 2:
                cancel();
                break;
            case 3:
                display();
                break;
            case 4:
                savefile();
                printf("\n\n\t\t Goodbye!");
                break;
            default:
                printf("\n\n\t\t SORRY INVALID CHOICE!");
                printf("\n\n\t\t PLEASE CHOOSE FROM 1-4");
                printf("\n\n\t\t Do not forget to chose from 1-4");
        }
        getch();
    } while (choice != 4);

    return 0;
}

// Function to prompt user for passenger details
void details() {
    struct Passenger *temp = (struct Passenger *)malloc(sizeof(struct Passenger));
    printf("\n\t Enter your passport number: ");
    gets(temp->passport); fflush(stdin);
    printf("\n\t Enter your name: ");
    gets(temp->name); fflush(stdin);
    printf("\n\t Enter your email address: ");
    gets(temp->email); fflush(stdin);
    printf("\n\t Enter the destination: ");
    gets(temp->destination); fflush(stdin);
    temp->next = NULL;

    // If head is NULL, set head to temp
    if (head == NULL) {
        head = temp;
    } else {
        // Find the last node and link temp to it
        struct Passenger *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

// Function to reserve a seat
void reserve(int x) {
    if (x > 15) {
        printf("\n\t Seat Full.");
        return;
    }

    if (head == NULL) {
        printf("\n\t Seat booking successful!");
        printf("\n\t Your seat number is: Seat A-%d", x);
        details();
    } else {
        struct Passenger *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        printf("\n\t Seat booking successful!");
        printf("\n\t Your seat number is: Seat A-%d", x);
        details();
    }
}

// Function to cancel a reservation
void cancel() {
    if (head == NULL) {
        printf("\n\t No bookings to cancel.");
        return;
    }

    char passport[6];
    printf("\n\n Enter passport number to delete record: ");
    gets(passport); fflush(stdin);

    if (strcmp(head->passport, passport) == 0) {
        struct Passenger *temp = head;
        head = head->next;
        free(temp);
        printf("\n\t Booking has been deleted.");
        return;
    }

    struct Passenger *temp = head;
    while (temp->next != NULL) {
        if (strcmp(temp->next->passport, passport) == 0) {
            struct Passenger *dummy = temp->next;
            temp->next = temp->next->next;
            free(dummy);
            printf("\n\t Booking has been deleted.");
            return;
        }
        temp = temp->next;
    }

    printf("\n\t Passport number is incorrect.");
}

// Function to display all passenger records
void display() {
    if (head == NULL) {
        printf("\n\t No bookings to display.");
        return;
    }

    struct Passenger *temp = head;
    printf("\n\n Passenger Records:\n");
    while (temp != NULL) {
        printf("\n\n Passport Number: %-6s", temp->passport);
        printf("\n Name: %-15s", temp->name);
        printf("\n Email Address: %-15s", temp->email);
        printf("\n Destination: %-15s", temp->destination);
        printf("\n Seat Number: A-%d", temp->seat_num);
        temp = temp->next;
    }
}

// Function to save passenger records to a file
void savefile() {
    if (head == NULL) {
        printf("\n\t No bookings to save.");
        return;
    }

    FILE *file = fopen("airline_records.txt", "w");
    if (file == NULL) {
        printf("\n\t Error in opening file!");
        return;
    }

    struct Passenger *temp = head;
    while (temp != NULL) {
        fprintf(file, "%-6s %-15s %-15s %-15s\n", temp->passport, temp->name, temp->email, temp->destination);
        temp = temp->next;
    }

    fclose(file);
    printf("\n\n\t Records have been saved to a file (airline_records.txt)");
}
