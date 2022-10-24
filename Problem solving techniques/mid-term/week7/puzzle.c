#include <stdio.h>

int puzzle(int n)
{
    printf("n = %d\n", n);
    if (n == 1)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return puzzle(n / 2) + n;
    }
    else
    {
        return puzzle(n * 3 + 1) + n;
    }
}

int main()
{
    int n = 6;
    printf("%d", puzzle(n));
    return 0;
}