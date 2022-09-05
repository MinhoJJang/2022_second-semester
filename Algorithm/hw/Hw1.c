#include <stdio.h>

/*
https://www.acmicpc.net/problem/2750
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

202033762 장민호
*/

#define MAX 1005 //  N(1 ≤ N ≤ 1,000)
int arr[MAX];

void InsertionSort(int arr[], int n)
{
    int i, j;
    int insData; // 데이터 임시 보관소

    for (i = 1; i < n; i++)
    {
        insData = arr[i]; // i 번째 데이터를 insData에 임시로 저장한다.

        for (j = i - 1; j >= 0; j--) // insData 위치 '전' 까지의 모든 숫자를 비교한다.
        {
            if (insData < arr[j]) // 오름차순 정렬. 즉, 만약 i번째 데이터와, 그 전의 데이터를 비교해서 그 전의 데이터가 더 클 경우, 그 두 데이터 위치를 바꿔야 오름차순이 유지될 것이다.
            {
                arr[j + 1] = arr[j]; // 데이터 위치를 바꿔준다.
            }
            else
            {
                // 왜 break 인가? Insertion Sort 특성상, insData 위치 전까지의 수열은 반드시 정렬된 상태이다. 따라서 insData가 arr[j]보다 커지는 순간 insData의 위치가 정해진 것이고, 그 뒤는 이미 정렬되어 있으므로 더 이상 살펴볼 필요가 없다. 이러한 이유로 Insertion Sort는 이미 거의 정렬된 배열에 대해 매우 빠른 속도를 보여준다.
                break;
            }
        }

        arr[j + 1] = insData; // 데이터 위치를 찾았으므로 삽입해준다.
    }
}

void printArr(int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void inputData(int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    inputData(N);
    InsertionSort(arr, N);
    printArr(N);

    return 0;
}