#include <stdio.h>
#include <string.h>

// 도서관리 시스템에 필요한 구조체를 만들어 2개의 데이터를 출력한다.
// 저자는 person 구조체를 만들어 사용해라. /이름, 출생년도, 주소

typedef struct _person
{
    char name[30];
    int birthYear;
    char address[30];
} Person;

typedef struct _book
{
    char bookName[30];
    char publisher[30];
    Person *author;
} Book;

void setPerson(Person *person, char *name, int birthYear, char *address)
{
    strcpy(person->address, address);
    strcpy(person->name, name);
    person->birthYear = birthYear;
}

void setBook(Book *book, char *bookName, char *publisher, Person *author)
{
    strcpy(book->bookName, bookName);
    strcpy(book->publisher, publisher);
    book->author = author;
}

void getBook(Book *book)
{
    printf(" - Book Info - \n bookName: %s publisher: %s\n", book->bookName, book->publisher);
    printf(" - Author Info - \n author_name: %s, author_birthYear: %d, author_address: %s\n", book->author->name, book->author->birthYear, book->author->address);
}

int main()
{
    Person author1;
    Person author2;
    Book book1;
    Book book2;

    setPerson(&author1, "Bentz", 1983, "10244-584 ADS street");
    setPerson(&author2, "Hyorim", 1989, "48211-295 TNA street");

    setBook(&book1, "HowToGetPerson's Mind?", "Bisang Publisher", &author2);
    getBook(&book1);

    return 0;
}
