sentence = ""
words = []
dic = []

print("문장의 단어를 등록합니다(종료는 0입력).")

while True :
    sentence = input("문장 입력 : ")
    if sentence == '0':
        break
    else :
        words = sentence.split(' ')
        l = len(words)
        
        for i in range(l):
            if words[i] not in dic:
                dic.append(words[i])
    
    
dic.sort()
for i in dic:
    print(i)
    
        