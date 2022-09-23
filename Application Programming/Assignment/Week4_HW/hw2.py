# 구구단 출력하기

table = int(input("Which table would you like?"))
high = int(input("How high would you like it to go?"))

print("### Here's your table ###")

for x in range(1, high+1):
    print("%d X %d = %d" %(table, x, table*x))
    
    
