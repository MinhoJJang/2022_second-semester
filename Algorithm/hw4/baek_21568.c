#include <stdio.h>

/*
202033762 장민호 알고리즘 HW4

https://www.acmicpc.net/problem/21568

// 참고 알고리즘
https://m.blog.naver.com/kks227/221414840544

A, B, C가 주어졌을 때, Ax+By=C를 만족하는 (x, y)중에서 다음을 만족하는 것을 아무거나 찾아보자.

x, y는 정수
-1,000,000,000 ≤ x, y ≤ 1,000,000,000
입력
첫째 줄에 정수 A, B, C가 주어진다.

출력
Ax+By=C를 만족하는 x, y를 공백으로 구분해 출력한다. 문제의 조건을 만족하는 (x, y)가 존재하지 않는 경우에는 -1을 출력한다.

제한
-1,000,000 ≤ A, B, C ≤ 1,000,000
A, B ≠ 0


예제 입력 1
1 2 3
예제 출력 1
3 0

예제 입력 2
3 4 5
예제 출력 2
-5 5

예제 입력 3
6 8 3
예제 출력 3
-1
*/

/*
먼저, 해가 존재하는지 여부부터 확인해야 한다. 만약 C가 gcd(A,B)의 배수가 아닐 경우, 애초에 불가능하다.


*/
#define NO 0
#define YES 1

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

int isAvailable(int c, int gcd)
{
    if (c % gcd != 0)
    {
        return NO;
    }
    return YES;
}

void EEA(int a, int b, int c)
{
    int r0 = a, r1 = b;
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;
    int temp = 0, q = 0;

    while (r1)
    {
        q = r0 / r1;
        temp = r0;
        r0 = r1;
        r1 = temp - r1 * q;
        temp = s0;
        s0 = s1;
        s1 = temp - s1 * q;
        temp = t0;
        t0 = t1;
        t1 = temp - t1 * q;
    }

    printf("x = %d, y = %d", (s0 - (s1 * q)) * c, t0 - (t1 * q) * c);
}

int main()
{
    int a, b, c, gcd;

    scanf("%d%d%d", &a, &b, &c);

    if (a < b)
    {
        gcd = GCD(b, a);
    }
    else
    {
        gcd = GCD(a, b);
    }

    if (isAvailable(c, gcd) == NO)
    {
        printf("-1");
    }
    else
    {
        EEA(a, b, c);
    }

    return 0;
}

/*
Testcase

1000000 847262 482836
x = 1841063696, y = -695525329

9382133 9382132 999
x = 570510807, y = -1353325085

38244 32133 593
-1

-32133 3949 21
x = 275919, y = 2034892

1 1 11
x = -11, y = 12

1000000 1000000 -1000000
x = 1000000, y = -999999

932131 321334 32138
x = 585856354, y = -215481115

3213 581910 485877
x = 1374175265, y = 39356038

-312312 -956864 -321345
-1

-312312 -956864 -321344
x = -1335406784, y = -1699774193
-> x,y overflow
*/