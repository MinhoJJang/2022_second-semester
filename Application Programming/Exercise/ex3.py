books = { 'q':1000,'w':10400,'e':106600,'r':100013,'t':32100}

print("검색 가능 도서 : ", books.keys())

print('-' * 35)

while True:
    bookName = input("도서명 입력(검색 종료는 0) : ")
    
    if(bookName == '0'):
        print("프로그램을 종료합니다")
        break
    elif bookName in books.keys():
        print("{0} = {1} 원".format(bookName, books.get(bookName)))
    else :
        print("검색 가능한 도서가 아닙니다.")