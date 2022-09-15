# -(슬라이드 27) Homework 1: 사용자로부터 3개의 정수를 입력 받아 가장 큰 수를 출력하세요.(hw1.py)

num1 = int(input("첫번째 정수를 입력하세요: "))
num2 = int(input("두번째 정수를 입력하세요: "))
num3 = int(input("세번째 정수를 입력하세요: "))

biggestNumber = num1
if biggestNumber < num2 :
    biggestNumber = num2

if biggestNumber < num3 :
    biggestNumber = num3
    
print("%d, %d, %d 중 가장 큰 수는 %d이다." %(num1, num2, num3, biggestNumber))