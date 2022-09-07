#include <stdio.h>

int B222(int x)
{
    printf("in B fn, %d, in function %s\n", x, __func__);
    return 0;
}

int main()
{
    int x = 5;
    B222(x);
    return 0;
}
