/*
알고리즘 HW2
202033762 장민호

https://www.acmicpc.net/problem/9251

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1
ACAYKP
CAPCAK
예제 출력 1
4
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001
#define max(a, b) (((a) > (b)) ? (a) : (b)) // max 매크로 함수

int dp[MAX][MAX];

void LCS(char str1[], char str2[], int len1, int len2)
{
    /*
    Solution_1.
    if (len1 == 0 || len2 == 0)
    {
        // 문자열 길이 중 어느 하나가 0이면 즉시 0을 리턴한다.
        dp[len1][len2] = 0;
    }
    else if (str1[len1 - 1] == str2[len2 - 1])
    {
        // 만약 각 문자열 맨 끝자리가 같을 경우, 이때의 LCS는 각각의 문자열 끝자리 - 1 자리까지의 LCS에다가 1을 더한 것과 반드시 같게 된다.
        dp[len1][len2] = 1 + LCS(str1, str2, len1 - 1, len2 - 1);
    }
    else
    {
        // 이도저도 아니라면, 두가지 경우의 수가 생긴다. str1-1 과 str2 의 LCS 와 str1 과 str2-1 의 LCS의 길이를 비교해 더 큰 것을 리턴하면 된다.
        dp[len1][len2] = max(LCS(str1, str2, len1, len2 - 1), LCS(str1, str2, len1 - 1, len2));
    }

    return dp[len1][len2];

    시간초과. max(LCS(), LCS()) 여기에서 잦은 함수 호출이 원인인 것 같다.
    */

    // Solution_2
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main()
{
    char str1[MAX];
    char str2[MAX];

    scanf("%s", str1);
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    LCS(str1, str2, len1, len2);

    printf("%d", dp[len1][len2]);

    return 0;
}
// 맞았습니다!