# - 과제 2(슬라이드 58)
# 스스로 해보기 2: random 모듈을 이용하여 1~100사이 난수로 무작위 숫자 두 개를 골라 덧셈 문제를 출제하는 프로그램을 완성하세요. (제출파일명: hw10-2.py)

import random as ran

num1 = ran.randint(1, 100) 
num2 = ran.randint(1, 100) 

print('{0} + {1} = ?'.format(num1, num2))
ans = int(input())

if(ans == num1+num2):
    print("정답입니다")
else:
    print("틀렸습니다")

