# Homework 1-BMI 계산하기
# 202033762 장민호

weight = float(input("몸무게를 kg단위로 입력하시오: "))
height = float(input("키를 m단위로 입력하시오: "))
BMI = weight / pow(height, 2)
print("당신의 BMI는 %.2f입니다."%BMI)