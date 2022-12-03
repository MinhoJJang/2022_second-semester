x = int(input("첫 번째 정수 입력 : "))
y = int(input("두 번째 정수 입력 : "))

def sum_xy(x,y):
    sum = 0
    for i in range(y-x+1):
        sum += (i+x)  
    return sum

print(sum_xy(x, y))