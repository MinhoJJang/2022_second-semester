

mydict = {'name': 'Kim', 'year': 1999, '(name, year)': ('kim', 123)}

# print(mydict['(name, year)'])
# print(mydict.get('(name, year)', 'value'))

if(mydict.get('newkey') == None):
    mydict.update({'newkey': 'newvalue'})
    mydict.update({'year': 2000})
    
mydict['pluskey'] = 'plusvalue'
mydict['name'] = 'Jang'
    
# print(mydict.get('newkey'))
# print(mydict.get('year'))

print(mydict)
# popitem(): 맨 뒤의 항목을 pop 하고 dictionary에서 제거
print(mydict.popitem())
print(mydict)

# pop(): 제거할 키값에 해당하는 value값을 리턴하고 제거
print(mydict.pop('name'))
print(mydict)

# del: year 항목을 제거 
del mydict['year']
print(mydict)

# clear(): 전체 딕셔너리 제거 
mydict.clear()
print(mydict)

mydict = {'name': 'Kim', 'year': 1999, '(name, year)': ('kim', 123)}

capitaldict = {'한국': '서울', '베트남': '하노이', '일본': '도쿄'}
for x, y in capitaldict.items( ):
    print('{0}의 수도는 {1}입니다.' .format(x, y))
    
    
x = {'a': 10, 'b': 20, 'c': 30, 'd': 40, 'e': 50}

# 불가능 
# for key, val in x.items():
#     if(val == 20):
#         del x[key]
# RuntimeError: dictionary changed size during iteration

# 가능
keyMemory = []

for key, val in x.items():
    if(val == 20):
        keyMemory.append(key)

for i in keyMemory:
    del x[i]
   
print(x)      

x = {key: value for key, value in x.items( ) if value != 20}
print(x)


