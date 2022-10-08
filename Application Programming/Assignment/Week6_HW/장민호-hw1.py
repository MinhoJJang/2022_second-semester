# 응용프로그래밍 6주차 과제 
# 202033762 장민호
# ‘빈 리스트(list) 두 개’를 만들고, ‘사용자로부터 요소를 입력’받아 ‘딕셔너리로 변환’하는 코드를 작성하시오.

name = []
score = []

while True:
    name.append(input("이름을 입력하시오: "))
    score.append(input("점수를 입력하시오: "))
    
    if(name[len(name)-1] == '' and score[len(score)-1] == '') :
        break

result = dict(zip(name, score))
result.popitem()
print(result)