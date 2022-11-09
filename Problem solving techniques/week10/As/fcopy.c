#include <stdio.h>

#define SIZE 50
#define ERROR 1

int main()
{
    int buffer[SIZE];
    int i;
    int count;

    FILE *originFile = NULL;
    FILE *copiedFile = NULL;

    char originFileName[SIZE];
    char copiedFileName[SIZE];

    printf("원본 파일 이름: ");
    scanf("%s", originFileName);

    printf("복사 파일 이름: ");
    scanf("%s", copiedFileName);

    originFile = fopen(originFileName, "rb");
    if (originFile == NULL)
    {
        fprintf(stderr, "원본 파일을 열 수 없습니다.");
        return ERROR;
    }

    copiedFile = fopen(copiedFileName, "wb");
    if (copiedFile == NULL)
    {
        fprintf(stderr, "사본 파일을 열 수 없습니다.");
        return ERROR;
    }

    while ((count = fread(buffer, sizeof(char), SIZE, originFile)) != 0)
    {
        fwrite(buffer, sizeof(char), count, copiedFile);
    }

    fclose(originFile);
    fclose(copiedFile);

    printf("파일 복사 완료");

    return 0;
}