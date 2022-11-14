#include "linkedList.h"

typedef struct _NODE
{
    int tag;
    char registeredDate[LEN];
    char feePaid[LEN];
    char name[LEN];
    int age;
    char organization[LEN];
    char job[LEN];
} PersonInfo;

// 노드 타입 정의
typedef struct _node
{
    PersonInfo data;     // 노드 데이터
    struct _node *pNext; // 다음 노드 포인터
} Node;

typedef struct _linkedList
{
    Node *pHead;
    Node *pTail;
    Node *pCurrent;
    int numData;
} LinkedList;

typedef LinkedList List;

// 구조체 타입 배열과 리스트를 각각 생성한다.
PersonInfo info_arr[LEN];
List *info_list;

int main()
{
    // 1. 먼저, 배열에 주어진 데이터를 삽입

    // 2. 리스트에다 주어진 데이터를 삽입

    // -> 과제에서 원하는 함수 사용하여 진행

    return 0;
}