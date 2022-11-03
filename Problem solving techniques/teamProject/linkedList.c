#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <time.h>   // clock .. 시간, 날짜 함수
#define TRUE 1
#define FALSE 0

typedef int Data;

// 노드 타입 정의
typedef struct _node
{
    Data data;           // 노드 데이터
    struct _node *pNext; // 다음 노드 포인터
} Node;

// Linked List 타입 정의
typedef struct _linkedList
{
    Node *pHead;
    Node *pTail;

    Node *pCurrent; // iteration 용
    int numData;
} LinkedList;

typedef LinkedList List;

// 리스트 초기화
void list_init(List *pList)
{
    // head 용 dummy node 방식
    pList->pHead = (Node *)malloc(sizeof(Node));
    pList->pHead->pNext = NULL;
    pList->pTail = pList->pHead;

    pList->numData = 0;

    printf("리스트 초기화\n");
}

// 리스트 제거
void list_destroy(List *pList)
{
    list_init_iter(pList);
    Node *pPrev = NULL;
    while (list_hasNext(pList))
    {
        pPrev = pList->pCurrent; // pCurrent를 움직이기 전에 포인터값을 저장해놓는 것.
        list_next(pList);        // pCurrent 이동
        free(pPrev);
    }

    memset(pList, 0, sizeof(Node));
    printf("리스트 소멸\n");
}

// 데이터 추가
int list_add(List *pList, Data data)
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

// n번째 데이터 삭제
int list_remove(List *pList, int n)
{

    if (n >= pList->numData)
        return FALSE;

    // n번째 노드 삭제하려면
    // n번째 뿐 아니라 n-1 번째 노드 정보도 알아야 한다
    // 즉. 이전 노드(previous node) 또한 알아야 한다.
    list_init_iter(pList);
    int i = 0;
    Node *pPrev = NULL; // 이전 노드를 가리킬 포인터
    while (list_hasNext(pList))
    {
        pPrev = pList->pCurrent; // pCurrent를 움직이기 전에 포인터값을 저장해놓는 것.
        list_next(pList);
        if (i >= n)
            break;
        i++;
    }

    // 위 while 문이 끝나면
    // pCurrent 는 n번째 노드를,
    // pPrev 는 n-1번째 노드를 가리키고 있다

    // 순서 잘 생각해야 한다.  순서 바뀌면 엉망된다.

    // 삭제진행: 매우 단순 (배열에 비해)
    pPrev->pNext = pList->pCurrent->pNext;

    // 만약 tail 이 삭제할 노드면 tail 값도 수정해야함
    if (pList->pCurrent == pList->pTail)
    {
        pList->pTail = pPrev; // tail을 이전 노드로 이동
    }

    // n번째 노드 삭제, 동적 메모리 할당 해제! 꼭!
    free(pList->pCurrent);

    pList->numData--;

    return TRUE;

    return 0;
}

// n번째 데이터 수정
int list_set(List *pList, int n, Data data)
{
    if (n >= pList->numData)
        return FALSE;

    // head부터 시작해서 n번째 노드 찾기, iteration 사용
    list_init_iter(pList); // iteration 시작

    int i = 0; // 현재 몇번째 노드?

    while (list_hasNext(pList))
    {
        list_next(pList);
        if (i >= n)
            break; // n번째 노드 찾음
        i++;
    }
    // 위 while 문이 끝나면 pCurrent 는 n번째 노드를 가리키고 있음
    printf("%d 번째 데이터 수정 %d --> %d\n", n, pList->pCurrent->data, data);

    pList->pCurrent->data = data;
    return TRUE;
}

// 데이터 개수
int list_length(List *pList)
{

    return pList->numData;
}

// 데이터 조회, iteration 초기화
//  pCurrent가 가리키는 곳을 리스트의 헤더로 옮긴다.
void list_init_iter(List *pList)
{
    pList->pCurrent = pList->pHead;
}

// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List *pList)
{
    pList->pCurrent = pList->pCurrent->pNext; // 우선 current 한발 앞으로 이동
    Data result = pList->pCurrent->data;      // 데이터 추출
    return result;
}

// 데이터 조회, iteration 다음 데이터가 있나?
int list_hasNext(List *pList)
{
    if (pList->pCurrent->pNext == NULL) // '다음 노드' 존재 여부 체크.. 없으면 false
        return FALSE;

    return TRUE;
}

// 데이터 조회 : n번째 데이터값 읽기
int list_get(List *pList, int n, Data *pData)
{

    if (n >= pList->numData)
        return FALSE;

    // head부터 시작해서 n번째 노드 찾기, iteration 사용
    list_init_iter(pList); // iteration 시작

    int i = 0; // 현재 몇번째 노드?

    while (list_hasNext(pList))
    {
        list_next(pList);
        if (i >= n)
            break; // n번째 노드 찾음
        i++;
    }

    // 매개변수에 n번째 노드 데이터 담아줌
    *pData = pList->pCurrent->data;

    return 0;
}

// 데이터 삽입
int list_insert(List *pList, int n, Data data)
{

    // n값 유효범위 검증
    if (n > pList->numData)
        return FALSE;

    // 새로운 node생성
    Node *pInsertNode = (Node *)malloc(sizeof(Node));
    memset(pInsertNode, 0, sizeof(Node));
    pInsertNode->data = data;

    // 1. 첫번째나 맨 마지막에 추가하면 add와 같음.
    if (pList->numData == 0 || pList->numData == n) // 이 조건을 제대로 쓰지 않으면 오류 생김!!!
    {
        pList->pTail->pNext = pInsertNode;
        pList->pTail = pInsertNode;
    }
    else
    { // 2. n번째 노드에 삽입하는 경우
        list_init_iter(pList);
        Node *pPrev = NULL;
        int i = 0;
        while (list_hasNext(pList))
        {
            pPrev = pList->pCurrent; // pCurrent를 움직이기 전에 포인터값을 저장해놓는 것.
            list_next(pList);
            if (i >= n)
                break; // n찾기
            i++;
        }

        // 위 while 문이 끝나면
        // pCurrent 는 n번째 노드를,
        // pPrev 는 n-1번째 노드를 가리키고 있다
        pPrev->pNext = pInsertNode;
        pInsertNode->pNext = pList->pCurrent;
        // n-1번째 노드의 pNext가 새로운 노드를 가리키고, 새로운 노드의 pNext가 n번째 노드값을 가리킴.
    }

    printf("[%d]번째 데이터 %d 삽입\n", n, data);

    // 데이터개수 증가
    pList->numData++;

    return TRUE;
}

void printList(List *pList)
{
    list_init_iter(pList); // iteration 시작
    printf("[ ");
    while (list_hasNext(pList))
    {
        printf("%d,", list_next(pList));
    }
    printf("\b]\n"); // \b => backspace
}

int main()
{

    List myList;
    list_init(&myList);
    // List *pList = &myList;

    printList(&myList);

    list_add(&myList, 100); // 데이터 추가
    printList(&myList);     // [100]

    list_add(&myList, 50); // 데이터 추가
    printList(&myList);    // [100, 50]

    list_add(&myList, 100);
    printList(&myList); // [100, 50, 100]

    list_add(&myList, 20);
    printList(&myList); // [100, 50, 100, 20]

    // 데이터 수정====================

    list_set(&myList, 0, 40); // 0번째 데이터를 100->40으로 수정
    list_set(&myList, 1, 30);
    list_set(&myList, 4, 30); // 수정 실패
    printList(&myList);       // [40,30,100,20]

    // 데이터 개수====================
    printf("데이터 개수는 %d\n", list_length(&myList)); // 4

    // n번째 데이터 조회
    Data data;
    if (list_get(&myList, 0, &data))
        printf("0번째 : %d\n", data); // 40
    if (list_get(&myList, 6, &data))
        printf("6번째 : %d\n", data); // FAIL
    if (list_get(&myList, 2, &data))
        printf("2번째 : %d\n", data); // 100

    // 데이터 삭제
    printf("삭제전\n");
    printList(&myList); // [40,30,100,20]

    list_remove(&myList, 2); // 100 삭제
    printList(&myList);      // [40,30,20]

    list_remove(&myList, 2); // 20 삭제
    printList(&myList);      // [40,30]

    printf("데이터 개수는 %d\n", list_length(&myList)); // 2

    list_remove(&myList, 0); // 40 삭제
    printList(&myList);      // [30]

    list_remove(&myList, 0); // 30 삭제
    printList(&myList);      // []

    list_remove(&myList, 0);                            // 삭제할게 없음 - 실패
    printf("데이터 개수는 %d\n", list_length(&myList)); // 0

    // insert
    printf("-----------data insert-----------\n");
    list_add(&myList, 10);

    list_add(&myList, 20);
    printList(&myList); // [10, 20]

    list_insert(&myList, 1, 40);
    printList(&myList); // [10, 40, 20]

    list_insert(&myList, 0, 5);
    printList(&myList); // [5, 10, 40, 20]

    printf("데이터 개수는 %d\n", list_length(&myList)); // 4

    list_destroy(&myList); // 리스트 제거

    list_init(&myList);
    list_insert(&myList, 0, 5); // insert 는 list 의 끝에 추가 (add) 가능하게 동작시키기
    printList(&myList);         // [5]
    list_insert(&myList, 1, 25);
    printList(&myList); // [5, 25]
    list_insert(&myList, 2, 45);
    printList(&myList); //[5, 25, 45]

    list_destroy(&myList); // 리스트 제거

    {
        printf("--------------------------------------------------------\n");
        list_init(&myList);
        unsigned int test_size = 10;
        clock_t start, end;
        Data data;
        printf("프로파일링 시작: 스냅샷 - 아무키나 누르세요\n");

        printf("%d개 insert...\n", test_size);

        // 프로파일링
        start = clock();

        for (unsigned int i = 0; i < test_size; i++)
        {
            list_insert(&myList, 0, i); // 0번째 insert~
        }

        end = clock();

        printf("현재 리스트 size : %d\n", list_length(&myList));
        printf("insert 결과: %ld ms 경과\n", end - start);

        //----------------------------------------
        printf("아무키나 누르시면 다음 테스트 진행합니다\n");

        printf("%d 개 get...\n", test_size);

        // 프로파일링
        start = clock(); // 시간 측정 시작
        for (unsigned int i = 0; i < test_size; i++)
        {
            list_get(&myList, i, &data);
        }
        end = clock();

        printf("get 결과: %ld ms 경과\n", end - start);

        //---------------------------------
        printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷\n");

        printf("%d 개 remove...\n", test_size);
        start = clock(); // 시간 측정 시작
        for (unsigned int i = 0; i < test_size; i++)
        {
            list_remove(&myList, 5); // 0번째 삭제니까 n번째 값을 찾아가는 동작이 없으므로 빠름.. 그러니까 프로파일링 하면 linkedlist 에 편파적임
        }
        end = clock(); // 시간 측정 끝
        printf("현재 리스트 size : %d\n", list_length(&myList));
        printf("remove 결과 : %ld ms 경과\n", end - start);

        //========================
        printf("\n아무키나 입력하면 list destroy됩니다\n");

        list_destroy(&myList);
    }

    printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");

    return 0;
}
