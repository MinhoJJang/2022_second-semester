# 과제 1(슬라이드 42) 
# 스스로 해보기 1: 원의 면적을 구하는 circleA() 함수와 원의둘레를 구하는 circleC() 함수가 포함된 Circle 클래스를 완성하세요. (제출 파일명: hw10-1.py)

# 둘레: 2ㅠr 넓이: ㅠr^2

import math

class Circle:
    def circleA(self, r):
        return 2*math.pi*r
    
    def circleC(self, r):
        return math.pi*pow(r,2)

c1 = Circle()

r = int(input("반지름을 입력하세요: "))

circumference = round(c1.circleA(r), 2)
area = (round(c1.circleC(r), 2))

print('원의 면적은 %s, 원의 둘레는 %s 입니다.'%(area, circumference))
