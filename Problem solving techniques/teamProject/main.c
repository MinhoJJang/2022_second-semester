#include "linkedList.h"

/*
- 이름찾고 전체 데이터 출력
    - array
    - linkedList
- organization 같은 데이터 출력
    - array
    -linkedList

- 태그번호순으로 sort
- sort한걸 가지고 링크드리스트 만들기
- selection sort 사용해서 10대, 20대, 30대.. 구분
- 정렬한 파일을 텍스트 파일에 write

- array 에서 데이터 삭제
- linkedList에서 데이터 삭제

(나이정렬)
- array 에 데이터 삽입, 삽입될 위치를 찾아서 넣기
- linkedList 데이터 삽입, 마찬가지로 나이순 정렬

*/

int main()
{
    List pList;
    list_init(&pList);
    PersonInfo info[LEN];
    int len = 0;

    // ======================== SetUp Start ========================

    /*
        202033762 장민호
        SetUp - Read a text file provided (conference registrations data)
    */
    FILE *inFile;
    inFile = fopen("./registration_data.txt", "r");

    /*
        202033762 장민호
        SetUp - Store the data in a struct array.
    */
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

    /*
        202033762 장민호
        SetUp - Store the data in a linked list.
    */
    printf("================================\n");
    printf("배열 값을 리스트에 데이터 삽입하기_Start\n");

    for (int i = 0; i < len; i++)
    {
        list_insert(&pList, info[i]);
    }
    printList(&pList);

    printf("배열 값을 리스트에 데이터 삽입하기_End\n");

    // ======================== SetUp Finish ========================

    /*
           201835242 허혁
            Search for “Choi” (if found, print all information about the persons) - in the array
    */
    printf("================================\n");
    printf("Search for all from Choi (if found, print all information about the persons)_Start\n");

    // 1. 파일에서 가져오는 대신 Test Array 에서 가져옴
    // 2. Search 할 문장과 비교 후 Choi 가 포함된 구조체 배열을 출력

    search_Arr_Name(info); // Search 후 Arr
    printf("Search for all from Choi (if found, print all information about the persons)_End\n");

    /*
       201835242 허혁
        Search for “Choi” (if found, print all information about the persons) - in the linked list
    */
    printf("================================\n");
    printf("Search for all from Choi (if found, print all information about the persons)_Start\n");

    PersonInfo searchedInfo1[LEN];
    memcpy(searchedInfo1, list_search_name(&pList, "Choi"), sizeof(searchedInfo1));
    printArr(searchedInfo1);

    // search_LinkedList_Name(info); // 연결 리스트로 출력
    printf("Search for all from Choi (if found, print all information about the persons)_End\n");

    /*
       201835242 허혁
        Search for all from Gachon University (if found, print all information about the persons). - in the array
    */
    printf("================================\n");
    printf("Search for all from Gachon University (if found, print all information about the persons)_Start\n");

    search_Array_Org(info);
    printf("Search for all from Gachon University (if found, print all information about the persons)_End\n");

    /*
        202033762 장민호
        Search for all from Gachon University (if found, print all information about the persons) - in the linked list
    */
    printf("================================\n");
    printf("Search for all from Gachon University (if found, print all information about the persons)_Start\n");

    PersonInfo searchedInfo[LEN];
    memcpy(searchedInfo, list_search_organization(&pList, "Gachon University"), sizeof(searchedInfo));
    printArr(searchedInfo);
    printf("Search for all from Gachon University (if found, print all information about the persons)_End\n");

    /*
        202033762 장민호
        Sort the data in the array in age order
    */
    printf("================================\n");
    printf("배열 나이순 정렬_Start\n");

    list_sort(&pList);
    printList(&pList);

    printf("배열 나이순 정렬_End\n");

    /*
        김태은
        Sort the data in the array in tag# order
    */
    printf("================================\n");

    printf("배열 태그순 정렬 start\n");
    tag_sort(info);
    printArr(info);
    printf("배열 태그순 정렬 end\n");

    /*
        202033762 장민호
        Create a linked list using the sorted data.
    */
    printf("================================\n");
    printf("Create a linked list using the sorted data._Start\n");

    List tempList;
    list_init(&tempList);
    for (int i = 0; i < len; i++)
    {
        list_insert(&tempList, info[i]);
    }
    printList(&tempList);

    printf("Create a linked list using the sorted data._End\n");

    /*
        김태은
        Sort the data in the array in age group order (using selection sort)
    */
    printf("================================\n");
    printf("배열 나이대 그룹화 파일생성_Start\n");
    ageGroup_sort(info);
    printf("배열 나이대 그룹화 파일생성_End\n");

    /*
        202033762 장민호
        All “Choi”s canceled registration. Remove the data from the linked list
    */
    printf("================================\n");
    printf("All 'Choi's canceled registration. Remove the data from in the linked list_Start\n");
    list_delete_firstName(&pList, "Choi");
    printList(&pList);

    printf("All 'Choi's canceled registration. Remove the data from in the linked list_End\n");

    /*
        202033762 장민호
        One “Paik” registered late. Add the data to in the linked list
    */
    printf("================================\n");
    printf("One “Paik” registered late. Add the data to in the linked list_Start\n");
    PersonInfo newData = {41, 2020, 06, 04, "yes", "Bobby Anderson", 45, "McGill University", "engineer"};

    list_add(&pList, newData);
    printList(&pList);

    printf("One “Paik” registered late. Add the data to in the linked list_End\n");

    /*
        이상윤
        Write the sorted data to a text file.
    */

    // 지정된 경로파일에 저장 -구조체 배열로 만들었을 때
    fileWrite_array(info);

    // 지정된 경로파일에 저장 -링크드리스트로 만들었을 때
    fileWrite_linkedList(&pList);

    return 0;
}
