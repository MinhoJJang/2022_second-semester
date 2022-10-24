#include <stdio.h>
#include <string.h>

/*
문제해결기법 5주차 과제
202033762 장민호
type 1.

 수업시간에 공지한대로 도서관리 시스템에 필요한 BookStore 구조체를 정의하여 값을 연산 및 출력한다.

  조건 : 저자는 Person이라는 구조체를 만들어 BookStore 내에서 선언하여 사용한다.

            예제는 5개 이상의 자료를 입력하여 데이터를 연산 및 출력한다.
*/

typedef struct _person
{
    char name[10];
    int birthYear;
    char address[100];
} Person;

typedef struct _book
{
    char bookName[30];
    char publisher[30];
    Person *author;
} BookStore;

void setPerson(Person *person, char *name, int birthYear, char *address)
{
    strcpy(person->address, address);
    strcpy(person->name, name);
    person->birthYear = birthYear;
}

void setBook(BookStore *book, char *bookName, char *publisher, Person *author)
{
    strcpy(book->bookName, bookName);
    strcpy(book->publisher, publisher);
    book->author = author;
}

void getBook(BookStore *book)
{
    printf(" - Book Info - \n bookName: %s publisher: %s\n", book->bookName, book->publisher);
    printf(" - Author Info - \n author_name: %s, author_birthYear: %d, author_address: %s\n", book->author->name, book->author->birthYear, book->author->address);
}

int main()
{
    Person author[5];
    BookStore book[5];

    setPerson(&author[0], "Jiseok", 1983, "247 Cabot Street Holyoke MA 01040-3927 USA");
    setPerson(&author[1], "Hyorim", 1989, "594 Route 216 Stormville NY 12582-0010 USA");
    setPerson(&author[2], "Suwon", 1981, "4081 E Olive Rd Ste B Pensacola FL 32514 USA");
    setPerson(&author[3], "Minseok", 1979, "517 Ash Street Scranton PA 18509-2903 USA");
    setPerson(&author[4], "Eian", 1992, "9022 South US Highway 1 Port Saint Lucie FL 34952 USA");

    setBook(&book[0], "Destiny Guardians", "Bisang Publisher", &author[0]);
    setBook(&book[1], "King Of Dawn", "Codin Publisher", &author[1]);
    setBook(&book[2], "Squid Game", "Zofia Publisher", &author[2]);
    setBook(&book[3], "The Forest", "ABC Publisher", &author[3]);
    setBook(&book[4], "Freddy's pizza store", "Uzone Publisher", &author[4]);

    for (int i = 0; i < 5; i++)
    {
        getBook(&book[i]);
        printf("\n");
        }

    return 0;
}
