# 1 Hello World！
    print("Hello world!")
# 2 变量和简单数据类型
## 2.1 变量
    message = "hello world"  
    print(message)
## 2.2 字符串
**引号可双可单，于是内部可使用引号。**
### 2.2.1 方法（后面都有括号,不影响原本的变量）
    print(name.title())  #首字母大写
    print(name.upper())  #全部大写
    print(name.lower())  #全部小写
    print(name.lstrip()) #删除左侧空白
### 2.2.2 合并字符串
    a = "happy"  
    b = "sad"  
    c = a+" "+b
### 2.2.3 制表符和换行符
- 制表符：\t  
- 换行符：\n
## 2.3 str()
    a = "happy "  
    b = 23  
    c = "th birthday!"  
    print(a+str(b)+c)
## 2.4 注释
**#后面加东西**
# 3 列表简介
## 3.1 列表及其访问
    bicycles = ['trek', 'cannondale', 'redline', 'specialized']  
    print(bicycles)  
    bicycles[0]  
    bicycles[-1]
## 3.2 修改、添加和删除元素
    bicycles[0] = 'giant'  
    bicycles.append('giant')    #末尾添加
    bicycles.insert(1,'giant')  #中间插入
    del bicycles[1]             #中间删除
    popped = bicycles[1]        #弹出某元
    bicycles.remove('trek')     #根据值删除元素(只删除首个)
## 3.3 组织列表
### 3.3.1 sort()（永久改变列表，且不能直接print） 
    bicycles = ['trek', 'cannondale', 'redline','specialized']  
    bicycles.sort()                 #正序
    bicycles.sort(reverse=True)     #倒序
### 3.3.2 sorted（暂时改变列表，且能直接print）
    print(sorted(bicycles,reverse=True))
### 3.3.3 列表元素倒转（永久改变）
    bicycles.reverse()
### 3.3.4 确定列表的长度
    lenn = len(bicycles)
# 4 操作列表
## 4.1 列表的遍历
~~~
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(magician)
~~~
## 4.2 创建数值列表
### 4.2.1 range()
    for value in range(1,5): 
        print(value)
**注意：**
- range是左闭右开的。
### 4.2.2 list(range(1,5))
    numbers = list(range(1,6)) 
    print(numbers)

    [1, 2, 3, 4, 5]

    even_numbers = list(range(2,11,2)) 
    print(even_numbers)

    [2,4,6,8,10]
### 4.2.3 数字列表的统计计算
    digits = [1,5,10,18]
    min(digits)
    max(digits)
    sum(digits)
### 4.2.4 列表解析
l = [value**2 for value in range(1,11)]
## 4.3 使用列表的一部分
### 4.3.1 切片
    players = ['charles', 'martina', 'michael', 'florence', 'eli']
    print(players[1:4]) #和range()一样也是左闭右开
    print(players[:4])  #不指定左侧时从第0个开始
    print(players[1:])  #知道我想注释啥吧
    print(players[-3:]) #从倒数第三个开始到最后
### 4.3.2 复制列表
    l1 = l2[:]  #正确的
    l1 = l2     #错误的
## 4.4 元组
**元组是一种不可变的列表，使用圆括号来标识。**

    dimensions = (200, 50)
    print(dimensions[0])    #和列表的读取类似
**可以给存储元组的变量赋值，让它指向新的元组。**

    dimensions = (200, 50)
    dimensions = (400,100)
# 5 if语句
## 5.1 基本语法
    cars = ['audi', 'bmw', 'subaru', 'toyota'] 
    for car in cars: 
        if car == 'bmw':
            print(car.upper())
        else:
            print(car.title())
**注意：**
- 与C语言相同：==，!=，>=
- 与C语言不同：and，or，sth in list，sth not in list，list（不空则返回True）
## 5.2 if-elif-else
    age = 12
    if age < 4:
        print("Your admission cost is $0.") 
    elif age < 18:
        print("Your admission cost is $5.")
    else:
        print("Your admission cost is $10.")
# 6 字典
## 6.1 一个简单的字典
    alien = {'color': 'green','points':5}
    print(alien['color'])
    print(alien['points'])
**注意：**  
- 字典以花括号标识，读取时为中括号，这一点与列表、元组相同。  
- 字典由一个个“键-值”对组成。
## 6.2 字典的使用
### 6.2.1 创建空字典
    alien = {}
### 6.2.2 添加键-值对
**字典是一种动态结构，可以随时直接添加键值对。**  

    alien = {'color': 'green','points':5}
    alien['x_position'] = 25

### 6.2.3 删除键-值对
    alien = {'color': 'green', 'points': 5}
    del alien['points']
## 6.3 遍历字典
### 6.3.1 遍历所有的键-值对
    for k,v in alien.atems():
        print("key:"+k)
        print("valve:"+v)
**注意：**
- 方法atems会返回一个键值对列表
### 6.3.2 遍历所有的键
**类似上面，用方法keys()，其实遍历字典的时候，默认也是遍历keys.**
### 6.3.3 按顺序遍历字典中的所有键
    for key in sorted(alien.keys()):
        print(key)
**注意：**
- 实质上是转化为了列表的排序。
### 6.3.4 遍历字典中的所有值
    for value in alien.values():        #返回列表，值可能重复
    for value in set(alien.values()):   #返回集合，值不会重复
## 6.4 嵌套
**没啥说的**
# 7 用户输入和while循环
## 7.1 函数input()的工作原理
    value = input("value = ") 
**注意：**
- 返回的是字符串。
  
**使用int获取数值输入**

    age = input("please input your age: ")
    age = int(age)
## 7.2 while循环
    active = True
    while active:
        ...
        if sth:
            active = False
# 8 函数
## 8.1 定义函数
    def hello_user(username):           #username是一个形参
        '''显示简单的问候语'''
        print("hello,"+username+'!')
    hello_user('Lee')                   #'Lee'是一个实参
# 8.2 传递实参
### 8.2.1 位置实参
    def pet_type(animal_type,pet_name):
        print(pet_name.title()+" is a "+animal_type+'.')
    pet_type('dog','xiaobai')
### 8.2.2 关键字实参
    def pet_type(animal_type,pet_name):
        print(pet_name.title()+" is a "+animal_type+'.')
    pet_type(pet_name = 'xiaobai',animal_type = 'dog')
### 8.2.3 默认值
    def pet_type(pet_name,animal_type = 'dog'):
        print(pet_name.title()+" is a "+animal_type+'.')
    pet_type('xiaobai')
**注意：**
- 使用默认值时，有默认值的形参需要放在最后。
- 不想使用默认值时，直接当做没有默认值来调用即可。
## 8.3 返回值
**return**
## 8.4 传递列表
### 8.4.1 在函数中修改列表
    def print_models(unprinted_designs, completed_models):
        ...
    print_models(unprinted_designs, completed_models)
### 8.4.2 禁止函数修改列表
    def print_models(unprinted_designs, completed_models):
        ...
    print_models(unprinted_designs[:], completed_models)
## 8.5 传递任意数量的实参
**形参名中的*会创建一个名为toppings的空元组，并将收到的实参都放入元组中。**

    def make_pizza(*toppings):
        print("If you wanna make a pizza, you'll need:")
        for topping in toppings:
            print("- "+topping)
    make_pizza('mushrooms', 'green peppers', 'extra cheese')
### 8.5.1 结合使用位置实参和任意数量实参
    def make_pizza(size,*toppings):
**注意：**
- 任意数量形参必须放在最后。
### 8.5.2 使用任意数量的关键字实参
    def build_profile(first, last, **user_info):
        '''创建一个字典，其中包含我们知道的有关用户的一切'''
        profile = {}
        profile['first_name'] = first
        profile['last_name'] = last
        for key, value in user_info.items():
            profile[key] = value
        return profile

    user_profile = build_profile('albert', 'einstein',location='princeton',field='physics')
    print(user_profile)
**注意：**
- **创建了一个名为user_info的空字典。
- 传入键值对的时候，键作为变量不要加表示字符串的引号。
## 8.6 将函数存储在模块中
### 8.6.1 导入整个模块
    import module_name                              #导入
    module_name.function_name()                     #使用
### 8.6.2 导入特定的函数
    from module_name import function_0, function_1  #导入
    function_0()                                    #使用
### 8.6.3 使用as给函数指定别名
    from module_name import function_name as fn     #导入
    fn()                                            #使用
### 8.6.4 使用as给模块指定别名
    import module_name as mn                        #导入
    mn.function_name()                              #使用
### 8.6.5 导入模块中的所有函数
    from module_name import *                       #导入
    function_name()                                 #使用
# 9 类
- 面向对象编程
- 类
- 对象
- 实例化
## 9.1 创建和使用类
### 9.1.1 创建Dog类
    class Dog():
        def __init__(self,name,age):
            self.name = name
            self.age = age

        def sit(self):
            print(self.name.title()+" is now sitting.")

        def roll_over(self):
            print(self.name.title()+"rolled over.")
**注意：**
- 类的名称首字母按照约定应大写。
- \_\_init\_\_中的下划线_前后各两个。
- 类下定义的函数成为方法，方法中的首个形参必为self。
- 创建实例时，只需给后两个形参提供值。
### 9.1.2 根据类创建实例
**创建实例**

    my_dog = Dog('willie', 6)
**用句点访问属性**

    print("My dog's name is "+my_dog.name.title()+", and he is "+str(my_dog.age)+" years old.")
**用句点调用方法**

    my_dog.sit()
## 9.2 使用类和实例
### 9.2.1 Car类
    class Car():
        def __init__(self,make,model,year):
            self.make = make
            self.model = model
            self.year = year

        def get_descriptive_name(self):
            message = str(self.year)+" "+self.make+" "+self.model
            return message
    my_car = Car('Audi','A4',2016)
    print(my_car.get_descriptive_name())
### 9.2.2 给属性指定默认值
**下面给里程数指定了默认值odometer，因此初始化时不需要形参。**

    class Car():
        def __init__(self,make,model,year):
            self.make = make
            self.model = model
            self.year = year
            self.odometers = 0

        def get_descriptive_name(self):
            message = str(self.year)+" "+self.make+" "+self.model
            return message

        def get_odometers(self):
            return self.odometers

    my_car = Car('Audi','A4',2016)
    print(str(my_car.get_odometers()))
### 9.2.3 修改属性的值
**直接修改属性的值**

    my_car.odometers = 100
**通过方法修改属性的值**

    def update_odometer(self, mileage):
        """将里程表读数设置为指定的值"""
        self.odometers = mileage
    
    my_car.update_odometer(100)
## 9.3 继承
### 9.3.1 子类的方法__init__()
    class ElectricCar(Car):
        def __init__(self,make,model,year):
            super().__init__(make,model,year)
**注意：**
- 子类括号中存放父类名称。
- super()是一个特殊函数，使得子类继承父类的__init__()方法。
- 父类的其他方法也为子类所继承。
### 9.3.2 给子类定义属性和方法
    class ElectricCar(Car):
        def __init__(self,make,model,year):
            super().__init__(make,model,year)
            #for Python2: super(Car,self).__init__(make,model,year)
            self.battery_size = 70

        def describe_battery(self):
            print(self.battery_size)

    my_Ecar = ElectricCar('Audi','A4',2016)
    my_Ecar.describe_battery()
**注意：**
- 新属性放在初始化中super()的下面，作为子类的初始化的一部分。
- 下面又可以定义子类自己的新方法。
### 9.3.3 重写父类的方法
**没啥说的，重写即可，程序会以子类的新方法为准，忽略父类的同名旧方法。**
### 9.3.4 将实例用作属性
    class Battery():
        def __init__(self,battery_size):
            self.battery_size = battery_size

        def describe_battery(self):
            print("It's "+str(self.battery_size)+"!")

    class Ecar(Car):
        def __init__(self,make,model,year):
            super().__init__(make,model,year)
            self.battery = Battery(70)          #将实例用作属性

    my_ecar = Ecar('Tesla','a',2016)
    my_ecar.battery.describe_battery()
**注意：**
- 最后一行中，先查找my_ecar的battery属性，再对存储在该属性中的实例Battery(70)调用方法describe_battery().
## 9.4 导入类
**存放类Car的模块命名为car.py, 写主程序的模块用更具体的名字my_car.py.**
## 9.5 Python标准库
## 9.6 类编风格
- 类名应采用驼峰命名法，即将类名中的每个单词的首字母都大写，而不使用下划线。实例名和模块名都采用小写格式，并在单词之间加上下划线。
- 需要同时导入标准库中的模块和你编写的模块时，先编写导入标准库模块的import语句，再添加一个空行，然后编写导入你自己编写的模块的import语句。
# 10 文件和异常
## 10.1 从文件中读取数据
### 10.1.1 读取整个文件
**方法read()返回的是字符串。**

    with open('pi_digits.txt') as file_object:
        contents = file_object.read()
        print(contents)
**注意：**
- with使得程序在合适的时机自动关闭文件，不需要close()，返回的文件对象只在with代码块内可用。
- 方法open()打开的必须是同一个目录下的文件，并返回一个表文件的对象。
- as将该对象存入file_object中。
- 方法read()返回字符串，并且会在文件结尾时返回一个空字符串，所以print时结尾多一行。
### 10.1.2 文件路径
- 相对文件路径
- 绝对文件路径
- Linux用/，windows用\
### 10.1.3 逐行读取
    with open("pi_digits.txt") as f:
        # contents = f.read()
        for line in f:
            print(line.rstrip())
**问题：**
- 上面代码中注释掉了contents = f.read()，这样运行的结果为逐行读取的正常情况，但假如不注释掉这条代码，运行后并没有输出，为什么？
- f的类型是'_io.TextIOWrapper'，这种类型是怎么组织起来的，为什么for循环可以逐行读取数据，它是以行为单位组织的吗？

**回答：**
- read()是根据光标位置读取文件的，第一次读到末尾光标就指向最后了。
- 不知道耶。。。
### 10.1.4 创建一个包含文件各行内容的列表
**方法readlines()返回的是列表，其中每一个元素是文本中的一行。**

    with open("pi_digits.txt") as f:
        lines = f.readlines()
### 10.1.5 使用文件中的内容
    with open("pi_digits.txt") as f:
        lines = f.readlines()

    pi_str = ''
    for line in lines:
        pi_str += line.strip()
## 10.2 写入文件
### 10.2.1 写入空文件
    file_name = 'programming.txt'

    with open(file_name,'w') as f:
        f.write("I love programming.")
**注意：**
- 'w'会在你写入之前把原有的文本清空。
- 'a'不会清空，只会附加新的。
- 'r'是默认的打开方式，只读。
- 'r+'是可读可写。
### 10.2.2 输入多行
**手动加上换行符\n**
## 10.3 异常
### 10.3.1 try-except代码块
    try:
        answer = a/b
    except ZeroDivisionError:
        print("zz")
    else:
        print(answer)
**还有诸如FileNotFoundError的异常。**
### 10.3.2 分析文本
**方法split()将字符串以' '分割，返回一个字符串列表。**
## 10.4 存储数据
### 10.4.1 使用 json.dump()和 json.load()
>模块json(JavaScript Object Notation)让你能够将简单的Python数据结构转储到文件中，并在程序再次运行时加载该文件中的数据。

    import json

    file_name = "try.json"
    numbers = [0,1,5,4]

    with open(file_name,"w") as f:
        json.dump(numbers,f)
    with open(file_name) as ff:
        n = json.load(ff)

    print(n)
# 11 测试代码
## 11.1 测试函数

    import unittest
    from name_function import get_formatted_name

    class NamesTestCase(unittest.TestCase):
        def test_first_last_name(self):
            n = get_formatted_name('harry','potter')
            self.assertEqual(n,"Harry Potter")

    if __name__ == "__main__":
        unittest.main()
**注意：**
- 定义的方法要以test_开头。