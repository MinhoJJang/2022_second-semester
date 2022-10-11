#include <stdio.h>
#define MAX 5
#define INFINITE 100000

int distance[MAX][MAX] = {
    {0, 2, INF, INF, 3},
    {INF, 0, 1, 3, -1},
    {4, INF, 0, 1, INF},
    {INF, INF, INF, 0, 1},
    {INF, 2, 3, INF, 0}};

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
    printf("    a b c d e\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%c : ", i + 97);
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