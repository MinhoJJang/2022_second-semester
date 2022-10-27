#include <stdio.h>
#include <string.h>

int sum(int *arr)
{
    int idx = sizeof(arr) / sizeof(int);
    int sum = 0;
    for (int i = 0; i <= idx; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float avg(int *arr)
{
    int idx = sizeof(arr) / sizeof(int);
    float sum = 0;
    for (int i = 0; i <= idx; i++)
    {
        sum += arr[i];
    }
    return sum / (idx + 1);
}

void main()
{
    int i;
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("score.txt", "r");
    outputFile = fopen("outpuScore.txt", "w");

    if (inputFile == NULL)
        printf("\nFile Could Not Be Opened");
    else
    {
        for (int i = 0; i < 3; i++)
        {
            char name[20];
            int score[3];
            fscanf(inputFile, "%s %d %d %d", name, &score[0], &score[1], &score[2]);
            fprintf(outputFile, "%s %d %d %d %d %.2f \n", name, score[0], score[1], score[2], sum(score), avg(score));
        }
        fclose(inputFile);
        fclose(outputFile);
    }
}