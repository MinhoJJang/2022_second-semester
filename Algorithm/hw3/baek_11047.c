#include <stdio.h>

int main()
{
    int coinTypes;
    int totalValue;
    int coinValue[10] = {0};
    int type;
    int optimalCoinNumber = 0;

    scanf("%d %d", &coinTypes, &totalValue);
    for (type = 0; type < coinTypes; type++)
    {
        scanf("%d", &coinValue[type]); // 코인의 가치를 입력받는다.
    }
    type--;

    while (type >= 0)
    {
        // 코인의 가치가 큰 것부터 차례로 나눈다. type 변수를 1씩 줄여가면서 최대한 적은 코인을 사용하도록 한다.
        if (totalValue / coinValue[type] >= 1)
        {
            int coins = totalValue / coinValue[type];

            optimalCoinNumber = optimalCoinNumber + coins;
            totalValue = totalValue - (coins * coinValue[type]);

            // 만약 남은 금액이 0이면 종료한다. A1 = 1이므로, 반드시 while문이 종료되기 전에 totalValue == 0 이 성립한다.
            if (totalValue == 0)
            {
                printf("%d", optimalCoinNumber);
                return 0;
            }
            type--;
        }
        else
        {
            type--;
        }
    }

    return 0;
}