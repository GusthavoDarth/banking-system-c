#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

struct AccountHolder createAccountHolder(char name[], char email[], char phoneNumber[])
{
    struct AccountHolder newAccountHolder;
    strcpy_s(newAccountHolder.name, sizeof(newAccountHolder.name), name);
    strcpy_s(newAccountHolder.email, sizeof(newAccountHolder.email), email);
    strcpy_s(newAccountHolder.phoneNumber, sizeof(newAccountHolder.phoneNumber), phoneNumber);

    return newAccountHolder;
}

struct Account createAccount(struct Bank *bank, char name[], char email[], char phoneNumber[])
{
    struct Account newAccount;
    newAccount.accountHolder = createAccountHolder(name, email, phoneNumber);
    newAccount.accountBalance = 0.0;
    newAccount.accountNumber = bank->numAccounts++;
    if(bank->numAccounts >= MAX_ACCOUNTS)
    {
        printf("Error: Maximum number of accounts limits %d reached.\n", MAX_ACCOUNTS);
        bank->numAccounts--;
        return newAccount;
    }

    bank->accounts[newAccount.accountNumber] = newAccount;
    return newAccount;
}

void displayAccount(struct Account *account)
{
    printf("Account Number : %d\n", account->accountNumber);
    printf("Account Holder : %s\n", account->accountHolder.name);
    printf("Account Balance : %.2f\n", account->accountBalance);
    printf("Account email : %s\n", account->accountHolder.email);
    printf("Account tel : %s\n", account->accountHolder.phoneNumber);
    printf("\n");
};

void displayAllAccounts(struct Bank *bank)
{
    for (int i = 0; i < bank->numAccounts; i++)
    {
        displayAccount(&bank->accounts[i]);
    }
};

void displayAccountStatement(struct Bank *bank, int accountNumber)
{
    int found = 0;
    for (int i = 0; i < bank->numTransactions; i++) {
        if (bank->transactions[i].account.accountNumber == accountNumber)
        {
            printf("Transaction ID : %d\n", bank->transactions[i].transactionId);
            printf("Account Number : %d\n", bank->transactions[i].account.accountNumber);
            printf("Account Holder : %s\n", bank->transactions[i].account.accountHolder.name);
            printf("Transaction Type : %c\n", bank->transactions[i].type);
            printf("Transaction Amount : %.2f\n", bank->transactions[i].amount);
            printf("\n");
            found = 1;
        }
    }
    if (!found) printf("No transactions found for this account.\n");
}


struct Account updateAccount(struct Bank *bank, int accountNumber)
{
    struct Account updateAccount = bank->accounts[accountNumber];
    printf("Enter new name: ");
    scanf("%s", updateAccount.accountHolder.name);
    printf("Enter new email: ");
    scanf("%s", updateAccount.accountHolder.email);
    printf("Enter new phone number: ");
    scanf("%s", updateAccount.accountHolder.phoneNumber);
    bank->accounts[accountNumber] = updateAccount;
    return updateAccount;
};



void deposit(struct Bank *bank, int accountNumber)
{
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }
    if (bank->numTransactions >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot record more transactions.\n");
        return;
    }
    bank->accounts[accountNumber].accountBalance += amount;
    bank->transactions[bank->numTransactions].transactionId = bank->numTransactions + 1;
    bank->transactions[bank->numTransactions].account = bank->accounts[accountNumber];
    bank->transactions[bank->numTransactions].amount = amount;
    bank->transactions[bank->numTransactions].type = 'D';
    bank->numTransactions++;
};

void withdraw(struct Bank *bank, int accountNumber)
{
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }
    if (bank->numTransactions >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot record more transactions.\n");
        return;
    }
    if (amount > bank->accounts[accountNumber].accountBalance)
    {
        printf("insufficient funds\n");
    }
    else
    {
        bank->accounts[accountNumber].accountBalance -= amount;
        bank->transactions[bank->numTransactions].transactionId = bank->numTransactions + 1;
        bank->transactions[bank->numTransactions].account = bank->accounts[accountNumber];
        bank->transactions[bank->numTransactions].amount = amount;
        bank->transactions[bank->numTransactions].type = 'W';
        bank->numTransactions++;
    }
};

int saveBankFiles(struct Bank *bank, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Error opening file for writing\n");
        return -1;
    }
    fwrite(&bank->numAccounts, sizeof(int),1,file);
    fwrite(&bank->numTransactions, sizeof(int),1,file);
    fwrite(bank->accounts, sizeof(struct Account),bank->numAccounts,file);
    fwrite(bank->transactions, sizeof(struct Transaction),bank->numTransactions,file);
    fclose(file);
    printf("Data saved successfully\n");
    return 0;
}

int loadBankFiles(struct Bank *bank, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        return 0;
    }

    fread(&bank->numAccounts, sizeof(int),1,file);
    fread(&bank->numTransactions, sizeof(int),1,file);
    fread(bank->accounts, sizeof(struct Account),bank->numAccounts,file);
    fread(bank->transactions, sizeof(struct Transaction),bank->numTransactions,file);
    fclose(file);
    printf("Data loaded successfully\n");
    return 0;
}
