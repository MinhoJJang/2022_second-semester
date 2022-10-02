# (슬라이드 54-55) Homework 2: 짝수, 홀수 리스트 만들기 프로그램을 완성하세요.(oddeven.py) 

number = [4, 13, 15, 70, 51, 23, 38, 9, 12, 5]
odd = []
even = []

for i in number:
    if(i % 2 == 0):
        even.append(i)
    else:
        odd.append(i)
        
even.sort()
odd.sort()

print("짝수 리스트 = " , even)
print("홀수 리스트 = " , odd)