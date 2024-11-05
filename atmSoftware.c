# include <stdio.h>

int main() {
    int pin;
    
    printf("***Welcome to Cal Poly's ATM****\nPlease enter your PIN:");
    scanf("%d", &pin);
    
    if (pin == 1111) {
        printf("Welcome to your account!\n");
    } else {
        printf("Invalid PIN. Please try again.\n");
    }

    return 0;
}