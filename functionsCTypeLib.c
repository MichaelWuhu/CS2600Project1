#include <stdio.h>

int main() {
    
    FILE *fp;
    char filename[50];
    int aCounnter = 0;
    int eCounter = 0;
    int iCounter = 0;
    int oCounter = 0;
    int uCounter = 0;
    int consonantCounter = 0;
    int punctuationCounter = 0;
    int totalCharacterCounter;
    
    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    
    

    return 0;
}