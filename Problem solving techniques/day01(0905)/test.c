#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void setRandomArray(int arr[])
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (rand() % MAX) * MAX + rand() % MAX;
    }
}

void printArray(int arr[], char *type)
{
    printf("%s\n", type);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int age[MAX] = {0};
    int score[MAX] = {10, 20, 30, 25, 50, 45, 33, 15, 99, 76};

    setRandomArray(age);
    // setRandomArray(score);

    int maxAgeIndexArray[MAX] = {0};
    int maxAgeIndex = 0;

    int maxAge = age[0];

    for (int i = 0; i < MAX; i++)
    {
        if (maxAge < age[i])
        {
            maxAge = age[i];
            maxAgeIndex = 0;
            maxAgeIndexArray[maxAgeIndex] = i;
            maxAgeIndex++;
        }
        else if (maxAge == age[i])
        {
            maxAgeIndexArray[maxAgeIndex] = i;
            maxAgeIndex++;
        }
    }

    printArray(age, "age");
    printArray(score, "score");

    printf("maxAge = %d\n", maxAge);
    printf("maxAgeIndex = %d\n", maxAgeIndex);
    for (int i = 0; i < maxAgeIndex; i++)
    {
        printf("score = %d\n", score[maxAgeIndexArray[i]]);
    }

    return 0;
}