#include <stdio.h>
#define MAX 5
#define INFINITE 100000

int distance[MAX][MAX] = {
    {0, 2, INFINITE, INFINITE, 3},
    {INFINITE, 0, 1, 3, -1},
    {4, INFINITE, 0, 1, INFINITE},
    {INFINITE, INFINITE, INFINITE, 0, 1},
    {INFINITE, 2, 3, INFINITE, 0}};

void floyd()
{
    for (int k = 0; k < MAX; k++)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

void getDistance()
{
    for (int i = 0; i < MAX; i++)
    {
        if (i == 0)
        {
            printf("    0 1 2 3 4\n");
        }

        printf("%d : ", i);
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", distance[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    floyd();
    getDistance();
    return 0;
}