#include <stdio.h>

int sum(n)
{
    if (n == 0)
    {
        return n;
    }
    return n + sum(n - 1);
}

int memory[100];

int sum1(n)
{
    if (n == 0)
    {
        memory[n] = n;
    }
    else
    {
        memory[n] = n + sum1(n - 1);
    }
    return memory[n];
}

int main()
{
    int n = 100;
    printf("%d\n", sum(n));
    printf("%d\n", sum1(n));
    return 0;
}