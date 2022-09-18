/*
https://www.acmicpc.net/problem/11004

알고리즘 HW2
quick sort 사용하여 풀면 된다.

문제
수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.

둘째에는 A1, A2, ..., AN이 주어진다. (-109 ≤ Ai ≤ 109)

출력
A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.

예제 입력 1
5 2
4 1 2 3 5
예제 출력 1
2
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5000001
#define YES 1
#define NO 0
int arr[MAX];

// 배열 두개값 바꾸기
void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

// 배열 정렬 영역 쪼개기 (쪼갤 index 리턴)
int Partition(int arr[], int left, int right)
{

    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽! (값)
    int low = left + 1;    // low 는 피벗 오른쪽에서 시작 (index)
    int high = right;      // high 는 right 부터 시작 (index)

    //
    while (low <= high)
    {
        // low 우측 이동, pivot 보다 큰 것을 만날때까지
        while (arr[low] <= pivot && low <= high)
        {
            low++;
        }

        // high 좌측 이동, pivot 보다 작은 것을 만날때까지!
        while (arr[high] >= pivot && high >= (left + 1))
        {
            high--;
        }

        // low와 high가 멈추면
        if (low <= high) // low, high가 교차되지 않은 상태라면 Swap 진행
            Swap(arr, low, high);
    }

    // pivot과 high가 가리키는 대상교환
    Swap(arr, left, high);

    return high; // 옮겨진 피벗의 위치정보 리턴
}

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right); // pivot 정하고, 둘로쪼갬
        QuickSort(arr, left, pivot - 1);         // pivot 왼쪽영역을 퀵정렬
        QuickSort(arr, pivot + 1, right);        // pivot 오른쪽영역을퀵정렬
    }
}

int compare(int num1, int num2) // qsort에 쓰기위한 오름차순 비교 함수 구현
{
    if (num1 < num2) // a가 b보다 작을 때는
        return -1;   // -1 반환

    if (num1 > num2) // a가 b보다 클 때는
        return 1;    // 1 반환

    return 0; // a와 b가 같을 때는 0 반환
}

int main()
{
    int numberOfNumbers;
    int index;

    scanf("%d", &numberOfNumbers);
    scanf("%d", &index);

    for (int i = 0; i < numberOfNumbers; i++)
    {
        scanf("%d", &arr[i]);
    }

    // QuickSort(arr, 0, numberOfNumbers - 1);
    qsort(arr, numberOfNumbers, sizeof(int), compare);

    printf("%d", arr[index - 1]);

    return 0;
}