#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    FILE *myFile, *outFile;

    myFile = fopen("mf.txt", "r");
    outFile = fopen("of.txt", "w");

    if (myFile == NULL)
    {
        printf("\nFile Could Not Be Opened");
    }
    else
    {
        do
        {
            ch = fgetc(myFile);
            putchar(ch);
            fputc(ch, outFile);
        } while (ch != EOF);
    }
    return 0;
}