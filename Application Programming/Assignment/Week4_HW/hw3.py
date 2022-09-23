# 줄 바꿈 없이 숫자 옆에 별표 출력하기 

timer = int(input("Countdown timer: How many seconds?"))

for x in range(timer, 0, -1):
    print(x, end='')
    for y in range(x):
        print("*", end='')
    print()

print("BLAST OFF!")
        
    