#include <stdio.h>

#define MAX_OBJECT 105
#define MAX_WEIGHT 100010

//#define max(a, b) (a > b) ? a : b
#define max(a, b) (((a) > (b)) ? (a) : (b))
int knap[MAX_OBJECT][MAX_WEIGHT] = {0};

// int max(int a, int b)
// {
//     if (a < b)
//     {
//         return b;
//     }
//     return a;
// }

int knapSack01(int weight[], int value[], int numberOfObject, int maxWeight)
{

    // knap 배열을 채울 때, 들어오는 물건 개수 당 가방의 최대 무게를 고려해 표를 채운다는 생각으로 DP를 구현한다.
    int numOfItem, knapMaxWeight;

    /*
            0   1   2   3   4   5   6   7   8   9   10 (knapMaxWeight)
        0
        1
        2
        3
        4
        5
    (numOfItem)
    */

    for (numOfItem = 1; numOfItem <= numberOfObject; numOfItem++)
    {
        for (knapMaxWeight = 1; knapMaxWeight <= maxWeight; knapMaxWeight++)
        {
            // 일단, 가방의 용량이 적어도 현재 들어온 물건의 용량보다는 크거나 같아야 한다.
            if (knapMaxWeight >= weight[numOfItem])
            {
                // 현재 들어온 물건의 용량보다 크거나 같다면, 그 전까지 담았던 물건들의 가치와 현재 담을 수 있는 물건의 가치를 계산해서 무엇이 더 큰지 비교해야 한다.

                knap[numOfItem][knapMaxWeight] = max(knap[numOfItem - 1][knapMaxWeight], knap[numOfItem - 1][knapMaxWeight - weight[numOfItem]] + value[numOfItem]);
            }
            // 만약 가방의 용량이 되지 않는다면, 애초에 그 물건은 담을 생각조차 할 수 없으므로, 그냥 물건이 들어오지 않은 것과 같은 의미이다.
            else
            {
                knap[numOfItem][knapMaxWeight] = knap[numOfItem - 1][knapMaxWeight];
            }
        }
    }

    return knap[numberOfObject][maxWeight];
}

int main()
{
    int numberOfObject;
    int maxWeight;
    int weight[MAX_OBJECT];
    int value[MAX_OBJECT];

    scanf("%d", &numberOfObject);
    scanf("%d", &maxWeight);

    for (int i = 1; i <= numberOfObject; i++)
    {
        scanf("%d %d", &weight[i], &value[i]);
    }

    int optimalValue = knapSack01(weight, value, numberOfObject, maxWeight);

    printf("%d", optimalValue);

    return 0;
}
