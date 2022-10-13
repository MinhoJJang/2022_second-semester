#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 5
#define INF 100000

#define s 0
#define t 1
#define x 2
#define y 3
#define z 4

int edge[MAX][MAX] = {
    {0, 6, INF, 7, INF},
    {INF, 0, 5, 8, -4},
    {INF, -2, 0, INF, INF},
    {INF, INF, -3, 0, 9},
    {2, INF, 7, INF, 0}};

int distance[MAX];

void setDistance(int source)
{
    for (int j = 0; j < MAX; j++)
    {
        distance[j] = INF;
        if (source == j)
        {
            distance[j] = 0;
        }
    }
}

void bellmanFord()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int source = 0; source < MAX; source++)
        {
            for (int dest = 0; dest < MAX; dest++)
            {
                if (dest != source && edge[source][dest] != INF && distance[dest] > distance[source] + edge[source][dest])
                {
                    distance[dest] = distance[source] + edge[source][dest];
                }
            }
        }
    }
}

void getDistance()
{
    printf("s t x y z\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", distance[i]);
    }
}

int main()
{
    setDistance(s);
    bellmanFord();
    getDistance();
    return 0;
}

// 음수 weight loop 찾는 것도 해줘야 하는데..,