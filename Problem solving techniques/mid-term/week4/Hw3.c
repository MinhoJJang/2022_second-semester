/*
Homework (20 points)

Textbook Chapter 8.3
Programming Exercises 2 and 4
Must follow the problem solving steps (including
the drawing of memory diagrams).

2. Write a program that has a declaration in main() to store the following numbers into an array named rates : 6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0. There should be a function call to show() that accepts the rates array as a parameter named rates and then displays the numbers in the array.

4. Write a program that declares three one-dimensional arrays named price, quantity, and amount. Each array should be declared in main() and should be capable of holding 10 double-precision numbers. The numbers that should be stored in price are 10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98. The numbers that should be stored in quantity are 4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8. Your program should pass these three arrays to a function called extend(), which should calculate the elements in the amount array as the product of the equivalent elements in the price and quantity arrays (for example, amount[1] = price[1] * quantity[1]). After extend() has put values in the amount array, the values in the array should be displayed from within main().
*/

/*
    문제해결기법 4주차 과제
    Chapter 8.3
    Exercise 2, 4

    202033762 장민호

    1. 문제설명
     - Exercise 2.
        rates라는 이름의 배열을 main 함수 내부에 선언하고, 해당 배열에 주어진 숫자들을 넣어 초기화 한다. 이후, rates 배열을 인자값으로 갖는 show() 라는 함수를 만든다. show() 함수는 인자값으로 받은 배열 내부에 있는 숫자들을 나열하여 보여주면 된다.
     - Exersice 4.
        3개의 1차원 배열을 선언한다. 각 배열의 이름은 price, quantity, 그리고 amount 이다. 각 배열은 main 함수 내부에서 선언되어야 하며 10개의 double 타입 숫자들을 받을 수 있도록 해야 한다. price와 quantity 배열에는 주어진 일련의 숫자들을 넣어 초기화 시키면 된다. 내가 할 일은 extend()라는 함수를 만드는 것인데, 그 함수는 세 개의 배열을 인자값으로 받아야 한다. 함수 내부에서는 amount[1] = price[1] * quantity[1] 과 같은 연산을 수행하여 amount 배열에 데이터를 입력한다. extend() 함수가 amount 배열에 데이터를 다 넣었으면 해당 데이터를 main 함수 내부에서 출력하도록 한다.

    2. 작성후기

        문제가 단순하여 해결에 큰 어려움이 없었다. 이 문제에서 중요한 점은 배열의 이름은 포인터이므로, 함수에서 배열을 받을 때에는 포인터로 받아도 된다는 것이며 실제로 Exercise 4에서 해당 방식으로 문제를 해결하였다.
*/

#include <stdio.h>
#include <malloc.h>

#define MAX 10

// Exercise 2
void show(float rates[])
{
    for (int i = 0; i < 9; i++)
    {
        printf("rates[%d] = %.1f\n", i, rates[i]);
    }
}

// Exercise 4
void extend(double *price, double *quantity, double *amount)
{
    for (int i = 0; i < MAX; i++)
    {
        amount[i] = price[i] * quantity[i];
    }
}

int main()
{
    printf("========== Exercise 2 ==========\n");
    // ====== Exercise 2 Strat ======
    float rates[9] = {6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0};
    show(rates);
    // ====== Exercise 2 End ======

    printf("========== Exercise 4 ==========\n");

    // ====== Exercise 4 Start ======

    double price[MAX] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
    double quantity[MAX] = {4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8};
    double amount[MAX];

    extend(price, quantity, amount);

    for (int i = 0; i < MAX; i++)
    {
        printf("amount[%d] = %.2lf\n", i, amount[i]);
    }

    // ====== Exercise 4 End ======

    return 0;
}