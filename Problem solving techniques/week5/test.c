#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *ShowArrChar(char ar[], char ar2[])
{
    return strcat(ar2, ar);
}

int main()
{
    char arr1[20];
    char arr2[20];

    int size = 13;
    //  scanf("%d", &size);
    char *arr3 = (char *)malloc(sizeof(char) * size);

    printf("size of arr3 = %d\n", sizeof(arr3) / sizeof(char));

    getchar();

    printf("size of arr1 = %d\n", sizeof(arr1) / sizeof(char));

    printf("Enter first string\n");
    gets(arr1);

    printf("size of arr1 = %d\n", strlen(arr1));

    printf("Enter second string\n");
    gets(arr2);

    // printf("arr1 = %s\n", arr1);
    // printf("arr2 = %s\n", arr2);

    char result[30];
    strcpy(result, ShowArrChar(arr1, arr2));
    printf("result = %s", result);

    return 0;
}