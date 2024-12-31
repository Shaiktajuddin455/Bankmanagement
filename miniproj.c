#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100  // Maximum number of accounts

// Define the structure to hold account details
typedef struct {
    int accountNumber;
    char accountHolder[100];
    double balance;
} Account;

// Global array of accounts and current number of accounts
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;  // To track the number of created accounts

// Function to create an account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    printf("\nEnter account number: ");
    scanf("%d", &newAccount.accountNumber);
    getchar(); // Consume newline character

    printf("Enter account holder's name: ");
    fgets(newAccount.accountHolder, sizeof(newAccount.accountHolder), stdin);
    newAccount.accountHolder[strcspn(newAccount.accountHolder, "\n")] = '\0'; // Remove the newline character

    newAccount.balance = 0.0;  // Initialize balance to 0.0
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit() {
    int accountNumber;
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    // Search for the account and deposit money
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited %.2lf into account %d. New balance: %.2lf\n", amount, accountNumber, accounts[i].balance);
            } else {
                printf("Invalid deposit amount. Amount should be greater than zero.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw() {
    int accountNumber;
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    // Search for the account and withdraw money
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrew %.2lf from account %d. New balance: %.2lf\n", amount, accountNumber, accounts[i].balance);
            } else if (amount > accounts[i].balance) {
                printf("Insufficient funds. Current balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Invalid withdrawal amount. Amount should be greater than zero.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to check the balance of an account
void checkBalance() {
    int accountNumber;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    // Search for the account and print balance
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("\nAccount Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Current Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to display the list of all accounts
void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts found.\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        printf("\nAccount Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].accountHolder);
        printf("Balance: %.2lf\n", accounts[i].balance);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n*** Bank Account Management System ***\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Display All Accounts\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}

