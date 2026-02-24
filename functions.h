#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"  // para ter acesso às definições das structs

// Protótipos das funções
struct AccountHolder createAccountHolder(char name[], char email[], char phoneNumber[]);
struct Account createAccount(struct Bank *bank, char name[], char email[], char phoneNumber[]);
void displayAccount(struct Account *account);
void displayAllAccounts(struct Bank *bank);
void displayAccountStatement(struct Bank *bank, int accountNumber);
struct Account updateAccount(struct Bank *bank, int accountNumber);
void deposit(struct Bank *bank, int accountNumber);
void withdraw(struct Bank *bank, int accountNumber);
int saveBankFiles(struct Bank *bank, const char *filename);
int loadBankFiles(struct Bank *bank, const char *filename);

#endif
