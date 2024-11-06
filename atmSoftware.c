#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

void validatePIN(int *pin, int *counter) {
    *counter = 0;
    while (*pin != 1111) {
        system("cls");
        (*counter)++;
        if (*counter == 3) {
            printf("Too many illegal PINs. Try later again.\n");
            exit(0);
        }
        printf("***Welcome to Cal Poly's ATM****\nPlease enter your PIN:");
        scanf("%d", pin);
    }
    system("cls");
}

void showMainMenu() {
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
}

void transferFromCheckingToSavings(double *checking, double *savings) {
    double transferAmount;
    printf("Enter the amount you want to transfer: \n");
    scanf("%lf", &transferAmount);
    if (transferAmount > *checking) {
        printf("Transaction not completed\n");
        printf("Current balance is: %.2lf\n", *checking);       
        sleep(3);
        system("cls");
    } else {
        *checking -= transferAmount;
        *savings += transferAmount;
        printf("Transaction completed\n");
        sleep(3);
        system("cls");
    }
}

void transferFromSavingsToChecking(double *checking, double *savings) {
    double transferAmount;
    printf("Enter the amount you want to transfer: \n");
    scanf("%lf", &transferAmount);
    if (transferAmount > *savings) {
        printf("Transaction not completed\n");
        printf("Current balance is: %.2lf\n", *savings);
        sleep(3);
        system("cls");
    } else {
        *savings -= transferAmount;
        *checking += transferAmount;
        printf("Transaction completed\n");
        sleep(3);
        system("cls");
    }
}

void showBalance(double balance, const char *accountType) {
    printf("Current balance in %s account is: %.2lf\n", accountType, balance);
    sleep(3);
    system("cls");
}

void withdrawCash(double *checking, double *savings) {
    char accountType[50];
    printf("Which account do you want to withdraw from? (Checking or Saving)\n");
    scanf("%s", accountType);
    
    for (int i = 0; accountType[i]; i++) {
        accountType[i] = tolower(accountType[i]);
    }

    if (strcmp(accountType, "checking") != 0 && strcmp(accountType, "saving") != 0) {
        printf("Invalid account type\n");
        sleep(3);
        system("cls");
        return;
    }

    double withdrawAmount;
    printf("Enter the amount you want to withdraw: \n");
    scanf("%lf", &withdrawAmount);

    if (strcmp(accountType, "checking") == 0) {
        if (withdrawAmount > *checking) {
            printf("Transaction not completed\n");
            printf("Current balance is: %.2lf\n", *checking);
            sleep(3);
            system("cls");
        } else {
            *checking -= withdrawAmount;
            printf("Transaction completed\n");
            sleep(3);
            system("cls");
        }
    } else if (strcmp(accountType, "saving") == 0) {
        if (withdrawAmount > *savings) {
            printf("Transaction not completed\n");
            printf("Current balance is: %.2lf\n", *savings);
            sleep(3);
            system("cls");
        } else {
            *savings -= withdrawAmount;
            printf("Transaction completed\n");
            sleep(3);
            system("cls");
        }
    }
}

int main() {
    int pin, counter = 0, selection = 0;
    double initialBalanceChecking = 1000.00;
    double initialBalanceSavings = 1000.00;

    system("cls");

    printf("***Welcome to Cal Poly's ATM****\nPlease enter your PIN:");
    scanf("%d", &pin);

    validatePIN(&pin, &counter);

    while (selection != 6) {
        showMainMenu();
        scanf("%d", &selection);

        if (selection < 1 || selection > 6) {
            system("cls");
            continue;
        }

        if (selection == 1) {
            transferFromCheckingToSavings(&initialBalanceChecking, &initialBalanceSavings);
        } else if (selection == 2) {
            transferFromSavingsToChecking(&initialBalanceChecking, &initialBalanceSavings);
        } else if (selection == 3) {
            showBalance(initialBalanceSavings, "savings");
        } else if (selection == 4) {
            showBalance(initialBalanceChecking, "checking");
        } else if (selection == 5) {
            withdrawCash(&initialBalanceChecking, &initialBalanceSavings);
        }
    }

    printf("Thank you for using the ATM system.\n");
    return 0;
}
