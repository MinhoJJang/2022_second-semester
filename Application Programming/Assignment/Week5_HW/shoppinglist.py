# -(슬라이드 52-53) Homework 1: 쇼핑리스트 만들기 프로그램을 완성하세요.(shoppinglist.py)

import enum
from sqlalchemy import true


slist = []
while True:
    item = input('원하는 물건을 입력하세요: ')
    if item == 'quit':
        break
    else:
        slist.insert(0, item)
        slist.sort()
    
    for i, value in enumerate(slist):
        print(i+1, value)
        
        
