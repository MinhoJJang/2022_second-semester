/*
202033762 장민호
문제해결기법 6주차 과제 LEVEL 2+

    지갑 프로그램.

    동전 혹은 지폐를 넣고 빼는 작업을 수행한다. wallet이라는 구조체를 만들고, 그 구조체에 500원 동전, 1000원 지폐를 넣고 꺼내는 함수를 만든다. 이때 동전 혹은 지폐를 꺼낼 때 잔액이 부족하면 꺼낼 수 없도록 만들었다.

    간단하게 만들 수 있어서 큰 어려움 없이 작성할 수 있었다. call by reference는 구조체 포인터를 사용해 같은 지갑에 돈을 넣고 뺄 수 있도록 하였고, 동전 개수 등은 call by value를 통해 함수를 작동시켰다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0

// 지갑의 데이터

typedef struct _wallet
{
    int coin500;  // 500원짜리 동전 개수
    int bill1000; // 1000원짜리 지폐 개수
} Wallet;

// 지갑의 동작
void wlt_init(Wallet *p);                  // 지갑의 초기화
void wlt_put_coin(Wallet *p, int coinNum); // 동전 삽입
int wlt_take_coin(Wallet *p, int coinNum); // 동전 추출
void wlt_put_bill(Wallet *p, int billNum); // 지폐 삽입
int wlt_take_bill(Wallet *p, int billNum); // 지폐 추출
int wlt_balance(Wallet *p);                // 지갑내 잔액 확인

void wlt_init(Wallet *p)
{
    printf("지갑을 초기화 합니다\n");
    p->bill1000 = 0;
    p->coin500 = 0;
} // 지갑의 초기화

void wlt_put_coin(Wallet *p, int coinNum)
{
    p->coin500 += coinNum;
    printf("동전 %d 개 삽입되어 %d개가 되었습니다.\n", coinNum, p->coin500);
} // 동전 삽입

int wlt_take_coin(Wallet *p, int coinNum)
{
    if (p->coin500 < coinNum)
    {
        printf("동전개수가 부족하여 %d 개를 추출할 수 없습니다\n", coinNum);
        return FAIL;
    }

    p->coin500 -= coinNum;
    printf("동전 %d 개 추출되어 %d 개가 되었습니다\n", coinNum, p->coin500);
    return SUCCESS;
} // 동전 추출

void wlt_put_bill(Wallet *p, int billNum)
{
    p->bill1000 += billNum;
    printf("지폐 %d 개 삽입되어 %d개가 되었습니다.\n", billNum, p->bill1000);
} // 지폐 삽입

int wlt_take_bill(Wallet *p, int billNum)
{
    if (p->bill1000 < billNum)
    {
        printf("지폐개수가 부족하여 %d 개를 추출할 수 없습니다\n", billNum);
        return FAIL;
    }

    p->bill1000 -= billNum;
    printf("지폐 %d 개 추출되어 %d 개가 되었습니다\n", billNum, p->bill1000);
    return SUCCESS;

} // 지폐 추출

int wlt_balance(Wallet *p)
{
    return p->coin500 * 500 + p->bill1000 * 1000;
} // 지갑내 잔액 확인

int main()
{
    Wallet myWallet; // 지갑 생성

    wlt_init(&myWallet); // 지갑 초기화
    // p = &myWallet
    wlt_put_coin(&myWallet, 2);                    // 동전삽입: 500 x 2개
    wlt_put_bill(&myWallet, 3);                    // 지폐삽입 : 1000원 x 1개
    printf("잔액 : %d\n", wlt_balance(&myWallet)); // 2000원

    wlt_put_coin(&myWallet, 3);                    // 동전삽입: 500 x 2개
    wlt_put_bill(&myWallet, 4);                    // 지폐삽입 : 1000원 x 1개
    printf("잔액 : %d\n", wlt_balance(&myWallet)); // 7500원

    wlt_take_coin(&myWallet, 4);                   // 동전 추출
    wlt_take_bill(&myWallet, 2);                   // 지폐 추출
    printf("잔액 : %d\n", wlt_balance(&myWallet)); // 잔액 3500원

    wlt_take_coin(&myWallet, 1);  // 추출 성공, 잔액 3000원
    wlt_take_bill(&myWallet, 10); // 추출 실패
    printf("잔액 : %d\n", wlt_balance(&myWallet));

    return 0;
}