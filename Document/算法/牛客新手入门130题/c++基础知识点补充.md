## 算法知识点笔记

[TOC]

------

### 一、C++基础语法补充

#### 1、进阶输入输出

​	在c++中可以用`fixed`和`setpreision`来控制浮点数的输出精度。常见的应用有如下两种：

- 保留小数点后n位（四舍五入），对应语法：

```c++
cout << fixed << setprecision(n) << pi << endl; 
```

- 保留有效数字n位（四舍五入），对应语法：

```c++
cout << setprecision(n) << pi << endl;
```

- 清空以前对小数输出格式的设置

```c++
cout << defaultfloat;
```

【使用的场景】

​	题目要求，误差的量级不超过$10^{-3}$时，可以只保留小数点后的3位，即：

```c++
cout << fixed << setprecision(3) << x << endl;
```

#### 2、类型转换

​	C++有两种类型转换方式：隐式转换和显式转换。

- **隐式转换：**我们可以通过将一种类型的变量直接赋值给另一种类型的变量，此时被赋值的变量就相当于是主动赋值变量由原本数据类型转化为新数据类型后的值。此时，编译器会自动将一种类型转换为另一种类型，无需额外的代码。
- **显式转换**：我们也可以使用**强制类型转换运算符**来将一种类型的变量强制转换为另一种类型的变量。此时，我们需要在变量名前加上括号，并在括号内指定要转换的目标类型。例如，如果我们要把一个 `double` 类型的变量（假设这个变量叫 `d`）转换为 `int` 类型的变量，此时表示变量 `d` 在被转化类型后的结果的表达式为: `(int) d`。需要注意的是，这个操作只能得到转换后的值，并不会改变原本变量的值，也就是说，此时变量 `d` 的数据类型并没有发生改变，仍然为 `double` 类型。

> 特殊的，在 C++ 中，我们无法直接通过 `(string) 整数类型变量名` 的方法将整数类型变量转换为字符串类型变量，也无法直接通过 `(int) 字符串类型变量名` 的方法将字符串类型变量转换为整数类型变量。如果需要，可以尝试使用下面三个函数：
>
> 1. `stoi()` 函数：将字符串转换为整数。
> 2. `stod()` 函数：将字符串转换为双精度浮点数。
> 3. `to_string()` 函数：将数值转换为字符串。

​	需要特别注意的是，从浮点型转换为整型时，小数部分会被截断，而不是四舍五入。

#### 3、字符和字符串

- 字符是char，就是单个字符例如n；用cin或getchar输入
- 字符串是string，一个串，如nowcode；用cin输入；

#### 4、常用数学函数

| 数学函数名称 |   函数名   |                           计算结果                           |                             举例                             |
| :----------: | :--------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|     根号     | `sqrt(x)`  | ![img](https://www.nowcoder.com/equation?tex=%5Csqrt%7Bx%7D&preview=true) | sqrt(9) (结果为 ![img](https://www.nowcoder.com/equation?tex=3&preview=true)) |
|    绝对值    | `fabs(x)`  | ![img](https://www.nowcoder.com/equation?tex=%20%5C%7C%20x%20%5C%7C&preview=true) | fabs(-7.6) (结果为 ![img](https://www.nowcoder.com/equation?tex=7.6&preview=true)) |
|   向上取整   | `ceil(x)`  | ![img](https://www.nowcoder.com/equation?tex=%20%5Clceil%20x%20%5Crceil&preview=true) | ceil(-7.6) (结果为 ![img](https://www.nowcoder.com/equation?tex=-7&preview=true)) |
|   向下取整   | `floor(x)` | ![img](https://www.nowcoder.com/equation?tex=%20%5Clfloor%20x%20%5Crfloor&preview=true) | floor(-7.6) (结果为 ![img](https://www.nowcoder.com/equation?tex=-8&preview=true)) |
|   四舍五入   | `round(x)` | ![img](https://www.nowcoder.com/equation?tex=%5B%20x%20%5D&preview=true) | round(-7.6) (结果为 ![img](https://www.nowcoder.com/equation?tex=-8&preview=true)) |
|    幂函数    | `pow(a,b)` | ![img](https://www.nowcoder.com/equation?tex=a%5Eb&preview=true) | pow(2,6) (结果为 ![img](https://www.nowcoder.com/equation?tex=64&preview=true)) |

#### 5、循环控制语句

- break：立即退出当前循环，不在执行循环中剩余语句。
- continue：跳过当前循环的剩余语句，直接进入下一次循环。

### 二、c++数据结构

#### 1、数组

##### 1）数组的声明与初始化

> 数组内元素的数据类型 数组名 [数组大小]

例如：`int arr[5]`

##### 2）数组的访问

​	通过数组的下标来访问，例如`arr[1]`；注意：

- 数组的下标默认从0开始

##### 3）数组的遍历

​	使用for循环来遍历数组下标，如：

```c++
int arr[5] = {10,20,30,40,50};
for(int i=0;i<5;i++)
{
    cout << arr[i] << endl;
}
```

##### 4）二维数组

- 声明：`int arr[3][4]`，生成一个3行4列的二维数组。

- 初始化：

  ```c++
  int arr[3][4]={
      {1,2,3,4},
      {5,6,7,8}.
      {9,10}
  } //其中没有指定元素的默认是0
  ```

- 访问：同一维数组，都是用下标来访问`arr[i][j]`

- 遍历：用嵌套的循环

  ```c++
  for(int i=0;i<3;i++)
  {
      for(int j=0;i<4;i++)
      {
          cout << arr[i][j] << endl;
      }
  }
  ```

##### ==5）vector——STL的数组==

> 连续的顺序的存储结构（和数组一样，但是长度可变）

###### >>>基本操作

- 构造：vector<类型> 名字(长度，[初值] )

```cpp
//一维数组
vector<int> arr (100,1);
//二维数组
vector<vector<int>> arr2(100,vector<int>(50,-1))//构建100行，50列，初值为-1的二维数组
```

- 尾接：.push_back_(元素)：把元素加在数组的最后
- 尾删：.pop_back_()：删除vector最后一个元素
- 获取长度：.size( ) 例如：i < arr.size()
- 清空： .clear（）
- 判空：.empty（）：如果vector为空，返回true，否则返回false
- 改变长度：.resize（新长度，[默认值])

###### >>> 适用情况

​	1、不卡常的情况下，数组都可以用vector；

​	2、数据太大，用数组会爆栈，这时候只能用vector