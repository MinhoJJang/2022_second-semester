/*
Homework (30 points)

Textbook Chapter 7.3
Programming Exercises 2, 3a and 3b
Must follow the problem solving steps (including
the drawing of memory diagrams).

Chapter 7.3 Exercises

2. Write a C function named change() that accepts a single-precision number and the addresses of the integer variables named quarters, dimes, nickels, and pennies. The function should determine the number of quarters, dimes, nickels, and pennies in the number passed to it and write these values directly into the respective variables declared in its calling function.

3a. Write a function named secs() that accepts the time in hours,minutes, and seconds; and determines the total number of seconds in the passed data. Write this function so that the total number of seconds is returned by the function as an integer number.

3b. Repeat Exercise 3a but also pass the address of the variable totSec to the function secs(). Using this passed address, have secs() directly alter the value of totSec .
*/

/*
    문제해결기법 4주차 과제
    Chapter 7.3
    Exercise 2, 3a, 3b

    202033762 장민호

    1. 문제설명
     - Exercise 2.
        change() 라는 함수를 만든다. 해당 함수는 임의의 integer 타입 숫자 하나와, integer 타입 변수 quarters, dimes, nickels, pennies 들의 주소를 각각 받는다. change() 함수는 임의의 주어진 숫자를 cent로 가정하여 quarters, dimes, nickels, pennies로 변환한다. 이때, 함수를 호출하면 주소값에다 바로 값을 초기화하도록 한다.
     - Exercise 3a.
        secs() 라는 함수를 만든다. 해당 함수는 hours, minutes, seconds를 인자로 받고, 그 시간을 seconds로 변환하여 int 타입으로 리턴해준다.
     - Exercise 3b.
        3a와 동일한 문제인데, totSec라는 변수를 추가 선언하고, secs()함수에서 int값을 리턴하는 방식이 아니라 totSec의 주소값을 추가 인자로 받은 뒤 totSec에 바로 총 seconds를 입력하여 풀이한다.

    2. 작성후기

        세 문제 모두 Call by reference를 활용하는 법에 대하여 잘 이해할 수 있는 문제였다. 특히 3a, 3b를 통해 Call by value와 Call by reference 간의 차이점에 대해 코드로 느낄 수 있는 경험이 되었다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void change(int cents, int *quarters, int *dimes, int *nickels, int *pennies)
{
    *quarters = 25 * cents;
    *dimes = 10 * cents;
    *nickels = 5 * cents;
    *pennies = cents;
}

int secs_3a(int hours, int minutes, int seconds)
{
    int totalSec = 0;
    totalSec += hours * 3600;
    totalSec += minutes * 60;
    totalSec += seconds;

    return totalSec;
}

void secs_3b(int *hours, int *minutes, int *seconds, int *totSec)
{
    *totSec += *hours * 3600;
    *totSec += *minutes * 60;
    *totSec += *seconds;
}

int main()
{
    // Exercise 2
    int cents = 10;
    int quarters, dimes, nickels, pennies;

    change(cents, &quarters, &dimes, &nickels, &pennies);

    printf("%d cents = %d quarters\n", cents, quarters);
    printf("%d cents = %d dimes\n", cents, dimes);
    printf("%d cents = %d nickels\n", cents, nickels);
    printf("%d cents = %d pennies\n", cents, pennies);

    printf("==========================\n");

    // Exercise 3a
    int hours = 5;
    int minutes = 37;
    int seconds = 19;

    printf("%d hour %d minutes %d seconds \ntotal seconds = %d seconds\n", hours, minutes, seconds, secs_3a(hours, minutes, seconds));

    printf("==========================\n");

    // Exercise 3b
    int totSec = 0;
    secs_3b(&hours, &minutes, &seconds, &totSec);
    printf("%d hour %d minutes %d seconds \ntotal seconds = %d seconds\n", hours, minutes, seconds, totSec);

    return 0;
}