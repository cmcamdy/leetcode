#第四章 操作列表
#for循环
names = ['shenye', 'chenhuan', 'feifei']
for name in names:  #注意不要遗落冒号：
    print(f"{name.title()},who is a great person")
    print(f"samrt and beautiful,{name.title()}.\n")
#循环要注意缩进和不缩进的区别
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(f"{magician.title()},that was a great trick!")  #属于循环后的组成部分 所以需要缩进
    print(f"I can't wait to see your next trick,{magician.title()}.\n")
print("thanks,everyone.That's a great magic show!")

#函数range（）
for value in range(1, 5):  #注意差一，后面的数字是不包含
    print(f"{value}\n")
for value in range(1, 5, 2):  #range(开始，结束，步长)
    print(value)

#eg1:输出1~9的平方
squares = []
for value in range(1, 10):
    square = value**2
    squares.append(square)
print(squares)
#eg2:输出1~9的平方
squares = []
for value in range(1, 10):
    squares.append(value**2)
print(squares)

#list（） 将参数转换为列表
numbers = list(range(1, 5))
print(numbers)

#专门处理数字列表的Python函数
digits = list(range(1, 101))
print(max(digits))
print(min(digits))
print(sum(digits))

#列表解析
square = [value**2 for value in range(1, 10)]  #列表描述名=[定义一个表达式 for循环] 这个就不需要加冒号
print(squares)

#使用列表的一部分 切片
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[0:3])
print(players[1:4])
print(players[:])
#遍历切片
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print("here are the first three players on my team:")
for player in players[:3]:
    print(player.title())
#复制列表
my_foods = ['pizza', 'falafei', 'carrot cake']
friend_foods = my_foods[:]  #注意这里的是my_food[:],如果不加方括号，则相当于关联变量
print('My favourite foods are:')
print(my_foods)
print('\nMy friend favourite foods are:')
print(friend_foods)
my_foods.append('cannoli')
friend_foods.append('ice cream')
print(my_foods)
print(friend_foods)

#元组，不可变的列表,是由逗号标识的，搭配圆括号
dimensions = [200, 50]
print(dimensions[0])
print(dimensions[1])
dimensions[1] = 200
print(dimensions[1])

dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])
# dimensions[1]=200 这一步无法完成.如果要更改，可以给存储元组的变量赋值。重新定义整个元组：
dimensions = (100, 20)
print('original dimensions:')
for dimension in dimensions:
    print(dimension)
dimensions = (500, 50)
print('Modified dimensions:')
for dimension in dimensions:
    print(f'{dimension}\n')

#遍历元组中所有值
dimensions = (100, 20)
for dimension in dimensions:
    print(dimension)

#if语句
cars = ['audi', 'bmw', 'subaru', 'toyota']
for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())

#条件测试
requested_topping = 'mushrooms'
# if requested_topping != 'anchovies':
# if requested_topping is not 'anchovies':
if requested_topping is 'anchovies':
    print('hold the anchovies!')

#if 语句的格式
#if conditional test:
#   do something

age = 22
if age >= 18:
    print('True')

#if else 语句
age = 12
if age >= 18:
    print('True')
else:
    print('You are too young')

# if- elif- else 语句
age = 16
if age >= 18:
    print('Enough')
elif age <= 12:
    print('You are too young')
else:
    print('middle')

# if- elif- else 语句
age = 12
if age < 4:
    price = 0
elif age < 18:
    price = 25
else:
    price = 40
print(f'Your admission cost is ${price}.')

requested_toppings = ['mushrooms', 'extra cheese']
if 'watermalen' not in requested_toppings:
    print('watermalen')
if 'mushrooms' in requested_toppings:
    print("Adding mushrooms.")
if 'pepperoni' in requested_toppings:
    print("Adding pepperoni.")
if 'extra cheese' in requested_toppings:
    print("Adding extra cheese.")
print('\nFinished making your pizza!')

#使用if语句处理列表
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']
for requested_topping in requested_toppings:
    print(f"Adding{requested_topping}.")
print('\n Finished making your pizza!')

requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']
for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("sorry,we are out of green peppers right now.")
    else:
        print(f"Adding{requested_topping}.")
print('\n Finished making your pizza!')
