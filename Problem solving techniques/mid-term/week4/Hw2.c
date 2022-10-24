/*
Textbook Chapter 9.4

Programming Exercise #2
Write a C function named liquid() that is to accept an integer number and the addresses of the variables gallons, quarts, pints, and cups. The passed integer represents the total number of cups, and the function is to determine the number of gallons, quarts, pints, and cups in the passed value. Using the passed addresses, the
function should directly alter the respective variables in the calling function. Use the relationships of 2 cups to a pint, 4 cups to a quart, and 16 cups to a gallon.
*/

/*
    문제해결기법 4주차 과제
    Chapter 9.4
    Exercise 2

    202033762 장민호

    1. 문제설명
     - Exercise 2.
        liquid() 라는 함수를 만든다. 해당 함수는 총 5개의 인자를 갖는데, 하나는 int 타입 변수이며 나머지 4개는 gallons, quarts, pints, cups 변수의 주소값이다. int 타입 변수는 cup의 총 개수를 뜻하며 liquid 함수는 cup의 총 개수를 각각 몇 gallon, quart, pint, cup 인지 변환하면 된다. 이때 계산 시 주어진 주소값을 이용해 즉시 값을 반영하도록 한다. 16 cups = 1 gallon, 4 cups = 1 quart, 2 cups = 1 pint 임을 활용하여 계산하자.

    2. 작성후기

        문제 해결에 큰 어려움은 없었다. 이 문제에서 중요한 점은 함수 인자로 주어진 cups 변수를 계산을 통해 포인터 변수에 즉시 계산된 값을 입력하는 것이다. 이는 함수 인자를 포인터 변수로 받게 되면 Call by reference 방식으로 변수를 호출하는 것이므로, 해당 변수의 값이 복사되어 오는 것이 아니라 해당 변수의 주소값이 인자로 오게 된다. 따라서 해당 주소값에 있는 값을 바꾸는 즉시 main에 있는 변수에도 값이 반영된다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void liquid(int cups, float *gallon, float *quart, float *pint, float *cup)
{
    *gallon = cups / 16.0;
    *quart = cups / 4.0;
    *pint = cups / 2.0;
    *cup = cups / 1.0;
}

int main()
{
    int cups;
    float gallon, quart, pint, cup;

    cups = 13;
    liquid(cups, &gallon, &quart, &pint, &cup);
    printf("The total number of cups: %d\n", cups);
    printf("%d cup = %.2f gallon\n", cups, gallon);
    printf("%d cup = %.2f quart\n", cups, quart);
    printf("%d cup = %.2f pint\n", cups, pint);
    printf("%d cup = %.2f cup\n", cups, cup);

    return 0;
}