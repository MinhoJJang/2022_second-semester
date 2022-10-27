
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *strInFileName, *strOutFileName;
    FILE *inFile, *outFile;
    strInFileName = "./inputfile.txt";
    strOutFileName = "./outputfile.txt";
    if ((inFile = fopen(strInFileName, "r")) == NULL)
    {
        printf("File Could Not be Opened\n");
        exit(1);
    }
    if ((outFile = fopen(strOutFileName, "w")) == NULL)
    {
        printf("File Could Not be Opened\n");
        exit(1);
    }
    return 0;
}