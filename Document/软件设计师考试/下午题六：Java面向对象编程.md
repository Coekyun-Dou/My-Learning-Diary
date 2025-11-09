-------
### ！！！做题思路：

- 找有哪些类，类中有哪些成员变量（属性）、有哪些方法；**只要被定义出来的属性和方法就一定会被调用**
- 把被调用过的成员属性和方法排除
- 剩下的没有被调用过的成员属性和方法就是考试需要填写的

类

```java
class a(){
	//成员变量（属性） -赋值/取值
    private string name;
    
    //方法 -一定会被调用
    public string fun1(){}
    
    //方法
    public void fun2(){}
}
```

------

### 类

1、类一定有初始化的地方 new

2、抽象类必须有实现，抽象类里面的抽象方法必须在子类里面实现

3、子类继承父类，那么子类就具有父类的方法

### 属性

1、属性一般情况下是private

2、属性需要被设置值，也需要被获取值

### 方法

1、关心返回值、参数

2、方法里面的参数一定在方法体里面被调用

3、子类继承父类，那么子类就具有父类的方法

```java
有时候找出来：
//一个类
class Memento{
    //一个属性、两个方法
    string state;
    Memento(state){}
    getState(){}
}

//另一个类
class Originator{
    //一个属性、四个方法
    string state;
    setState(state){}
    getState(){}
    saveStateToMemento(){}
    getStateFromMemento(){}
}
```



