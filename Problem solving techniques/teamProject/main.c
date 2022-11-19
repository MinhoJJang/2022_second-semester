#include "linkedList.h"

// typedef struct _NODE
// {
//     int tag;
//     int year;
//     int month;
//     int day;
//     char answer[LEN];
//     char name[LEN];
//     int age;
//     char organization[LEN];
//     char job[LEN];
// } PersonInfo;

// 노드 타입 정의
// typedef struct _node
// {
//     PersonInfo data;     // 노드 데이터
//     struct _node *pNext; // 다음 노드 포인터
// } Node;

// typedef struct _linkedList
// {
//     Node *pHead;
//     Node *pTail;
//     Node *pCurrent;
//     int numData;
// } LinkedList;

// typedef LinkedList List;

// 구조체 타입 배열과 리스트를 각각 생성한다.

int main()
{
    List pList;
    list_init(&pList);
    PersonInfo info[LEN];
    FILE *inFile;
    inFile = fopen("./registration_data.txt", "r");
    int len = 0;
    /*
    6/2020-06-04/yes/Bobby Anderson/33/McGill University/engineer
    */

    // 202033762 장민호
    // info 배열에 데이터 삽입하기_Start
    if (inFile != NULL)
    {
        int i = 0;
        while (!feof(inFile))
        {
            fscanf(inFile, "%d/%d-%d-%d/%[^/]/%[^/]/%d/%[^/]/%s", &info[i].tag, &info[i].year, &info[i].month, &info[i].day, info[i].answer, info[i].name, &info[i].age, info[i].organization, info[i].job);
            i++;
        }
        len = i - 1;

        fclose(inFile);
    }

    printArr(info, len);
    // info 배열에 데이터 삽입하기_END

    printf("=============================\n");

    // 202033762 장민호
    // 배열 값을 리스트에 삽입하기_Start
    for (int i = 0; i < len; i++)
    {
        list_insert(&pList, info[i]);
    }
    printList(&pList);
    // 배열 값을 리스트에 삽입하기_End

    printf("=============================\n");

    // 202033762 장민호
    // 배열 나이순 정렬_Start
    list_sort(&pList);
    printList(&pList);

    return 0;
}