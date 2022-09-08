#include <stdio.h>

#define MAX 1000

int findMax(int local_arr[])
{
    int max = local_arr[0];
    for (int i = 0; i < MAX; i++)
    {
        if (max < local_arr[i])
        {
            max = local_arr[i];
        }
    }
    return max;
}

int main()
{

    int numList[MAX];

    for (int i = 0; i < MAX; i++)
    {
        numList[i] = i * 2 % 300;
    }

    printf("max = %d\n", findMax(numList));

    return 0;
}