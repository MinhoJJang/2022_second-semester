# BMI로 비만도 측정하기
 

from telnetlib import BM


def distinct(BMI):
    if(BMI < 18.5):
        return "마름"
    elif(BMI >= 18.5 and BMI < 25):
        return "보통"
    elif(BMI >= 25 and BMI < 30):
        return "가벼운 비만"
    elif(BMI > 30):
        return "심한 비만"
    
weight = float(input("체중(kg)을 입력하시오:"))
height = float(input("키(cm)를 입력하시오:"))/100

BMI = weight / height**2

print("### 당신의 BMI는 %.2f입니다." %(BMI))
print("### Result: 당신은 %s입니다." %distinct(BMI))
