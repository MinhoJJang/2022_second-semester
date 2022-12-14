#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>
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

// 김태은
// 나이 그룹별 sort
void ageGroup_sort(PersonInfo *z)
{
    int i;
    FILE *a, *b, *c, *d, *e, *f, *g, *h; // 파일 생성
    a = fopen("10s.txt", "w");
    b = fopen("20s.txt", "w");
    c = fopen("30s.txt", "w");
    d = fopen("40s.txt", "w");
    e = fopen("50s.txt", "w");
    f = fopen("60s.txt", "w");
    g = fopen("70s.txt", "w");
    h = fopen("others.txt", "w");
    // 각 나이대에 맞는 파일에 데이터 입력
    for (i = 0; i < 30; i++)
    {
        if (z[i].age >= 70)
        {
            fprintf(g, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else if (z[i].age >= 60)
        {
            fprintf(f, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else if (z[i].age >= 50)
        {
            fprintf(e, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else if (z[i].age >= 40)
        {
            fprintf(d, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else if (z[i].age >= 30)
        {
            fprintf(c, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else if (z[i].age >= 20)
        {
            fprintf(b, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else if (z[i].age >= 10)
        {
            fprintf(a, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
        else
        {
            fprintf(h, "%d/%d-%d-%d/%s/%s/%d/%s/%s\n", z[i].tag, z[i].year, z[i].month, z[i].day, z[i].answer, z[i].name, z[i].age, z[i].organization, z[i].job);
        }
    }
    fclose(a);
    fclose(b);
    fclose(c);
    fclose(d);
    fclose(e);
    fclose(f);
    fclose(g);
}

// 김태은
// tag 번호 순 sort in array
void tag_sort(PersonInfo *a)
{
    int i;
    int j;
    PersonInfo tmp; // 태그 비교하며 임시 장소 이용해 자리바꿔줌
    for (i = 0; i < 30; i++)
    {
        for (j = i + 1; j < 30; j++)
        {
            if (a[j].tag < a[i].tag)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void AddNode(Node *head, PersonInfo *Person)
{                                // 노드를 추가하는 함수
    Node *current = head->pNext; // head->next 부터 첫 번째 노드가 들어감
    Node *tail = head;           // head 의 이전 위치를 기억하는 포인터 변수
    // find insert loaction
    while (current != NULL)
    {
        // if (current->pNext == NULL)
        //     break;
        tail = current;
        current = current->pNext;
    }

    // make newnode
    Node *NewNode = (Node *)malloc(sizeof(Node));

    // data
    (NewNode->data).tag = Person->tag;
    (NewNode->data).year = Person->year;
    (NewNode->data).month = Person->month;
    (NewNode->data).day = Person->day;
    strcpy((NewNode->data).answer, Person->answer);
    strcpy((NewNode->data).name, Person->name);
    (NewNode->data).age = Person->age;
    strcpy((NewNode->data).organization, Person->organization);
    strcpy((NewNode->data).job, Person->job);

    // 새로운 노드를 기존 노드에 연결
    tail->pNext = NewNode;
    NewNode->pNext = current;
}

void DisplayAllData(Node *head)
{
    Node *current = head->pNext;
    while (current != NULL)
    {
        printf("\n%d / %d - %d - %d / %s / %s / %d / %s / %s\n", current->data.tag, current->data.year,
               current->data.month, current->data.day, current->data.answer, current->data.name, current->data.age, current->data.organization, current->data.job);
        current = current->pNext;
    }
}

/*
    201835242 허혁
    string 안에 target(substring)이 존재하는지 확인하는 함수
*/
bool Has_substring(char *string, char *target)
{
    char *check = strstr(string, target);

    if (check != NULL)
        return true; // target이 존재하면 true 반환
    return false;
}

/*
    201835242 허혁
    Search for all from Choi (if found, print all information about the persons).
    - in the Array
*/
void search_Arr_Name(PersonInfo testArr[])
{                             // 하나씩 서치하면서 Choi 와 같은 문자가 있으면 Array 에 저장
    PersonInfo choi_array[5]; // Choi 씨를 찾으면 담는 배열, 즉 검색해서 같은 단어가 있으면 담는 배열
    char keyWord[20];         // 검색할 단어를 입력받을 배열
    int i = 0;
    int index = 0;
    printf("키워드 입력 => "); // 여기선 Choi를 입력
    scanf("%s", keyWord);      // 검색할 단어를 입력
    while (i < 5)
    { // 테스트하는 배열의 갯수가 5개
        if (Has_substring(testArr[i].name, keyWord))
        {                                           // 키워드를 이름으로 탐색
            choi_array[index].tag = testArr[i].tag; // 테스트 배열의 값을 검색하여 찾은 단어의 배열의 값으로 전달
            choi_array[index].year = testArr[i].year;
            choi_array[index].month = testArr[i].month;
            choi_array[index].day = testArr[i].day;
            strcpy(choi_array[index].answer, testArr[i].answer);
            strcpy(choi_array[index].name, testArr[i].name);
            choi_array[index].age = testArr[i].age;
            strcpy(choi_array[index].organization, testArr[i].organization);
            strcpy(choi_array[index].job, testArr[i].job);
            index++;
        }
        i++;
    }
    for (int i = 0; i < index; i++)
    {
        printf("\n%d / %d - %d - %d / %s / %s / %d / %s / %s\n", choi_array[i].tag, choi_array[i].year, choi_array[i].month, choi_array[i].day, choi_array[i].answer, choi_array[i].name, choi_array[i].age, choi_array[i].organization, choi_array[i].job);
    }
}

/*
    201835242 허혁
    Search for all from Choi (if found, print all information about the persons).
    - in the Linked List
*/
void search_LinkedList_Name(PersonInfo testArr[])
{ // 하나씩 서치하면서 Choi 와 같은 문자가 있으면 LinkedList 에 저장
    PersonInfo choi_List[5];
    char KeyWord[20] = {0};
    int i = 0;
    int index = 0;
    printf("키워드 입력 => "); // Choi 입력
    scanf("%s", KeyWord);
    //	연결 리스트를 탐색 ( 이 코드에선 TestArr 탐색 )
    while (i < 5)
    {
        if (Has_substring(testArr[i].name, KeyWord))
        {                                          // 키워드를 이름으로 탐색
            choi_List[index].tag = testArr[i].tag; // 배열에서 다른 배열
            choi_List[index].year = testArr[i].year;
            choi_List[index].month = testArr[i].month;
            choi_List[index].day = testArr[i].day;
            strcpy(choi_List[index].answer, testArr[i].answer);
            strcpy(choi_List[index].name, testArr[i].name);
            choi_List[index].age = testArr[i].age;
            strcpy(choi_List[index].organization, testArr[i].organization);
            strcpy(choi_List[index].job, testArr[i].job);
            index++;
        }
        i++;
    }
    Node *head = (Node *)malloc(sizeof(Node)); // head Node는 값이 없는 더미 Node
    head->pNext = NULL;
    for (int i = 0; i < index; i++)
    { // 찾은 Choi의 노드 수만큼 노드 추가
        AddNode(head, &choi_List[i]);
    }
    DisplayAllData(head); // 출력
}

/*
    201835242 허혁
    Search for all from Gachon University (if found, print all information about the persons).
    - in the Array
*/
void search_Array_Org(PersonInfo testArr[])
{ // 하나씩 서치하면서 Gachon University 와 같은 문자가 있으면 Array 에 저장
    PersonInfo gachon_University_Array[5];
    char KeyWord[20] = {0};
    int i = 0;
    int index = 0;
    printf("키워드 입력 => "); // Gachon University 입력
    scanf("%s", KeyWord);
    //	연결 리스트를 탐색
    while (i < 5)
    {
        if (Has_substring(testArr[i].organization, KeyWord))
        { //	키워드를 조직으로 탐색
            gachon_University_Array[index].tag = testArr[i].tag;
            gachon_University_Array[index].year = testArr[i].year;
            gachon_University_Array[index].month = testArr[i].month;
            gachon_University_Array[index].day = testArr[i].day;
            strcpy(gachon_University_Array[index].answer, testArr[i].answer);
            strcpy(gachon_University_Array[index].name, testArr[i].name);
            gachon_University_Array[index].age = testArr[i].age;
            strcpy(gachon_University_Array[index].organization, testArr[i].organization);
            strcpy(gachon_University_Array[index].job, testArr[i].job);
            index++;
        }
        i++;
    }
    for (int i = 0; i < index; i++)
    {
        printf("\n%d / %d - %d - %d / %s / %s / %d / %s / %s\n", gachon_University_Array[i].tag, gachon_University_Array[i].year, gachon_University_Array[i].month, gachon_University_Array[i].day, gachon_University_Array[i].answer, gachon_University_Array[i].name, gachon_University_Array[i].age, gachon_University_Array[i].organization, gachon_University_Array[i].job);
    }
}

void fileRead()
{
    // 동적 메모리 할당
    struct _NODE *PersonInfo = (struct _NODE *)malloc(sizeof(struct _NODE));

    FILE *inFile;
    // inFile = fopen("c:\\test2\\registraion_data.txt", "r"); // 파일을 읽기전용으로 연다
    inFile = fopen("./registration_data.txt", "r");
    if (inFile == NULL)
    {
        printf("[Fail to connect]");
        exit(1);
    }
    else
    {
        const char buffer[1000]; // 토큰을 활용하여 저장할 것이다 이를 위한 buffer를 생성
        const char *token;       // 토큰 포인터 선언

        int i = 0;
        int idx = 0;
        while (!feof(inFile))
        {
            i = 0;
            fgets(buffer, 1000, inFile);
            char *context;
            // token = strtok(buffer, "/-", &context); // 띄어쓰기를 기준으로 토큰을 나눈다.
            token = strtok(buffer, "/-");
            while (token != NULL)
            {
                if (i == 0)
                {
                    PersonInfo[idx].tag = atoi(token); // atoi 캐스팅을 이용해 토큰을 int값으로 저장
                }
                else if (i == 1)
                {
                    PersonInfo[idx].year = atoi(token);
                }
                else if (i == 2)
                {
                    PersonInfo[idx].month = atoi(token);
                }
                else if (i == 3)
                {
                    PersonInfo[idx].day = atoi(token);
                }
                else if (i == 4)
                {
                    strcpy(PersonInfo[idx].answer, token); // strcpy를 이용해 토큰을 문자열로 저장
                }
                else if (i == 5)
                {
                    strcpy(PersonInfo[idx].name, token);
                }
                else if (i == 6)
                {
                    PersonInfo[idx].age = atoi(token);
                }
                else if (i == 7)
                {
                    strcpy(PersonInfo[idx].organization, token);
                }
                else
                {
                    strcpy(PersonInfo[idx].job, token);
                }

                i++;
                token = strtok(NULL, "/-"); // 토큰의 끝을 띄어쓰기로 설정
            }
            idx++;
        }

        for (int i = 0; i < idx; i++)
        {
            printf("%d / %d-%d-%d / %s / %s / %d / %s / %s \n", PersonInfo[i].tag, PersonInfo[i].year, PersonInfo[i].month, PersonInfo[i].day, PersonInfo[i].answer,
                   PersonInfo[i].name, PersonInfo[i].age, PersonInfo[i].organization, PersonInfo[i].job);
        }

        // 파일의 내용이 구조체에 들어가는지 TEST코드
        fclose(inFile);
    }
}

// 201835222 이상윤
// 지정한 경로에 파일 저장
// fileWrite_array
void fileWrite_array(PersonInfo saveArr[])
{
    // 새로운 linkedList로 배열을 뽑아내거나 registraion_data.txt파일에서 가져온 데이터를 바탕으로 배열로 저장된 것을 파일에 쓰기

    FILE *outFile;
    char fileName[LEN];
    int i = 0;

    // 지정할 경로 설정
    printf("\n\n [저장할 파일의 경로를 입력하세요] : ");
    scanf("%s", fileName);
    outFile = fopen(fileName, "w");

    if (outFile == NULL)
    {
        printf("Fail to connect");
        exit(1);
    }

    else
    {
        while (saveArr[i].tag != 0)
        {
            fprintf(outFile, "%d / %d-%d-%d / %s / %s / %d / %s / %s\n", saveArr[i].tag, saveArr[i].year, saveArr[i].month, saveArr[i].day, saveArr[i].answer, saveArr[i].name, saveArr[i].age, saveArr[i].organization, saveArr[i].job);
            i++;
            // 구조체 배열을 이용한파일에 쓰기
        }
        printf("\n\n 파일이 지정된 위치에 저장되었습니다.");
    }
    fclose(outFile);
}

// 201835222 이상윤
// fileWrite_linkedList
void fileWrite_linkedList(Node **newHead)
{
    FILE *outFile;
    Node *ptr = *newHead;
    char fileName[100];

    // 지정할 경로 설정
    printf("\n\n [저장할 파일의 경로를 입력하세요] : ");
    scanf("%s", fileName);
    outFile = fopen(fileName, "w");

    if (outFile == NULL)
    {
        printf("[Fail to connect]");
        exit(1);
    }
    if (ptr == NULL)
    {
        printf("\n\n [Error]");
    }
    else
    {
        ptr = ptr->pNext;
        while (ptr != NULL)
        {

            fprintf(outFile, "%d / %d-%d-%d / %s / %s / %d / %s / %s\n", ptr->data.tag, ptr->data.year, ptr->data.month, ptr->data.day, ptr->data.answer, ptr->data.name, ptr->data.age, ptr->data.organization, ptr->data.job);
            ptr = ptr->pNext;
            // 링크드리스트를 이용한 파일 쓰기
        }
        printf("\n\n 파일이 지정된 위치에 저장되었습니다.");
    }
    fclose(outFile);
}