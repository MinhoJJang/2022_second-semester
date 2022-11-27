
str = 'BACAEFGA'
str2 = '________'
selected = 'A'

# index1 = str.find('A')
# print(index1)

# index2 = str[index1+1:].find('A')
# print(index2)

# print(str)

index = -1
while(str[index+1:].find(selected) != -1):
 
        index = str[index+1:].find(selected)+index+1
        print(index)
        str2 = list(str2)
        str2[index] = selected
        str2 = ''.join(str2)
        print(str2)
        print(type(str2))

for player in str:
    print(player)