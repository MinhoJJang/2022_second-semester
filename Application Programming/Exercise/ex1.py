menu = 0
bucket = []

def printList(list):
    print("*" * 30)
    
    for x in list:
        print(x)
    
    print("*" * 30)

while True:
    menu = int(input("메뉴 선택(1.추가 2.삭제 0.종료) : "))
    
    if(menu == 0): 
        print("프로그램을 종료합니다")
        break
    elif(menu == 1):
        str = input("추가할 내용: ")
        bucket.append(str)
        printList(bucket)
    elif(menu == 2):
        str = input("삭제할 내용: ")
        bucket.remove(str)
        printList(bucket)
    else:
        print("메뉴 선택 오류입니다. 다시 선택하세요")
        
    
        