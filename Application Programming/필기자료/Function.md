# Function

## 내장함수

## 외장함수

## 사용자 정의 함수

기타 내용들은 여느 언어의 함수와 다를 것이 없지만, 파이썬은 독특하게도 여러 개의 리턴값을 줄 수 있다. 여러개의 리턴값은 튜플로 생성되어 반환된다.

```py
def fun1(x,y,z):
    return x**2, y**2, z**2

print(fun1(1,2,3))
(1,4,9)
```

## 지역변수, 전역변수

변수의 활성화되는 범위는 처음 생성된 위치에 기반한다. 함수 내부에서 선언되면 지역변수, 밖에서 선언되면 전역변수이다.

## 기본 매개변수

신기하게도 파이썬에는 기본 매개변수가 존재한다. 매개변수를 지정해주지 않을 경우 default 값으로 사용자가 어떤 값을 지정해 줄 수 있다.

```py
>>> def default(c = 'korea'):
...     print("I'm from" + c)
...
>>> default()
I'm from korea

>>> default('usa')
I'm from usa
```

## 가변 매개변수 \*args, \*\*kwargs

매개변수의 개수가 일정치 않을 때도 사용 가능하다. 들어온 매개변수는 모두 튜플처럼 인식한다.

```py
def fn(*args):
    print(type(args))
    for i in range(len(args)):
      print(args[i])
    print()

>>> fn(1,2,3)
<class 'tuple'>
1
2
3

>>> fn(10)
<class 'tuple'>
10

>>> fn(100,'hi','python!')
<class 'tuple'>
100
hi
python!
```

만약 매개변수가 dict 형태를 띄고 있어도 가능하다. \*args와 마찬가지로 가변적으로 인수 처리가 가능하다. 대신 그 인수는 반드시 dict형태 (key = value) 여야 한다. key값은 숫자는 불가능하다.

<중요!>
딕셔너리를 만들 때는 :를 사용하지만 인수로 전달할 때는 =을 사용한다.

```py
def fn(**kwargs):
    print(type(kwargs))
    for x,y in kwargs.items():
        print('{0} = {1}'.format(x,y))
    print()

fn(a=1, b=2, c=3)
<class 'dict'>
a = 1
b = 2
c = 3

fn(a1='qw123')
<class 'dict'>
a1 = qw123

dict = {'a' : 'jang' ,'b' : 'min' ,'c' : 'ho'}
fn(dict)
```

## Unpacking - function(\*tupleName) & funtion(\*\*dictionaryName)

리스트, 딕셔너리, 튜플 내부의 데이터를 다룰 때 꺼내서 사용하는 경우가 생길 수 있다. 어떻게 하는지 알아보자.

1. 리스트 언패킹 & 튜플 언패킹

```py
def unpacking(a,b,c):
    print(a, b, c)

list = [1,2,3]
unpacking(*list)

tuple = (1,2,3)
unpacking(*tuple)
```

2. 딕셔너리 언패킹

```py
def unpacking(a,b,c):
    print(a, b, c)

dict = {'a' : 'jang' ,'b' : 'min' ,'c' : 'ho'}
unpacking(**dict)

a에 dict의 a에 해당하는 value 값이 매핑됨.
```

만약 인수의 개수를 모른다면? dictionary 언패킹은 어떻게 할까?

```py
dict = {'a' : 'jang' ,'b' : 'min' ,'c' : 'ho', 'd' : 'yeah'}

def unpack(**kwargs):
    for x in kwargs.values():
        print(x)

unpack(**dict)
```

그러니까 언패킹이란건 매개변수 자체를 list, tuple, dictionary 타입으로 받는 것이고, 가변 매개인수는 함수 인자에 직접 인수를 적어야 한다.

아래 예시를 비교하면 이해가 쉽다.

```py
def fn(**kwargs):
    print(type(kwargs))
    for x,y in kwargs.items():
        print('{0} = {1}'.format(x,y))
    print()

fn(a=1, b=2, c=3)
-> 직접 매개변수 입력
<class 'dict'>
a = 1
b = 2
c = 3
```

```py
dict = {'a' : 'jang' ,'b' : 'min' ,'c' : 'ho', 'd' : 'yeah'}

def unpack(**kwargs):
    for x in kwargs.values():
        print(x)

unpack(**dict)
-> 매개변수에 dict 전달
```
