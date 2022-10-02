# 응용프로그래밍 5주차

## list

파이썬의 리스트에는 데이터타입이 정해져 있지 않다.

```py
listname = [10, 20, 'john', 36.2, True, 'john']
```

즉, 이러한 리스트가 가능하다는 의미이다.

## major methods

```py
append()
insert()
len(list)
remove()
del list[i]
pop()
clear()
리스트 병합 '+'
리스트 요소 반복 '*'
max()
min()
sum()
```

```py
# 리스트 주요 메서드
>>> name = [1,2,3]

>>> name.append(4)
>>> name
[1, 2, 3, 4]

>>> name.insert(2,10)
>>> name
[1, 2, 10, 3, 4]

>>> name[2]
10

>>> len(name)
5

>>> name.remove(3)
>>> name
[1, 2, 10, 4]

>>> del name[2]
>>> name
[1, 2, 4]

>>> name.pop()
4
>>> name
[1, 2]

>>> name.clear()
>>> name
[]

# 리스트 연산 +, *

>>> name = [1,2,3]
>>> name1 = [4,5,6]
>>> newname = name+name1
>>> newname
[1, 2, 3, 4, 5, 6]
>>> multiname = name*2
>>> multiname
[1, 2, 3, 1, 2, 3]
```

## list slicing

기본 문법은 다음과 같다.

```py
문자열[a:b:c]
a : 시작
b : 끝(포함하지않음)
c : 간격
```

```py
>>> bucketList = ['김가천', 22, '서울', '속초', '부산', '제주']

# 3번째 인덱스부터 5번째 인덱스까지
>>> bucketList[3:6]
['속초', '부산', '제주']

# 3번째 인덱스부터 마지막 인덱스까지
>>> bucketList[3:]
['속초', '부산', '제주']

# 0번째 인덱스부터 2번째 인덱스까지
>>> bucketList[:3]
['김가천', 22, '서울']

# 음수 인덱싱

# 뒤에서 첫번째
>>> bucketList[-1]
'제주'

# 뒤에서 세번째
>>> bucketList[-3]
'속초'
```

## string slicing

```py
>>> a = "Life is too short, you need python"
>>> a[0:4]
'Life'
>>> a[-6:]
'python'
>>> a[-6:-1]
'pytho'
>>> a[-6:0]
''
>>> a[-6:len(a)]
'python'
>>> len(a)
34
>>> a[-6:32]
'pyth'
```

## list methods2

```py
index()
in
count()
sort()
reverse()
```

```py
>>> goodPlace = ['a', 'b', 'c']
>>> goodPlace.index(a)
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
NameError: name 'a' is not defined
>>> goodPlace.index('a')
0

>>> a in goodPlace
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
NameError: name 'a' is not defined
>>> 'b' in goodPlace
True
>>> 'd' in goodPlace
False


>>> goodPlace.append('d')
>>> goodPlace.append('b')
>>> goodPlace
['a', 'b', 'c', 'd', 'b']
>>> goodPlace.count('b')
2

>>> goodPlace.sort()
>>> goodPlace
['a', 'b', 'b', 'c', 'd']

>>> goodPlace.reverse()
>>> goodPlace
['d', 'c', 'b', 'b', 'a']
>>>
```

## split()

문자열을 자를때 split 함수를 사용하여 리스트로 만들 수 있다.

`split([separator], [max])`

```py
>>> quiz = 'python.program.good'

>>> sp = quiz.split()
>>> sp
['python.program.good']
>>> sp = quiz.split(' ')
>>> sp
['python.program.good']
>>> sp[0]
'python.program.good'

>>> sp = quiz.split('.')
>>> sp
['python', 'program', 'good']
>>> sp[1]
'program'
>>> sp = quiz.split('.', 1)
>>> sp
['python', 'program.good']
>>> sp = quiz.split('.', 2)
>>> sp
['python', 'program', 'good']

>>> quiz = 'python program good'
>>> sp = quiz.split()
>>> sp
['python', 'program', 'good']
```

리스트에는 split를 사용할 수 없다. 리스트의 요소가 ',', '/'등으로 구분되어 있다면, 리스트의 요소에다가 split을 사용하여 새 리스트를 만들 수 있다.

> > > bucketList = ['부산,제주,속초,대전']
> > > bucketList
> > > ['부산,제주,속초,대전']
> > > bucketList[0]
> > > '부산,제주,속초,대전'
> > > sp2 = bucketList[0].split(',')
> > > sp2
> > > ['부산', '제주', '속초', '대전']

## join()

구분자를 사용자가 추가하여, 리스트 내의 요소들을 구분자로 합쳐 문자열로 만든다.

`','.join( 리스트이름 )`

```py
>>> sp = ['python', 'program', 'good']
>>> sp2 = ['부산', '제주', '속초', '대전']
>>> quiz = '&'.join(sp)
>>> quiz
'python&program&good'
>>> bucketList = '/'.join(sp2)
>>> bucketList
'부산/제주/속초/대전'
>>> '@@ '.join('abcd')
'a@@ b@@ c@@ d'
```

## enumerate()

```py
for i, value in enumerate(시퀀스 자료형 이름, [sequence]):
    print(i, value)

# [sequence]는 인덱스 시작 번호 지정, 생략하면 기본값은 0.
```

```py
bucketList = ['부산', '제주', '속초', '대전']

for i, value in enumerate(bucketList):
    print(i, value)

print()

for i, value in enumerate(bucketList,2):
    print(i, value)

0 부산
1 제주
2 속초
3 대전

2 부산
3 제주
4 속초
5 대전
```
