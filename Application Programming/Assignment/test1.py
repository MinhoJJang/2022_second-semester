my_data = (99, )
my_data1 = (99)

print(type(my_data))
print(type(my_data1))

my_data = ("hi", "hello", "bye")
my_data2 = (1, 2.8, "Hello World")
my_data3 = ("Book", [1, 2, 3])
my_data4 = ((2, 3, 4), (1, 2, "hi"))

print(my_data3[1])
print(my_data3[0][1:3])
print(my_data4[1][1])
print(my_data4[1][1:])
print(my_data + my_data2)
print(my_data*2)
print(my_data4[-2][0:1])

print(len(my_data4))

print([1,2,3] in my_data3)
print([2] in my_data3)
print((2,3,4) in my_data4)

a = ("John", "Charles", "Mike")
b = ("Jenny", "Christy", "Monica", "Vicky")

x = zip (a, b)
print(tuple(x))
print(x)


q,w,e = my_data4[1]
print(q, w, e)