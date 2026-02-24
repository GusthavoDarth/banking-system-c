#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char *argv[])
{
    int running = 1;
    struct Bank bank;
    bank.numAccounts = 0;
    loadBankFiles(&bank, "bank.dat");

    while(running != 0)
    {
        int choice;
        int accountNumber;
        system("cls");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Display one Account\n");
        printf("4. Deposit\n");
        printf("5. Withdraw\n");
        printf("6. Update Account\n");
        printf("7. Display Account transactions\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                char name[100];
                char email[100];
                char phoneNumber[20];
                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter email: ");
                scanf("%s", email);

                printf("Enter phone number: ");
                scanf("%s", phoneNumber);

                createAccount(&bank, name, email, phoneNumber);
                break;
            case 2:
                displayAllAccounts(&bank);
                system("pause");
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                if(accountNumber < 0 || accountNumber >= bank.numAccounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                displayAccount(&bank.accounts[accountNumber]);
                system("pause");
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                if(accountNumber < 0 || accountNumber >= bank.numAccounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                deposit(&bank, accountNumber);
                system("pause");
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                if(accountNumber < 0 || accountNumber >= bank.numAccounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                withdraw(&bank, accountNumber);
                system("pause");
                break;
            case 6:
                printf("Enter account number: ");
               scanf("%d", &accountNumber);
               if(accountNumber < 0 || accountNumber >= bank.numAccounts) {
                   printf("Invalid account number.\n");
                   break;
               }
               updateAccount(&bank, accountNumber);
               system("pause");
               break;
            case 7:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                if(accountNumber < 0 || accountNumber >= bank.numAccounts) {
                    printf("Invalid account number.\n");
                    break;
                }
                displayAccountStatement(&bank, accountNumber);
                system("pause");
                break;
            case 8:
                saveBankFiles(&bank, "bank.dat");
                running = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
