#include <stdio.h>

int main() {
    
    FILE *file;
    char filename[50];
    int vowelCounter = 0;
    int consonantCounter = 0;
    int punctuationCounter = 0;
    
    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    
    printf("Hello, World!\n");
    return 0;
}