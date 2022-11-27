# JavaScript语法基础
## 1 初识JS
### 1.1 简介
**发明：** 布兰登艾奇。发明，因与Sun公司合作起名JavaScript，与Java的关系类似于人民和人民大会堂的关系。

**特点：** 
- 运行在客户端
- 脚本语言，不需要编译，逐行**解释**
- 可以基于Node.js进行服务器端编程

**作用：**
- 做表单验证（最初）
- 网页特效
- 服务端开发（Node.js）
- 桌面程序（Electron）
- APP（Cordova）
- 控制硬件-物联网（Ruff）
- 游戏开发（cocos2d-js）

**HTML/CSS/JS的关系：**
JS是编程类语言，前两个是标记语言。
### 1.2 浏览器执行JS简介
**浏览器的组成：**
**渲染引擎（内核）：** 解析HTML和CSS，blink、webkit
**JS引擎：** JS解释器，VB
### 1.3 JS的组成
**ECMAScript：** JavaScript语法
**DOM：** 页面文档对象模型，操作页面元素
**BOM：** 浏览器对象模型，操作浏览器
### 1.4 JS初体验
JS有三种书写位置，分为行内、内嵌和外部
### 1.5 JS注释
**单行注释：** // (ctrl+/)
**多行注释：**/* ... */ (ctrl+shift+/)
### 1.6 输入输出
- **prompt(info)**: 用户输入信息，**类型是字符串**
- **alert(msg)**: 浏览器弹出警示框
- **console.log(msg)**: 浏览器控制台打印输出信息
## 2 变量
### 2.1 变量概述
变量是程序在内存中申请的一块用来存放数据的空间。
### 2.2 变量的使用
    var age;                // 声明
    age = 10;               // 赋值
    var age = 10;           // 直接初始化

    var my_name = 'Danny',
        my_age = 20         // 初始化多个变量
### 2.3 变量命名规范
- 字母+数字+_+$
- 严格区分大小写
- 不能以数字开头
- 不能是保留字
- 变量名必须有意义
- 遵循驼峰命名法。首字母小写，后面单词的首字母大写，如：myFirstName
- 不要把name作为变量名，用myName代替
## 3 数据类型
### 3.1 数据类型的简介
不同的数据所占用的空间是不同的，为了便于把数据分成所需内存大小不同的数据，**充分利用存储空间**，于是定义了不同的数据类型。
JS是**弱类型语言（动态语言）**，不用提前声明变量的类型，只有程序在运行赋值时才能确定，而且在赋值之后，数据类型还是可以变化的。
### 3.2 数据类型的分类
- 简单数据类型：number, string, boolean, undefined, null
- 复杂数据类型：object
#### 3.2.1 数字
- 数字包括整数和浮点数
- 数字前面写0，表示八进制；0x，表示十六进制
- Number.MAX_VALUE, Number.MIN_VALUE, Infinity, NaN
- **isNaN()** 函数判断是否不是数字
#### 3.2.2 字符串
- 推荐使用单引号
- 外单内双，外双内单
- \n \t \b \\' \\\
- 字符串长度及拼接：
  - **str.length**: 字符串长度
  - **字符串+任何类型=新的字符串**
  - console.log('我今年'+age+'岁')
#### 3.2.3 布尔型
- true
- false
- 参与加法运算时分别为1和0
#### 3.2.4 undefined和null
- undefined参与加法运算时，结果NaN，理解为undefined可能为数字，可能为字符串，所以结果不确定。
- null参与加法运算时，结果还是加数，null看作0.
### 3.3 获取变量的数据类型
**typeof var**
控制台颜色对于不同的数据类型也是不同的。
也可以通过字面量判断（废话）
### 3.4 数据类型的转换
#### 3.4.1 转化为字符串
- **var.toString()**, 
- **String()**, 
- **加号拼接空字符串**: **最重要**，加法迁就字符串，隐式转换
#### 3.4.2 转化为数字
- **parseInt(var)**: 字符串转化为整数，而且去除数字后面的字母
- **parseFloat(var)**: **最常用**，字符串转化为浮点数，同样会去除后面的字母
- **Number(var)**
- **str-0**, **str*1**: 减法迁就数字，隐式转换
#### 3.4.3 转化为布尔型
- **Boolean()**: 只有'', 0, NaN, null, undefined, false（废话）是false
### 3.5 补充说明
- 标识符：开发人员为变量、函数、属性、参数起的名字，不能是关键字或保留字
- 关键字：JS已经使用了的名字，break, case, while...
- 保留字：预留的关键字，boolean, byte, char...
## 4 运算符
### 4.1 浮点数的特殊情况
0.1+0.2会产生误差
0.07*100同样会有误差
3 == 3.0 // true
**不要直接判断两个浮点数是否相等**
### 4.2 递增和递减运算符
++var, var++：
- 副作用都是使得var自增1
- ++var返回值是var+1
- var++返回值是var
- 与C语言完全相同
### 4.3 比较运算符
- \>, \<, \>=, \<=
- !=不等于
- ==判等号，**会转型**
- ===全等号，**要求值和数据类型都一样**
### 4.4 逻辑运算符
- &&: 与
- ||:或
- !: 非
- **值或者表达式参与逻辑运算（逻辑中断，短路操作）**：表达式1 && 表达式2，如果表达式1为true（或者值非0），执行表达式2，返回表达式2（或者值2）；表达式1为false（或者值为0），返回表达式1（或者值0），不执行表达式2。或运算类似
### 4.5 赋值运算符
=, +=, -=, *=, /=, %=
### 4.6 运算符优先级
小括号
一元运算符
算数运算符，* → +
比较运算符，\> → ==
逻辑运算符，&& → ||
赋值运算符
逗号运算符
## 5 流程控制
### 5.1 分支流程控制
#### 5.1.1 if分支

    // if else
        if (条件表达式) {
          语句1
        } else{
          语句2
        }

    // if else if
    if (条件表达式1) {
      语句1;
    } else if(条件表达式2) {
      语句2;
    } else {
      语句3;
    }
#### 5.1.2 三元表达式
条件表达式 ? 表达式1 : 表达式2
#### 5.1.3 switch分支
    switch (value) {
      case value1:
        语句1;
        break;
      case value2:
        语句2;
        break;
      ...
      default:
        语句n;
    }
- value与case匹配的时候，需要全等，即值和类型完全一样。
- 不写break会顺序执行完。
### 5.2 循环流程结构
#### 5.2.1 for循环
    for(var i=1; i<=100 ; i++) {
      语句;
    }
#### 5.2.2 调试
- 打开检查（F12），点击source
- 打开代码，行号处打断点，刷新
- 点击step into next function call（F11）
- watch里面看变量当前值
#### 5.2.3 while循环
    while (条件表达式) {
      语句;
    }
#### 5.2.4 do-while循环
    do {
      语句;
    } while (条件表达式)
## 6 数组
### 6.1 数组的创建
- **var arrayName = new Array();**
- **var arrayName = [];**
- **Notes:**
数组内部可以放任何数据类型，之间用逗号分割开
### 6.2 数组相关函数
- **arrayName[index]**
- **arrayName.length**
### 6.3 添加数组元素
    var arr = ['a', 'b', 'c'];
    arr[3] = 'd';       // 直接追加元素
## 7 函数
### 7.1 函数的声明
    function funName(){
      函数体
    }
### 7.2 函数的参数
形参，实参
### 7.3 函数的返回值
- **return var;**
- 它只能返回一个值，如果是逗号隔开的（return var1, var2;），返回最后的值
- 没有return，返回undefined
### 7.4 arguments的使用
    // arguments对象中存储了所有的实参
    function fn(){
      console.log(arguments);
    }
    fn(1, 2, 3);
**Notes:**
- arguments是一个伪数组
- arguments是每个函数内置的
- 具有数组的length属性
- 按照索引的方式存储
- 没有数组的pop, push等方法
### 7.5 函数的声明方式
    // 1.利用函数关键字自定义函数（命名函数）
    function fn1() {
      语句1;
    }
    fn1();

    // 2.函数表达式（匿名函数）
    var fn2 = function(){
      语句2;
    }
    fn2();  // 这是变量名，不是函数名
### 7.6 作用域
- 全局作用域：全局变量，整个script标签或者一个单独的JS文件
- 局部作用域：局部变量，只在某个函数内部起作用
- **全局变量的特殊情况：在函数内部没有声明，只赋值的变量也是全局变量。**

      function fn () {
        num = 10;         // 全局变量
      }
      fn();
      console.log(num);   // 可以输出
- 全局变量只有浏览器关闭时才会销毁，比较占内存
- 局部变量当程序执行完毕就会销毁，比较节约内存资源
### 7.7 块级作用域
在{}之内的叫块级作用域
JS在es5没有块级作用域，直到es6才有
### 7.8 作用域链
内部函数访问外部函数的变量，采取链式查找的方式，决定找哪个值
## 8 JS预解析
- JS引擎在运行JS代码的时候分为两步：预解析、代码执行
- **预解析：JS里面所有的var, function提升到当前作用域的最前面**
  - **变量预解析（变量提升）：所有的变量（包括函数表达式左侧的函数变量）声明提升，不提升赋值**
  - **函数预解析（函数提升）：所有的函数提升**
- 代码执行：按顺序执行
## 9 对象
### 9.1 对象的概念
对象是一个具体的事物。
在JS中，**对象是一组无序的相关属性和方法的集合**，由属性和方法组成。
- 属性：事物的特征
- 方法：事物的行为
### 9.2 对象的创建
#### 9.2.1 利用字面量创建对象
对象字面量：花括号{}里面包含了对象的属性和方法

    var obj = {
      uname: 'Danny',
      gender: 'male',
      age: 12,

      sayHi: function() {
        console.log('Hi!');
      }
    }

    console.log(obj.uname);
    console.log(obj['uname']);
    obj.sayHi();
**Notes:**
- 属性和方法采用键值对的形式
- 多个属性和方法之间用逗号隔开
- 方法冒号后跟匿名函数
- 调用对象的属性，对象名.属性名||对象名['属性名']
- 调用对象的方法，对象名.方法名();
#### 9.2.2 利用new Object创建对象
    var obj = new Object();
    obj.uname = 'Jenny';
    obj.gender = 'female';
    obj.age = 14;

    obj.sayHi = function() {
      console.log('Hi!')
    }
**Notes:**
- 利用等号赋值的方法添加属性和方法
- 每个属性和方法之间用分号分割
#### 9.2.3 利用构造函数来创建对象
    /* function 构造函数名() {
      this.属性 = 值
      this.方法 = function(){}
    } */

    function Star(uname, age, gender){
        this.uname = uname;
        this.age = age;
        this.gender = gender;

        this.sing = function(song) {
            console.log(this.uname+'正在唱《'+song+'》');
        }
    }

    var ldh = new Star('刘德华', 18, '男');
    var zxy = new Star('张学友', 18, '男');
    var gfc = new Star('郭富城', 18, '男');
    var lm = new Star('黎明', 18, '男');

    ldh.sing('冰雨');
    zxy.sing('李香兰');
**Notes:**
- 构造函数名首字母大写
### 9.3 new关键字
1. 在内存中创建新的空的对象
2. this指向空对象
3. 执行构造函数里的代码，添加属性和方法
4. 返回这个对象
### 9.4 对象的遍历
    var obj = {
        name: 'KBY',
        gender: 'male',
        age: 22
    }

    //for (变量名 in 对象名) {}
    for (var key in obj){
        console.log(key);
        console.log(obj[key]);
    }
## 10 内置对象
### 10.1 内置对象的概念
**对象分为三种：自定义对象、内置对象、浏览器对象**
**内置对象：Math, Date, Array, String**
### 10.2 查阅文档MDN
### 10.3 Math对象
- 它不是构造函数，**不用new**，直接使用即可
- Math.max(var)
- Math.random(),返回[0, 1)之间的浮点数
### 10.4 Date对象
- 它是构造函数，**需要new**
- **var date1 = new Date();** 返回当前时间

      var date1 = new Date()            
      console.log(date1);                   // 当前时间

      var date2 = new Date(2023, 10, 1)
      console.log(date2);

      var date3 = new Date('2023-10-1 08:08:08');
      console.log(date3);
- 日期格式化

      var date = new Date();
      console.log(date.getFullYear());
      console.log(date.getMonth()+1);       // 从0开始，月份要+1
      console.log(date.getDate)             // 日期
      console.log(date.getDay)              // 周几 周日是0
      console.log(date.getHours)            // 小时
      console.log(date.getMinutes)          // 分钟
      console.log(date.getSeconds)          // 秒数
- 时间戳 / 获得总毫秒数（距1970-01-01）

      // F1
      var date1 = new Date();
      console.log(date1.valueOf());
      console.log(date1.getTime());

      // F2
      var date2 = +new Date();
      console.log(date2);

      // F3
      console.log(Date.now());
### 10.5 Array对象
#### 10.5.1 数组的创建

    var arr1 = new Array(2);      // 长度为2的空数组
    var arr1 = new Array(2, 3);   // 存放了元素2, 3的数组
#### 10.5.2 是否是数组
- **arr instanceof Array**

      var arr1 = [];
      var obj1 = {};
      console.log(arr1 instanceof Array);
      console.log(obj1 instanceof Array);
- **Array.isArray()**

      var arr1 = [];
      var obj1 = {};
      console.log(Array.isArray(arr1));
      console.log(Array.isArray(obj1));
#### 10.5.3 数组元素的添加和删除
- **arr.push(newValue);**
  - 副作用是数组最后添加一个或多个新元素
  - 返回值是新数组的长度
- **arr.unshift(newValue)**
  - 副作用是数组前面添加一个或多个新元素
  - 返回值是新数组的长度
- **arr.pop()**
  - 副作用是删除数组最后面的元素
  - 返回删除的元素
- **arr.shift()**
  - 副作用是删除数组最前面的元素
  - 返回删除的元素
#### 10.5.4 数组排序
- **arr.reverse()**
- **arr.sort()**          // 按位排序

      arr.sort(function(a, b)) {
        return a-b;       // 升序 
      }
#### 10.5.5 返回元素的索引
- **arr.indexOf(value)**：返回数组中出现的第一个value的索引
- **arr.lastIndexOf(value)**：返回数组中出现的最后一个value的索引
#### 10.5.6 数组转化为字符串
- **arr.toString()**: 默认逗号分隔
- **arr.join(分隔符)**

      arr.join('-')
### 10.6 字符串对象
#### 10.6.1 基本包装类型
字符串本身是简单数据类型，JS会将其**包装**为复杂数据类型，使之成为有length等属性的基本包装类型。

    var str = 'andy';
    // 等价于：
    var temp = new String('andy');
    str = temp;
    temp = null;
#### 10.6.2 字符串的不可变性

    var a = 'a';
    a = 'b'       
- 以上代码的确可以改变变量a的值，但实际上是在内存上申请了一个新的空间，让变量a指向了它，原本的空间不变
- 由于字符串的不可变性，不要大量拼接字符串
#### 10.6.3 根据字符返回位置
    var str = '墙里秋千墙外道，墙外行人，墙里佳人笑。';
    console.log(str.indexOf('墙', 2));
- **str.indexOf('要查找的字符', [起始的位置])**
#### 10.6.4 根据位置返回字符
- **str.charAt(index)**：返回index位置字符
- **str.charCodeAt(index)**: 返回index位置字符的ASCII码，判断用户按了哪个键
- **str[index]**：返回index位置字符（HTML5新增）
- **a['a']**：a是一个对象，若有'a'属性，返回属性值；无，返回undefined
#### 10.6.5 拼接和截取字符串
- **str1.concat(str2)**：拼接字符串
- **str1.substr(起始位置，长度)**：截取字符串
#### 10.6.6 替换字符串，字符串转化为数组
- **str.replace(被替换的字符，替换为的字符)**：只替换第一个出现的
- **str.split(分隔符)**
## 11 简单数据类型和复杂数据类型
### 11.1 简单数据类型（基本数据类型 / 值类型）
**放栈里**
**string, number, boolean, undefined, null**
- null返回的类型是一个空对象，实际上是bug
- 如果有个变量以后打算存储对象，又暂时不想赋值，就先给个null
- **栈**里开辟空间存放**值**，变量名指向该值
### 11.2 复杂数据类型（引用数据类型）
**放堆里**
**系统对象，自定义对象**
- 它存储的实际上是地址
- **栈**里放**地址**，变量名指向该地址，地址对应的数据放在**堆**里
# Web APIs
## 1 基本概念
### 1.1 Web APIs和JS基础的关系
之前的阶段主要学ECMAScript，是为了现在打基础
本阶段主要学BOM和DOM，是W3C组织的规范，实现页面交互效果
### 1.2 API和Web API
- **API(Application Programming Interface，应用程序编程接口)** 是一些预先定义的函数，目的是提供应用程序与开发人员基于某软件或硬件得以访问一组例程的能力，而又无需访问源码，或理解内部工作机制的细节。
- **Web API**是浏览器提供的一套**页面元素**和**操作浏览器功能**的API(DOM, BOM)，如之前一直使用的alert.
## 2 DOM基础
### 2.1 DOM简介
**DOM(Document Object Model，文档对象模型)** 处理可扩展标记语言(HTML, XML)的标准程序接口
### 2.2 DOM树
- **文档**：一个页面就是一个文档（Document）
- **元素**：页面里的所有标签（element）
- **节点**：网页中的所有内容都是节点，如标签、属性、文本、注释（node）

**DOM把以上内容都看作对象**
### 2.3 获取元素
- **document.getElementById(id)**：返回id是'id'的标签对象，JS代码放在该标签的下面才行
- **console.dir()**：打印返回的元素对象，便于查看其属性和方法
- **document.getElementsByTagName(tagName)**：返回tag是tagName的标签对象，**即使只有一个元素，也是一个伪数组**
- **element.getElementsByTagName(tagName)**：返回父元素是element，tag是tagName的标签对象，注意element不能是一个伪数组，要指明某对象

      <ol>
          <li>aa</li>
          <li>aa</li>
          <li>aa</li>
      </ol>
      <script>
          var a = document.getElementsByTagName('ol');
          var b = a[0].getElementsByTagName('li');    // 指明第零个
          console.log(a);
          console.log(b);
      </script>
- **document.getElementsByClassName(className)**：HTML5使用，根据类名获取某些元素
- **document.querySelector(选择器)**：返回指定选择器（加 . # 等符号）的第一个对象
- **document.querySelectorAll(选择器)**：返回指定选择器（加 . # 等符号）的第所有对象，**返回的也是伪数组**
- **document.body**：返回整个body对象
- **document.documentElement**：返回整个html对象
## 3 事件基础
### 3.1 事件概述
- JS使我们有能力创建动态页面，而事件是可以被JS侦测到的行为
- 事件三要素
  1. **事件源**：事件被触发的对象
  2. **时间类型**：如何触发，如鼠标点击，鼠标经过
  3. **事件处理程序**：通过一个函数赋值的方式完成

          <button id='btn'>朕不给你</button>
          <script>
              var btn = document.getElementById('btn');
              btn.onclick = function() {
                  alert('你不能抢！');
              }
          </script>
### 3.2 时间执行的步骤
1. **获取事件源**
2. **注册时间（绑定时间）**
3. **添加时间处理程序（函数赋值）**
### 3.3 操作元素
#### 3.3.1 改变元素
- **element.innerText**: 是一个属性，值是元素的值，不识别HTML的Tag
- **element.innerHTML**: 是一个属性，值是元素的值，识别HTML的Tag
- **Notes：**
  - 两个属性都是可读写的
  - innerHTML更常用
  - innerHTML还会保留空格和换行
#### 3.3.2 改变元素属性
**element.attribute = newAttribute**
#### 3.3.3 改变表单属性
    <input type="button" value="按钮" id="btn">
    <input type="text" value="输入内容" id="txt">

    <script>
        var btn = document.querySelector('#btn');
        var txt = document.querySelector('#txt');
        btn.onclick = function() {
            txt.value = '被点击了';   // 通过属性来选中表单属性
            btn.disabled = true;      // 点击一次后禁用
            // this.disabled = true      与上面等价
        }
    </script>
#### 3.3.4 修改样式属性
- **element.style.styleName**: 驼峰命名法，与CSS中名字不一样
- **element.style.display = 'none'**: 隐藏盒子
#### 3.3.5 获得和失去焦点
- **element.onfocus**：(input)
- **element.onblur**
#### 3.3.6 通过className修改样式属性
element.style.styleName这种方式在数量多的时候很繁琐
所以，在CSS里面写.change样式备用
- **this.className = 'change'**: 给某元素添加类名，正好对应上.change样式，它会覆盖原来的类名，若想保留原类名，this.className = 'oldClassName newClassName'
#### 3.3.7 获取元素自定义属性
- **element.attribute**：得到内置属性 
- **element.getAttribute('name')**：得到自定义属性，如index="1"，原名即可，注意与下面dataset的驼峰命名法区分
#### 3.3.8 改变自定义属性的值
- **element.attribute = '值'**：设置内置属性
- **element.setAttribute('属性', '值')**：设置内置或自定义属性
- **element.removeAttribute('属性')**：移除某属性
## 4 一些算法技巧
### 4.1 排他
只让自己变化样式，先干掉其他人，再设置自己
### 4.2 H5自定义属性
目的：保存并使用数据，保存到页面而不是数据库中
规定：所有自定义属性都以data-开头
- **element.dataset**：是一个集合，存放了所有data-开头的属性
- **element.dataset.attribute**：驼峰命名法
- **element.dataset['attribute']**：驼峰命名法
## 5 节点操作
### 5.1 使用节点的原因
- 获取元素：
  - DOM提供的方法：getElementById等等，只要使用就得从头get，繁琐
  - **节点方法：利用层级关系获取元素**
- **节点：nodeName, nodeType, nodeValue**
  - nodeName: div等
  - nodeType: 元素节点是1，属性节点是2，文本节点是3（文字、空格、换行）
### 5.2 节点操作
#### 5.2.1 父子
- **element.parentNode**: 返回父节点，没爹回空

      <div class="box">
        <span class="ewm">x</span>
      </div>

      <script>
        var ewm = document.querySelector('.ewm');
        console.log(ewm.parentNode);                // 访问父节点
      </script>
- **element.childNodes**: 返回子节点
  - **Notes:**
  - 会把元素节点和文本节点（换行等）都放进去
  - for循环，根据元素节点的类型nodeType == 1只取元素节点
  - 不提倡使用
- **element.children**：返回子元素节点
  - **Notes:**
  - 只返回子元素节点，文本节点不管
  - 好用，我们大家都用它
- **element.firstChild**
- **element.lastChild**
  - **Notes:**
  - 返回第一个 / 最后一个元素或文本节点，包括空格、换行
- **element.firstElementChild**
- **element.lastElementChild**
  - **Notes:**
  - 返回第一个 / 最后一个子元素节点，好
  - 有兼容性问题，**element.children[0]** 最常用
- **element.onmouseover**
- **element.onmouseout**
- **element.onclick**
#### 5.2.2 兄弟
- **element.nextSibling**：下一个兄弟节点，会得到文本节点
- **element.previousSibling**：上一个兄弟节点，会得到文本节点
- **element.nextElementSibling**：下一个兄弟元素节点
- **element.previousElementSibling**：上一个兄弟元素节点
#### 5.2.3 创建节点
- **document.createElement('tagName')**
- **node.appendChild(child)**：后面追加孩子，类似push

      <ul></ul>

      <script>
      var ul = document.querySelector('ul');
      var li = document.createElement('li');
      ul.appendChild(li);
      </script>
- **node.insertBefore(child, 指定元素)**

      <ul></ul>

      <script>
      var ul = document.querySelector('ul');
      var li = document.createElement('li');
      ul.appendChild(li);
      var lili = document.createElement('li');
      ul.insertBefore(lili, ul.children[0]);
      </script>
#### 5.2.4 删除节点
- **node.removeChild(child)**
#### 5.2.5 赋值（克隆）节点
- **node.cloneNode(true)**：返回一个相同的node节点
- **Node:**
  - 括号为空 / 括号内为false：浅克隆，只赋值标签，不复制内容
  - 括号内为true：深克隆，赋值标签和内容
#### 5.2.6 三种动态创建元素方法的区别
- **document.write('\<div>123\</div>')**：会使得页面全部重绘
- **innerHTML**：拼接字符串，速度较慢；采取数组形式拼接，**速度最快**
- **document.createElement**：速度快很多
### 5.3 复习
利用创建、增、删、改、查的思路复习DOM
## 6 事件高级
### 6.1 注册事件（绑定事件）
- 传统方式：on-开头，具有唯一性
- 方法监听注册方式：**addEventListener() / attachEvent()**
  - **addEventListener('type', listener[, useCapture])**
  - type: 事件类型字符串，如click，mouseover，不要加on-
  - listener：事件处理函数，发生时调用
  - useCapture：布尔值，默认false冒泡阶段，true捕获阶段
### 6.2 删除事件（解绑事件）
- **removeEventListener('type', listener)**：单独写函数
### 6.3 DOM的事件流
事件流描述的是从页面中接收事件的顺序
事件发生时会在节点元素之间按照特定的顺序传播，这个传播过程即DOM事件流
**举例：div注册了一个事件：**
1. 捕获阶段: Document->Element html->Element body->Element div
2. 当前目标阶段
3. 冒泡阶段: Element div->Element body->Element html->Document
### 6.4 事件对象
    btn.onclick = function (event) {}
    btn.addEventListener('click', function (event) {})
侦听函数的小括号里面，当成形参来看
事件对象只有有了事件才会存在，它是系统自动创建的，不需要传实参
事件对象是事件的一系列相关数据的集合，比如：鼠标点击里包含了鼠标的坐标
事件对象自己随便命名，如：e
### 6.5 事件对象的常见属性
#### 6.5.1 this和e.target
    <div class="box">123</div>

    <script>
    div.addEventListener('click', function(e){
      console.log(e.target);  // 返回触发事件的对象
      console.log(this);      // 返回绑定事件的对象
    })
    </script>
ul > li，给ul绑定事件，点击li，this / e.currentTarget是ul，e.target是li
#### 6.5.2 e.type和阻止默认行为
- **e.type**: 返回type
- **e.preventDefault()**: 阻值默认行为，如链接不跳转，点击按钮不提交

      a.addEventListener('click', function(){
        e.preventDefault();
      })
      // return false传统方式，和上面等效
- **e.stopPropagation()**：阻值冒泡，点了儿子，不认为点了父亲
- 
      <div id='father'>
        <div id='son'></div>
      </div>

      <script>
        var son = document.querySelector('#son');
        son.addEventListener('click', function(e){
          alert('son');
          e.stopPropagation();
        })
        
        var father = document.querySelector('#father');
        son.addEventListener('click', function(e){
          alert('father');
        })

        document.addEventListener('click', function(){
          alert('document');
        })
上面代码，点儿子只弹出son，点父亲会弹出father和document，因为默认是冒泡阶段，一层一层向上，点了儿子，弹出son本应向上冒泡到父亲，但儿子 被阻止了，点父亲，弹出father，且冒泡未被阻止，所以冒泡到document，弹出document
#### 6.5.3 事件委托
- **原因**：设想ul里面很多个li，每个li注册事件，页面就绪事件会很长
- **原理**：不是每个子节点设置事件监听器，而是父节点设置监听器，然后利用冒泡原理影响设置每个子节点，如：给ul注册点击事件，然后利用e.target来找到当前点击的li，点击li，事件会冒泡到ul上，ul有注册事件，就会触发时间监听器。
- **作用**：只操作了一次DOM，提高了是程序的性能
#### 6.5.4 鼠标事件：禁止选中文字和禁止右键菜单等
- **contextmenu**：右键菜单

      document.addEventListener('contextmenu', function(e){
        e.preventDefault();
      })
- **selectstart**：开始选中

      document.addEventListener('selectstart', function(e){
        e.preventDefault();
      })
**其实 F12 element 找内容就可以了**
- **mousemove**：鼠标移动1px就触发
- **e.clientX**：相对于鼠标在浏览器可视窗口x坐标
- **e.clientY**：相对于鼠标在浏览器可视窗口y坐标
- **e.pageX**：相对于页面x
- **e.pageY**：相对于页面y
#### 6.5.5 键盘事件
- **(on)keyup**：某个键松开时触发
- **(on)keydown**：某个键按下时触发，按下时一直会触发
- **(on)keypress**：某个键按下时触发，按下时一直会触发，但是不识别功能键，如ctrl, shift
- 执行顺序：keydown, keypress, keyup
- **e.keyCode**：返回ASCII码值，keyup和keydown不区分大小写，keypress区分大小写0
## 7 BOM基础
### 7.1 BOM的构成
BOM（Browser Object Model）即**浏览器对象类型**，它提供了独立于内容而与浏览器窗口进行交互的对象，其核心对象是window.如：前进页面，刷新页面，BOM缺乏标准
||DOM|BOM|
|:---:|:---:|:---:|
|名称|文档对象模型|浏览器对象模型|
|意义|把文档当作对象看待|把浏览器当作对象来看待|
|顶级对象|document|window|
|学习内容|操作页面元素|浏览器窗口交互对象|
|标准|W3C|不统一，兼容性差|
**BOM包含DOM**
**window = document + location + navigation + screen + history**
window对象是浏览器的顶级对象，它具有双重角色。
- 它是JS访问浏览器窗口的一个接口
- 它是一个全局对象，定义在全局作用域中的变量、函数都会变成window对象的属性和方法。
window有属性name，所以变量命名不要用name.
### 7.2 window对象的常见事件
#### 7.2.1 窗口加载事件
- **window.onload**: 窗口（页面）加载事件，当文档内容（包括图像、脚本文件、CSS文件等）完全加载完成会触发该事件。
  - **注意：**
    - 有了window.onload就可以把JS代码写道页面元素的上方，因为onload是等页面内容完全加载完毕，再去执行处理函数。
    - window.onload这种传统注册事件方式只能写一次，如果有多个，会以最后一个为准。
    - 如果使用addEventListener则没有限制。

          <script>
            window.addEventListener('load', function () {
              var btn = document.querySelector('button');
              btn.addEventListener('click', function () {
                alert('click');
              })
            })
          </script>
    
          <button>click</button>
- **window.DOMContentLoaded**：当DOM加载完成，不包括样式表、图片、flash等时，事件触发。改善图片太多，用户体验下降的情况。
#### 7.2.2 调整窗口大小事件
- **window.onresize**: 窗口大小变化就会触发。
- **window.innerWidth**: 窗口宽度
#### 7.2.3 定时器
- **window.setTimeout(调用函数, 延时时间)**：间隔一个延时时间，再调用函数
  - **注意：**
    - 调用时，window可以省略
    - 延时单位是毫秒，可以省略
    - 调用函数可以直接写函数，也可以写函数名
    - 定时器可能有很多，所以要给每一个加上标识符

            <script>
              var time1 = setTimeout(function(){
                alert('aaa');
              }, 3000)
            </script>
    
            <script>
              function fn() {
                alert('aaa');
              }
              var time2 = setTimeout(fn, 3000);
            </script>
**回调函数**：定时器里的函数也叫回调函数，即回头调用，还有监听器里的函数等。
- **clearTimeout(定时器名字)**
- **setInterval(回调函数, 间隔时间)**：每间隔一个间隔时间，执行一次回调函数
- **clearInterval(定时器名字)**
### 7.3 JS执行机制
JS是单线程语言，同一时间只能做一件事，后HTML5提出Web Worker标准，运行创建多个线程
- 同步任务：上一个任务执行完了，才能执行下一个任务
- 异步任务：多个事情同时推进。如：回调函数、普通事件（click）、资源加载（load）、定时器（setTimeout）

同步任务在主线程上进行，形成一个执行栈，先执行执行栈里的同步任务，其中的回调函数等放入任务队列，执行完执行栈中的任务后，开始事件循环，监视任务队列，把任务队列里的任务放到执行栈执行。
### 7.4 location对象
#### 7.4.1 URL
URL(Uniform Resource Locator)，即统一资源定位符。
**protocol: // host[:port]/path[?query]#fragment**
**http: // www.itcast.cn/index.html?name=andy&age=18#link**
- **protocol**: 通信协议。常用http, ftp等
- **host**: 主机（域名）
- **port**: 端口号。省略时使用方案的默认端口，如http的默认端口是80
- **path**: 路径。由零或多个'/'符号隔开的字符串，一般用来表示主机上的一个目录或文件地址
- **query**: 参数，以键值对的形式通过&符号分割开
- **fragment**: 片段。#后面内容常见于链接，锚点
#### 7.4.2 location的属性
- **location.href**: 获取或者设置整个URL
- **location.host**: 返回主机（域名）
- **location.port**: 返回端口号
- **location.pathname**: 返回路径
- **location.search**: 返回参数
- **location.hash**: 返回片段。#后面内容常见于链接，锚点
#### 7.4.3 location常见方法
- **location.assign()**: 跟href一样，可以跳转页面（重定向页面），它记录浏览历史，能后退页面。
- **location.replace()**: 替换当前页面，因为不记录历史，所以不能后退页面。
- **location.reload()**: 重新加载页面，相当于刷新按钮或F5，如果参数为true，强制刷新ctrl+F5 
### 7.5 navigator对象
- **navigator.userAgent**: 判断用哪个终端打开页面，是PC还是移动端等
### 7.6 history对象
- **history.forward()**: 相当于点击了左上角前进按钮
- **history.back()**: 相当于点击了左上角后退按钮
- **history.go(1)**: 前进一步
- **history.go(-1)**: 后退一步