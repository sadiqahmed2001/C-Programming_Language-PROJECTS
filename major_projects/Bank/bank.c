#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Bank Account
struct BankAccount {
    int accountNumber;
    char name[100];
    float balance;
};

// Function to create a new account
void createAccount(struct BankAccount *accounts, int *numAccounts) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    printf("Enter name: ");
    scanf("%s", accounts[*numAccounts].name);
    accounts[*numAccounts].balance = 0.0;
    (*numAccounts)++;
    printf("Account created successfully.\n");
}

// Function to deposit money
void deposit(struct BankAccount *accounts, int numAccounts) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money
void withdraw(struct BankAccount *accounts, int numAccounts) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. Current balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to check balance
void checkBalance(struct BankAccount *accounts, int numAccounts) {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct BankAccount accounts[100];
    int numAccounts = 0;
    int choice;

    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
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