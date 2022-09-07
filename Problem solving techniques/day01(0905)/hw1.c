#include <stdio.h>'
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
문제해결기법 1주차 과제
202033762 장민호

문제: 나이, 점수 배열을 받아, 나이가 가장 많은 사람의 점수, 나이가 가장 어린 사람의 점수, 가장 점수가 높은 사람의 나이, 가장 점수가 낮은 사람의 나이를 각각 출력한다.
*/

#define MAX 10

#define HIGH 1
#define LOW 0

void printArray(int arr[], char *type)
{
    printf("%s\n", type);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printValue(int temp, int arr[], int indexStoreArr[], int NumberOfIndex, char *condition)
{
    int len = strlen(condition);
    char *str = malloc(len);

    printf("======%s======\n", condition);

    // Age 혹은 Score print
    if (strcmp(condition, "LowestAgeScore") == 0 || strcmp(condition, "HighestAgeScore") == 0)
    {
        printf("%s = %d\n", strncpy(str, condition, len - 5), temp);
    }
    else
    {
        printf("%s = %d\n", strncpy(str, condition, len - 3), temp);
    }

    // Score 혹은 Age 배열 print
    for (int i = 0; i < NumberOfIndex; i++)
    {
        printf("%s = %d\n", condition, arr[indexStoreArr[i]]);
    }
}

void fn(int arr[], int arr2[], int level, char *condition)
{
    int temp = arr[0];
    int indexStoreArr[MAX];
    int NumberOfIndex = 0;

    if (level == HIGH)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (temp < arr[i])
            {
                temp = arr[i];
                NumberOfIndex = 0;
                indexStoreArr[NumberOfIndex++] = i;
            }
            else if (temp == arr[i])
            {
                indexStoreArr[NumberOfIndex++] = i;
            }
        }
    }
    else if (level == LOW)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (temp > arr[i])
            {
                temp = arr[i];
                NumberOfIndex = 0;
                indexStoreArr[NumberOfIndex++] = i;
            }
            else if (temp == arr[i])
            {
                indexStoreArr[NumberOfIndex++] = i;
            }
        }
    }

    printValue(temp, arr2, indexStoreArr, NumberOfIndex, condition);
}

int main()
{
    int age[MAX] = {19, 30, 15, 19, 15, 50, 35, 55, 30, 63};
    int score[MAX] = {10, 20, 90, 25, 50, 45, 33, 15, 90, 76};

    fn(age, score, LOW, "LowestAgeScore");
    fn(age, score, HIGH, "HighestAgeScore");
    fn(score, age, LOW, "LowestScoreAge");
    fn(score, age, HIGH, "HighestScoreAge");

    return 0;
}