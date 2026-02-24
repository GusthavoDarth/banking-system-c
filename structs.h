#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

struct AccountHolder{
    char name[50];
    char email[100];
    char phoneNumber[20];
};

struct Account{
    struct AccountHolder accountHolder;
    int accountNumber;
    double accountBalance;
};

struct Transaction{
    int transactionId;
    struct Account account;
    double amount;
    char type;
};

struct Bank{
    struct Account accounts[MAX_ACCOUNTS];
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions;
    int numAccounts;
};

#endif
