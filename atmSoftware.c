#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int pin;
    int counter = 0;
    int selection;
    double initialBalanceChecking = 1000.00;
    double initialBalanceSavings = 1000.00;

    clear_screen();

    printf("***Welcome to Cal Poly's ATM****\nPlease enter your PIN:");
    scanf("%d", &pin);

    while (pin != 1111) {
        clear_screen();  // Use clear_screen function
        counter++;
        if (counter == 3) {
            printf("Too many illegal PINs. Try later again.\n");
            return 0;
        }
        printf("***Welcome to Cal Poly's ATM****\nPlease enter your PIN:");
        scanf("%d", &pin);
    }
    clear_screen();

    counter = 0;

    while (selection != 6) {
        printf(
            "***Welcome to Cal Poly's ATM****\n"
            "(1) Transfer from checking account to savings account\n"
            "(2) Transfer from savings account to checking account\n"
            "(3) Savings account balance\n"
            "(4) Checking account balance\n"
            "(5) Withdraw Cash from either account\n"
            "(6) Exit\n"
            "==> Please select option (1-6):\n"
        );
        scanf("%d", &selection);

        // verify selection is between 1 and 6
        if (selection < 1 || selection > 6) {
            clear_screen();
            continue;
        }
        // selection 1 --> transfer from checking account to savings account
        else if (selection == 1) {
            double transferAmount;
            printf("Enter the amount you want to transfer: \n");
            scanf("%lf", &transferAmount);
            if (transferAmount > initialBalanceChecking) {
                printf("Transaction not completed\n");
                printf("Current balance is: %.2lf\n", initialBalanceChecking);
                clear_screen();
            } else {
                initialBalanceChecking -= transferAmount;
                initialBalanceSavings += transferAmount;
                printf("Transaction completed\n");
                clear_screen();
            }
        // selection 2 --> transfer from savings account to checking account
        } else if (selection == 2) {
            double transferAmount;
            printf("Enter the amount you want to transfer: \n");
            scanf("%lf", &transferAmount);
            if (transferAmount > initialBalanceSavings) {
                printf("Transaction not completed\n");
                printf("Current balance is: %.2lf\n", initialBalanceSavings);
                clear_screen();
            } else {
                initialBalanceSavings -= transferAmount;
                initialBalanceChecking += transferAmount;
                printf("Transaction completed\n");
                clear_screen();
            }
        }
        // selection 3 --> display savings account balance
        else if (selection == 3) {
            printf("Current balance is: %.2lf\n", initialBalanceSavings);
            clear_screen();
        }
        // selection 4 --> display checking account balance
        else if (selection == 4) {
            printf("Current balance is: %.2lf\n", initialBalanceChecking);
            clear_screen();
        }
        // selection 5 --> withdraw cash from either account
        else if (selection == 5) {
            char accountType[10];
            printf("Which account do you want to withdraw from? (Checking or Saving)\n");
            scanf("%s", accountType);
            accountType[0] = tolower(accountType[0]);

            if (strcmp(accountType, "checking") != 0 && strcmp(accountType, "saving") != 0) {
                printf("Invalid account type\n");
                clear_screen();
                continue;
            }

            double withdrawAmount;
            printf("Enter the amount you want to withdraw: \n");
            scanf("%lf", &withdrawAmount);

            if (strcmp(accountType, "checking") == 0) {
                if (withdrawAmount > initialBalanceChecking) {
                    printf("Transaction not completed\n");
                    printf("Current balance is: %.2lf\n", initialBalanceChecking);
                    clear_screen();
                } else {
                    initialBalanceChecking -= withdrawAmount;
                    printf("Transaction completed\n");
                    clear_screen();
                }
            } else if (strcmp(accountType, "saving") == 0) {
                if (withdrawAmount > initialBalanceSavings) {
                    printf("Transaction not completed\n");
                    printf("Current balance is: %.2lf\n", initialBalanceSavings);
                    clear_screen();
                } else {
                    initialBalanceSavings -= withdrawAmount;
                    printf("Transaction completed\n");
                    clear_screen();
                }
            }
        }
    }

    printf("Thank you for using the ATM system.\n");
    return 0;
}