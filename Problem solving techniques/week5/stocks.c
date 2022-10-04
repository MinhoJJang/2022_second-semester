#include <stdio.h>

typedef struct _stock
{
    float earnings_per_share;
    int number_of_share;
    float anticipated_price;
} stock;

void setStock(stock *st, float earnings, int share)
{
    st->earnings_per_share = earnings;
    st->number_of_share = share;
    st->anticipated_price = st->earnings_per_share * st->number_of_share;
}

void getStock(stock *st)
{
    printf("earnings_per_share: %.2f\n", st->earnings_per_share);
    printf("number_of_share: %d\n", st->number_of_share);
    printf("anticipated_price: $%.2f\n", st->anticipated_price);
    printf("\n");
}

int main()
{
    stock stocks[5];

    setStock(&stocks[0], 1.78, 347);
    setStock(&stocks[1], 6.12, 184);
    setStock(&stocks[2], 109.33, 4);
    setStock(&stocks[3], 0.32, 462);
    setStock(&stocks[4], 19.78, 13);

    for (int i = 0; i < 5; i++)
    {
        getStock(&stocks[i]);
    }

    return 0;
}