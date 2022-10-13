#include <stdio.h>

void wrt_backward()
{
    int c;
    if ((c = getchar()) != '\n')
    {
        wrt_backward();
    }
    putchar(c);
}

int main()
{
    printf("input a line\n");
    wrt_backward();
    return 0;
}