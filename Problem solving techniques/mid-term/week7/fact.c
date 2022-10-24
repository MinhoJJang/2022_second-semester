#include <stdio.h>
#define MAX 21

typedef unsigned long long superlong;
superlong memo[MAX];

superlong fact(int n)
{
    if (n == 1)
    {
        memo[n] = 1;
    }
    else
    {
        memo[n] = n * fact(n - 1);
    }

    return memo[n];
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%lld", fact(n));

    return 0;
}