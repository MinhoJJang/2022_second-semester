#include "linkedList.h"

/*
- 이름찾고 전체 데이터 출력
    - array
    - linkedList
- organization 같은 데이터 출력
    - array
    -linkedList(장민호)-

- 태그번호순으로 sort
- sort한걸 가지고 링크드리스트 만들기
- selection sort 사용해서 10대, 20대, 30대.. 구분
- 정렬한 파일을 텍스트 파일에 write

- array 에서 데이터 삭제
- linkedList에서 데이터 삭제(장민호)-

(나이정렬)
- array 에 데이터 삽입, 삽입될 위치를 찾아서 넣기
- linkedList 데이터 삽입, 마찬가지로 나이순 정렬(장민호)-

*/

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
    printf("================================\n");
    printf("배열에 데이터 삽입하기_Start\n");
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

    printArr(info);
    printf("배열에 데이터 삽입하기_End\n");

    // 202033762 장민호
    printf("================================\n");
    printf("배열 값을 리스트에 데이터 삽입하기_Start\n");

    for (int i = 0; i < len; i++)
    {
        list_insert(&pList, info[i]);
    }
    printList(&pList);

    printf("배열 값을 리스트에 데이터 삽입하기_End\n");

    // 202033762 장민호
    printf("================================\n");
    printf("배열 나이순 정렬_Start\n");

    list_sort(&pList);
    printList(&pList);

    printf("배열 나이순 정렬_End\n");

    // 202033762 장민호
    printf("================================\n");
    printf("배열에 데이터 추가 시 정렬되어 출력_Start\n");
    PersonInfo newData = {41, 2020, 06, 04, "yes", "Bobby Anderson", 45, "McGill University", "engineer"};

    list_add(&pList, newData);
    printList(&pList);

    printf("배열에 데이터 추가 시 정렬되어 출력_End\n");

    // 202033762 장민호
    printf("================================\n");
    printf("Search for all from Gachon University (if found, print all information about the persons)_Start\n");

    PersonInfo searchedInfo[LEN];
    memcpy(searchedInfo, list_search_organization(&pList, "Gachon University"), sizeof(searchedInfo));
    printArr(searchedInfo);
    printf("Search for all from Gachon University (if found, print all information about the persons)_End\n");

    // 202033762 장민호
    printf("================================\n");
    printf("All 'Choi's canceled registration. Remove the data from in the linked list_Start\n");
    list_delete_firstName(&pList, "Choi");
    printList(&pList);

    printf("All 'Choi's canceled registration. Remove the data from in the linked list_End\n");

    return 0;
}
