# Module

함수와 변수로 구성된 하나의 파일. 마치 자바의 class 나 C의 .h 같은 느낌이다. 그러니까 모듈은 누군가 만든 것을 불러와 사용할 수도 있고, 파이썬 자체에 내장된 모듈을 가져올 수도 있다.

대표적인 모듈로는 math, random이 있다.

```py
>>> import math

>>> math.pi
3.141592653589793

>>> factorial(5)
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
NameError: name 'factorial' is not defined

>>> math.factorial(5)
120

>>> import random
>>> random.random()
0.5301061487403709
```

근데 매번 모듈 이름 쓰기 귀찮으니 from 이라는 것도 제공해준다. 이러면 그냥 함수 이름만 써도 된다.

```py
from math import factorial

factorial(5)
120
```

같은 함수 이름을 쓰는 서로 다른 모듈을 가져온다면
이런 식으로 사용할 수도 있다.

```
import my, your
my.hello()
your.hello()
```

모듈이 뭐가 있는지 알고 싶다면

```py
help('modules')
```

해당 모듈 안에 무슨 함수가 있는지 알고싶다면

```py
dir('math')
```

import를 사용하는 방법 4가지

```py
import module-name1, module-name2

from module-name1 import function-name, ...

# 해당 모듈 내 모든 함수 import. 마찬가지로 함수를 부를 때 앞에 모듈. 을 안써도 된다.
from module-name1 import *

import module-name as alias-name

ex) import math as m
```

## math, random

random.random() -> 0부터 1사이 실수
random.randint(a,b) -> a이상 b미만 정수
math.pow(a,b) -> a의 b승
random.choice(list) -> list에 있는 것 중 랜덤으로 1개 선택해 리턴

## datetime

```py
>>> import datetime as da

>>> da.date.today()
datetime.date(2022, 12, 2)

>>> da.date.today().strftime('%Y/%m/%d')
'2022/12/02'

>>> da.date.today().strftime('%Y&%m&%d')
'2022&12&02'

>>> d = da.date.today()
>>> dt = da.datetime.today()
>>> dt
datetime.datetime(2022, 12, 2, 14, 2, 11, 658597)
>>> dt.strftime('%b %d %Y %a %H:%M:%S')
'12월 02 2022 금 14:02:11'
>>> dt.strftime('%m %d %Y %a %H:%M:%S')
'12 02 2022 금 14:02:11'
>>> dt.year
2022
>>> dt.day
2
>>> dt.hour
14
>>> dt.minute
2
>>> dt.second
11
>>> dt.month
12
```

%Y : 해당연도

%m : 해당 달(숫자)
%b : 해당 달(숫자+'월')

%d : 해당 날짜
%a : 해당 날짜의 요일

%H, %M, %S : 시, 분, 초 (대문자 유의)

## time

```py
>>> import time

>>> time.time()
1669957776.505847
(1970년 1월 1일 0시부터 지난 시간(초단위)) UTC라고 한다.

>>> time.localtime()
time.struct_time(tm_year=2022, tm_mon=12, tm_mday=2, tm_hour=14, tm_min=9, tm_sec=46, tm_wday=4, tm_yday=336,tm_isdst=0)

>>> time.strftime('%Y-%m-%d', time.localtime())
'2022-12-02'

>>> time.sleep(5)

>>> for i in range(5):
...     print(i)
...     time.sleep(1)
...
0
1
2
3
4
```

# 응용예제

## 1. interval between dates

```py
import datetime

today = datetime.date.today()
print('today : ' , today)

date = input('end day(yyyy-mm-dd): ')
ymd = date.split('-')
endday = datetime.date(int(ymd[0]), int(ymd[1]), int(ymd[2]))

print(endday - today)

today :  2022-12-02
end day(yyyy-mm-dd): 2022-12-16
14 days, 0:00:00
```

## 2. target date

```py
date = input('start day(yyyy-mm-dd):')
ymd = date.split('-')
startday = datetime.date(int(ymd[0]), int(ymd[1]), int(ymd[2]))

term = int(input('term(ex: -10, 10) : '))
t = datetime.timedelta(days=term)

print('target date is : ', (startday+t))
```
