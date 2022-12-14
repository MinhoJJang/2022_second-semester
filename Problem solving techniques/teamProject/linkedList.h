#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <malloc.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define LEN 100

// 202033762 장민호
// 구조체 생성
typedef struct _NODE
{
    int tag;
    int year;
    int month;
    int day;
    char answer[LEN];
    char name[LEN];
    int age;
    char organization[LEN];
    char job[LEN];
} PersonInfo;

// 202033762 장민호
// 노드 타입 정의
typedef struct _node
{
    PersonInfo data;     // 노드 데이터
    struct _node *pNext; // 다음 노드 포인터
} Node;

// 202033762 장민호
// Linked List 타입 정의
typedef struct _linkedList
{
    Node *pHead;
    Node *pTail;
    Node *pCurrent;
    int numData;
} LinkedList;

typedef LinkedList List;

// 202033762 장민호
// 데이터 조회, iteration 초기화
//  pCurrent가 가리키는 곳을 리스트의 헤더로 옮긴다.
void list_init_iter(List *pList)
{
    pList->pCurrent = pList->pHead;
}

// 202033762 장민호
// 데이터 조회, iteration 다음 데이터가 있나?
int list_hasNext(List *pList)
{
    if (pList->pCurrent->pNext == NULL) // '다음 노드' 존재 여부 체크.. 없으면 false
        return FALSE;

    return TRUE;
}

// 202033762 장민호
// 리스트 초기화
void list_init(List *pList)
{
    pList->pHead = (Node *)malloc(sizeof(Node));
    pList->pHead->pNext = NULL;
    pList->pTail = pList->pHead;
    pList->numData = 0;
    printf("리스트 초기화\n");
}

// 202033762 장민호
// 데이터 조회, iteration 다음 데이터 추출
PersonInfo list_next(List *pList)
{
    pList->pCurrent = pList->pCurrent->pNext;  // 우선 current 한발 앞으로 이동
    PersonInfo result = pList->pCurrent->data; // 데이터 추출
    return result;
}

// 202033762 장민호
// 데이터 개수
int list_length(List *pList)
{
    return pList->numData;
}

// 202033762 장민호
// 배열 속 데이터 출력
void printArr(PersonInfo info[])
{
    printf("============Array Print Start=============\n");
    for (int i = 0; i < LEN; i++)
    {
        if (info[i].tag == 0)
        {
            break;
        }
        printf("%d/%d-%d-%d/%s/%s/%d/%s/%s\n", info[i].tag, info[i].year, info[i].month, info[i].day, info[i].answer, info[i].name, info[i].age, info[i].organization, info[i].job);
    }
    printf("============Array Print Stop=============\n");
}

// 202033762 장민호
// 리스트 속 데이터 출력
void printList(List *pList)
{
    list_init_iter(pList); // iteration 시작
    printf("============List Print Start=============\n");
    while (list_hasNext(pList))
    {
        PersonInfo info = list_next(pList);
        printf("%d/%d-%d-%d/%s/%s/%d/%s/%s\n", info.tag, info.year, info.month, info.day, info.answer, info.name, info.age, info.organization, info.job);
    }
    printf("============List Print Stop=============\n\n");
}

// 202033762 장민호
// 리스트 정렬. (나이 오름차순)
void list_sort(List *pList)
{
    // 링크드리스트를 나이순으로 정렬한다. Selection Sort 사용
    int len = pList->numData;
    for (int i = 0; i < len - 1; i++)
    {
        // pList가 헤드를 가리키도록
        // pCurrent = pHead
        list_init_iter(pList);

        // FirstNode는 계속 그 다음 노드가 되어야 하므로 pCurrent를 i번 만큼 뒤로 땡겨야 한다.
        for (int j = 0; j < i; j++)
        {
            if (list_hasNext(pList))
            {
                pList->pCurrent = pList->pCurrent->pNext;
            }
        }

        // 처음 노드와 선택될 노드를 생성
        Node *firstNode = (Node *)malloc(sizeof(Node));
        Node *selectNode = (Node *)malloc(sizeof(Node));
        Node *tempNode = (Node *)malloc(sizeof(Node));
        Node *tempNode2 = (Node *)malloc(sizeof(Node));
        Node *a = (Node *)malloc(sizeof(Node));
        Node *b = (Node *)malloc(sizeof(Node));
        Node *c = (Node *)malloc(sizeof(Node));
        Node *d = (Node *)malloc(sizeof(Node));
        firstNode = pList->pCurrent;
        selectNode = firstNode;

        // 그 다음 노드부터 차례로 찾기
        while (list_hasNext(pList))
        {
            if (pList->pCurrent->pNext->data.age < selectNode->pNext->data.age)
            {
                // 만약 더 작은 데이터를 찾았을 경우, 그 이전 노드를 select한다.
                selectNode = pList->pCurrent;
            }
            // 현재 가리키는 노드를 그 다음 노드로 변경해준다.
            pList->pCurrent = pList->pCurrent->pNext;
        }

        memcpy(tempNode, firstNode, sizeof(Node));
        memcpy(tempNode2, selectNode, sizeof(Node));

        // 두 노드의 위치를 변경한다.
        if (firstNode == selectNode)
        {
            continue;
        }
        else if (firstNode->pNext == selectNode)
        {

            a = tempNode2->pNext;
            b = tempNode->pNext;
            c = tempNode2->pNext->pNext;

            firstNode->pNext = a;
            firstNode->pNext->pNext = b;
            firstNode->pNext->pNext->pNext = c;
        }
        else
        { /*
         firstNode의 pNext와, selectNode의 pNext를 서로 변경해야 한다.
         서순 주의 꼬이면 망함
     */

            a = tempNode2->pNext;
            b = tempNode->pNext->pNext;
            c = tempNode->pNext;
            d = tempNode2->pNext->pNext;

            firstNode->pNext = a;
            firstNode->pNext->pNext = b;
            selectNode->pNext = c;
            selectNode->pNext->pNext = d;
        }
    }
}

// 202033762 장민호
/*
One “Paik” registered late. Add the data to
  in the linked list
*/
int list_add(List *pList, PersonInfo data)
{
    // 새로운 node 생성
    Node *pNewNode = (Node *)malloc(sizeof(Node));
    memset(pNewNode, 0, sizeof(Node));
    pNewNode->data = data;

    // 삽입된 데이터가 들어갈 위치를 찾아야 함. 이때, List는 이미 나이순으로 정렬된 상태여야 함.
    // 1. 먼저 기존 리스트를 나이순으로 정렬한다.
    list_sort(pList);

    // 2. pHead->pNext부터 차례로, 나이를 비교한다.
    list_init_iter(pList);

    while (list_hasNext(pList))
    {
        // 만약 pCurrent에서 다음 노드가 존재할 경우 그 다음 노드의 age값과 새로 들어온 데이터의 age값을 비교한다.
        // 만약 그 다음 데이터의 age 값이 더 크다면, pCurrent가 곧 pNewNode가 들어갈 자리이다.
        if (pList->pCurrent->pNext->data.age > data.age)
        {
            pNewNode->pNext = pList->pCurrent->pNext;
            pList->pCurrent->pNext = pNewNode;
            (pList->numData)++;
            return TRUE;
        }
        pList->pCurrent = pList->pCurrent->pNext;
    }

    // 만약 while문이 끝날때까지 if문을 타지 않는다는 것은, 현재 들어온 노드의 나이가 가장 크다는 뜻. 그냥 맨 뒤에 추가하는 것과 같다.

    // tail이 가리키던 node의 next를 새로운 node에 연결
    pList->pTail->pNext = pNewNode;

    // tail 을 새로운 node 로 이동
    pList->pTail = pNewNode;

    // 데이터 개수 증가
    (pList->numData)++;

    return TRUE;
}

// 202033762 장민호
// 데이터 추가
int list_insert(List *pList, PersonInfo data)
{
    // 새로운 node 생성
    Node *pNewNode = (Node *)malloc(sizeof(Node));
    memset(pNewNode, 0, sizeof(Node));
    pNewNode->data = data;

    // tail이 가리키던 node의 next를 새로운 node에 연결
    pList->pTail->pNext = pNewNode;

    // tail 을 새로운 node 로 이동
    pList->pTail = pNewNode;

    // 데이터 개수 증가
    (pList->numData)++;

    return TRUE;
}

/*
202033762 장민호
Search for all from Gachon University (if found, print all information about the persons).
  - in the linked list
*/
PersonInfo *list_search_organization(List *pList, char key[])
{
    int idx = 0;
    static PersonInfo returnInfo[LEN]; // 반환할 배열 선언

    list_init_iter(pList);      // pCurrent 맨 처음으로 돌림
    while (list_hasNext(pList)) // 다음 노드가 존재한다면
    {
        if (strcmp(key, pList->pCurrent->pNext->data.organization) == 0) // 만약 같으면
        {
            returnInfo[idx] = pList->pCurrent->pNext->data;
            idx++;
            // 해당 정보를 returnInfo에 저장한다.
        }
        pList->pCurrent = pList->pCurrent->pNext;
    }

    return returnInfo;
}

/*
202033762 장민호
All “Choi”s canceled registration. Remove the data from
  in the linked list
*/
void list_delete_firstName(List *pList, char key[])
{

    list_init_iter(pList);      // pCurrent 맨 처음으로 돌림
    while (list_hasNext(pList)) // 다음 노드가 존재한다면
    {
        // 해당 노드의 이름을 가져오고, 그 이름의 성씨를 비교해야 하므로 공백 기준으로 문자열을 나누는 strtok을 사용하여 이름이라는 문자열을 두 개의 문자열로 나누고, 맨 뒤의 문자열, 성씨가 같을 경우 해당 노드를 제거한다.
        char tempName[LEN];
        char name[2][LEN];
        int idx = 0;
        strcpy(tempName, pList->pCurrent->pNext->data.name);

        char *ptr = strtok(tempName, " ");

        while (ptr != NULL)
        {
            strcpy(name[idx], ptr);
            idx++;
            ptr = strtok(NULL, " ");
        }

        if (strcmp(name[idx - 1], key) == 0) // 만약 맨 뒤 이름(성씨)이 서로 같으면
        {
            Node *pDelete = NULL;
            pDelete = pList->pCurrent->pNext;
            // 만약 다음 노드가 마지막일 경우
            if (pList->pCurrent->pNext == pList->pTail)
            {
                pList->pTail = pList->pCurrent; // tail을 이전 노드로 이동
                free(pDelete);
                pList->numData--;
                break; // 마지막 노드이므로 더 조사할 필요 없다.
            }
            else
            {
                pList->pCurrent->pNext = pList->pCurrent->pNext->pNext;
                free(pDelete);
            }
            // 다음 연결된 노드가 또 Choi일 수도 있기 때문에 pCurrent를 움직이지 않는다.
        }
        else // 만약 성씨가 같지 않다면, 조사를 계속한다.
        {
            pList->pCurrent = pList->pCurrent->pNext;
        }
    }
}
