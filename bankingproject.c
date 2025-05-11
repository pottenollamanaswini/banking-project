#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct BankAccount {
    int accNumber;
    char name[50];
    float balance;
};

struct BankAccount accounts[MAX];
int count = 0;

void createAccount() {
    if (count >= MAX) {
        printf("Account limit reached!\n");
        return;
    }
    printf("\nCreating New Account\n");
    printf("Enter account number: ");
    scanf("%d", &accounts[count].accNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]", accounts[count].name);
    printf("Enter initial deposit: ");
    scanf("%f", &accounts[count].balance);
    count++;
    printf("Account created successfully!\n");
}

void displayAccounts() {
    if (count == 0) {
        printf("No accounts to display.\n");
        return;
    }
    printf("\n--- Account List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Account No: %d | Name: %s | Balance: %.2f\n",
            accounts[i].accNumber,
            accounts[i].name,
            accounts[i].balance);
    }
}

int findAccount(int accNo) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accNumber == accNo)
            return i;
    }
    return -1;
}

void depositMoney() {
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int index = findAccount(accNo);
    if (index != -1) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        accounts[index].balance += amount;
        printf("Amount deposited successfully. New balance: %.2f\n", accounts[index].balance);
    } else {
        printf("Account not found.\n");
    }
}

void withdrawMoney() {
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int index = findAccount(accNo);
    if (index != -1) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (accounts[index].balance >= amount) {
            accounts[index].balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", accounts[index].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n2. Display Accounts\n3. Deposit Money\n4. Withdraw Money\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}