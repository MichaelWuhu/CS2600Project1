#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    FILE *outputFile;
    char filename[50];
    int aCounter = 0;
    int eCounter = 0;
    int iCounter = 0;
    int oCounter = 0;
    int uCounter = 0;
    int consonantCounter = 0;
    int punctuationCounter = 0;
    int totalCharacterCounter = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file\n");
        fclose(fp);
        return 1;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ' || ch == '\n')
            continue;  // Ignore spaces and newlines

        if (isalpha(ch))
        {
            ch = tolower(ch);
            switch (ch)
            {
            case 'a':
                aCounter++;
                break;
            case 'e':
                eCounter++;
                break;
            case 'i':
                iCounter++;
                break;
            case 'o':
                oCounter++;
                break;
            case 'u':
                uCounter++;
                break;
            default:
                consonantCounter++;
                break;
            }
        }
        else if (ispunct(ch))
        {
            punctuationCounter++;
        }
        totalCharacterCounter++;
    }

    // Calculate percentages
    int aPercentage = (int)(((float)aCounter / totalCharacterCounter) * 100 + 0.5);
    int ePercentage = (int)(((float)eCounter / totalCharacterCounter) * 100 + 0.5);
    int iPercentage = (int)(((float)iCounter / totalCharacterCounter) * 100 + 0.5);
    int oPercentage = (int)(((float)oCounter / totalCharacterCounter) * 100 + 0.5);
    int uPercentage = (int)(((float)uCounter / totalCharacterCounter) * 100 + 0.5);
    int consonantPercentage = (int)(((float)consonantCounter / totalCharacterCounter) * 100 + 0.5);
    int punctuationPercentage = (int)(((float)punctuationCounter / totalCharacterCounter) * 100 + 0.5);

    // print results
    printf("a %d%% ; e %d%% ; i %d%% ; o %d%% ; u %d%% ; consonants %d%% ; punct %d%%\n",
           aPercentage, ePercentage, iPercentage, oPercentage, uPercentage, consonantPercentage, punctuationPercentage);

    // print to output.txt
    fprintf(outputFile, "Percentages of various characters:\n");
    fprintf(outputFile, "a %d%% ; e %d%% ; i %d%% ; o %d%% ; u %d%% ; consonants %d%% ; punct %d%%\n",
            aPercentage, ePercentage, iPercentage, oPercentage, uPercentage, consonantPercentage, punctuationPercentage);

    fclose(fp);
    fclose(outputFile);

    return 0;
}
