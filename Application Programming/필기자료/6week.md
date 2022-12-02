# Dictionary, tuple

## Dictionary

- key: value 쌍의 집합을 Dictionary 라고 한다.
- 하나의 key에 하나의 value가 대응되어야 한다.
- value로는 모든 데이터 유형이 가능하다.
- key로는 리스트와 딕셔너리를 제외하고 모든 데이터 유형이 가능하다.
- 만약 key 값이 중복될 경우, 나중에 들어온 값을 사용한다.
- 중괄호 `{ }` 를 이용해 정의된다.

### value 가져오기

```py
>>> mydict = { 'name': 'Kim',
'year': 1999 }
>>> mydict ['name']
'Kim'
>>> mydict ['year']
1999
```

### get()

`dictionary . get( keyname, value )`

- 지정한 keyname에 해당되는 value를 반환한다.
- 만약 지정한 keyname이 없을 경우, get() 내부에서 지정한 value가 대신 출력된다.
- 만약 지정한 keyname이 존재할 경우, get() 내부에서 지정한 value는 무시되고 딕셔너리 내부의 value 값이 리턴된다.
- value 값은 반드시 필요하지는 않다.
- 딕셔너리 내부에 데이터를 삽입하는 것은 아니다!

```py
>>> mydict = {'name': 'Kim', 'year': 1999}
>>> mydict.get('name')
# mydict[‘name’] 과 동일한 결과
'Kim'
>>> mydict.get('namw’)
아무 것도 출력되지 않음
>>> mydict.get('namw', 'The name is not in the dictionary.')
'The name is not in the dictionary.’

###

mydict = {'name': 'Kim', 'year': 1999, '(name, year)': ('kim', 123)}
print(mydict['(name, year)'])
print(mydict.get('(name, year)', 'value'))

# 두 코드 동일한 결과
('kim', 123)
('kim', 123)
```

### update()

`dictionary.update({key:value})`

- 딕셔너리에 key: value 쌍이 없는 경우 딕셔너리의 마지막 위치에 key:value 쌍을 추가한다.
- 만약 해당 key가 이미 딕셔너리에 존재할 경우, value값을 변경한다.

이를 조금 응용하면

```py
if(mydict.get('newkey') == None):
    mydict.update({'newkey': 'newvalue'})
    mydict.update({'year': 2000})

print(mydict.get('newkey'))
print(mydict.get('year'))

newvalue
2000
```

혹은 update를 사용하지 않고도 이렇게 값을 추가할 수도 있다.

```py
mydict['pluskey'] = 'plusvalue'
mydict['name'] = 'Jang'

{'name': 'Jang', 'year': 2000, '(name, year)': ('kim', 123), 'newkey': 'newvalue', 'pluskey': 'plusvalue'}
```

### popitem(), pop(), del, clear()

popitem()과 pop()의 차이는, popitem()은 전체 key: value를 리턴하고, pop()은 value만 리턴한다.

```py
print(mydict)
# 맨 뒤의 항목을 pop 하고 dictionary에서 제거
print(mydict.popitem())
print(mydict)

{'name': 'Kim', 'year': 2000, '(name, year)': ('kim', 123), 'newkey': 'newvalue'}
('newkey', 'newvalue')

# pop(): 제거할 키값에 해당하는 value값을 리턴하고 제거
print(mydict.pop('name'))
print(mydict)

Jang

# year 항목을 제거
del mydict['year']
print(mydict)

{'name': 'Kim', 'year': 2000, '(name, year)': ('kim', 123)}
{'name': 'Kim', '(name, year)': ('kim', 123)}

# 전체 딕셔너리 제거
mydict.clear()
print(mydict)

{}
```

### membership test, len()

- in 은 지정된 key 가 사전에 있는지 여부를 테스트한다. (membership test)
- len은 사전의 길이를 반환한다.

```py
>>> dictionary = { '한국': '서울', '베트남': '하노이', '일본': '도쿄'}
>>> '한국' in dictionary
True

# key 항목이 아닌 value 항목을 적으면 False가 반환된다.
>>> '서울' in dictionary
False

# 만약 value 값의 존재 여부를 확인하고 싶다면...?
>>> '서울' in dictionary.values()
True
# 이렇게 dictionary.values()를 통해 dictionary의 value list를 정의역으로 하여 구할 수 있다.

>>> len(dictionary)
3
```

### keys(), values(), items()

- keys(): 딕셔너리의 모든 키를 리스트 형태로 반환
- values(): 딕셔너리의 모든 값을 리스트 형태로 반환
- items(): 딕셔너리의 모든 키값 쌍을 튜플로 묶어 리스트 형태로 반환

```py
>>> dictionary.keys()
dict_keys(['한국', '베트남', '일본'])
>>> dictionary.values()
dict_values(['서울', '하노이', '도쿄'])
>>> dictionary.items()
dict_items([('한국', '서울'), ('베트남', '하노이'), ('일본', '도쿄')])

# 응용
capitaldict = {'한국': '서울', '베트남': '하노이', '일본': '도쿄'}
for x, y in capitaldict.items( ):
    print('{0}의 수도는 {1}입니다.' .format(x, y))
```

### 딕셔너리 수정하기

`x = {'a': 10, 'b': 20, 'c': 30, 'd': 40, 'e': 50}` 라는 딕셔너리에서, value값이 20일 경우 딕셔너리에서 삭제하는 코드를 만드려면 어떻게 해야 할까?

```py
# 불가능
for key, val in x.items():
    if(val == 20):
        del x[key]

RuntimeError: dictionary changed size during iteration
-> for문 내부에서 dict을 수정할 수는 없다

# 가능
keyMemory = []

for key, val in x.items():
    if(val == 20):
        keyMemory.append(key)

for i in keyMemory:
    del x[i]

print(x)
```

즉 for 문 내부에서 딕셔너리가 변경되면 안된다.

혹은 이런 표현식도 가능하다.

```py
x = {key: value for key, value in x.items( ) if value != 20}
print(x)
```

아예 딕셔너리를 다시 만드는 방법이다.

### dict(), zip()

- dict()는 딕셔너리를 생성한다.
- 리스트나 튜플을 딕셔너리로 변환할 수 있다.

> dict

```py
>>> li = [ ('name', 'Alice'), ('year',1999) ]
>>> info = dict(li)
>>> info
{'name': 'Alice', 'year': 1999}
>>> li = ( ('name', 'Alice'), ('year',1999) )
>>> info = dict(li)
>>> info
{'name': 'Alice', 'year': 1999}
```

> zip

서로 다른 리스트를 묶을 때 사용한다. 매치되는 값이 없을 경우 그냥 데이터 무시됨

```py
>>> title = ['name', 'age', 'birthday']
>>> value = ['Johnson', 20, '1998-04-15', 'test']
>>> info = dict(zip(title, value))
>>> info
{'name': 'Johnson', 'age': 20, 'birthday': '1998-04-15'}
# value의 3번째 index은 title과 매치하는 값이 없으므로 무시된다
```

---

## Tuple

- 튜플은 한번 생성되면 그 안의 내용을 수정할 수 없는 정렬된 집합.
- 튜플은 데이터들의 집합이고, 데이터의 타입은 그 무엇이 와도 상관없다.
- 튜플 내에 튜플이 존재할 수 있다.

```py
my_data = ("hi", "hello", "bye")
my_data2 = (1, 2.8, "Hello World")
my_data3 = ("Book", [1, 2, 3])
my_data4 = ((2, 3, 4), (1, 2, "hi"))
my_data5 = (99, )

# 만약 99뒤에 콤마(,) 가 없다면 my_data5는 정수형 변수로 취급된다.
my_data = (99, )
my_data1 = (99)

print(type(my_data))
print(type(my_data1))

<class 'tuple'>
<class 'int'>
```

- 튜플은 값을 변경할 수 없으므로 append나 remove 같은 메서드는 사용할 수 없다.
- 튜플은 기존 데이터를 DELETE, UPDATE 하지 않는 메서드만 사용 가능하다.

### index, slice, concatenation, repetition, Negative indexing, len, membership test

```py
my_data = ("hi", "hello", "bye")
my_data2 = (1, 2.8, "Hello World")
my_data3 = ("Book", [1, 2, 3])
my_data4 = ((2, 3, 4), (1, 2, "hi"))

print(my_data3[1])
[1, 2, 3]

print(my_data3[0][1:3])
oo

print(my_data4[1][1])
2

print(my_data4[1][1:])
(2, 'hi')

print(my_data + my_data2)
('hi', 'hello', 'bye', 1, 2.8, 'Hello World')

print(my_data*2)
('hi', 'hello', 'bye', 'hi', 'hello', 'bye')

print(my_data4[-2][0:1])
(2,)

print([1,2,3] in my_data3)
True

print([2] in my_data3)
False

print((2,3,4) in my_data4)
True

print(len(my_data4))
2
```

### zip()

```py
a = ("John", "Charles", "Mike")
b = ("Jenny", "Christy", "Monica", "Vicky")

x = zip (a, b)

# 쌍을 이루지 못하는 Vicky는 무시된다.
print(tuple(x))
(('John', 'Jenny'), ('Charles', 'Christy'), ('Mike', 'Monica'))

print(x)
<zip object at 0x7f0cd3f78a00>
```

### Unpacking

```py
my_data4 = ((2, 3, 4), (1, 2, "hi"))

q,w,e = my_data4[1]
print(q, w, e)

1 2 hi
```

### 응용) 튜플에 값 추가?

원래 튜플은 수정 불가한 객체이다. 그런데 만약 튜플에 값을 추가하거나 삭제하고 싶다면? 튜플을 리스트로 변경하고, 리스트에서 수정 작업을 수행한 뒤 튜플로 다시 변환시키면 가능하다.

```py
tu = (10, 20, 30)
li = list(tu)
li.append(40)
tu = tuple(li)
```
