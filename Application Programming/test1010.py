bookList = []

print("입력을 종료하려면 [Enter] 키를 누르세요")
print('='*30)

while(True):
    bookName = input("도서명 입력: ")
    if(bookName == ''):
        break
    else:
        bookList.append(bookName)

print('='*30)
bookList.sort()

for x in range(len(bookList)):
    print('{0} : {1} '.format(x+1, bookList[x]))

