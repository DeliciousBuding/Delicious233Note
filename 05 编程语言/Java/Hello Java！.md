- CS61B Spring2021 自学笔记
- 以C++面向对象为基础学习Java
# 编译与运行

![[Pasted image 20250209221742.png]]通过**javac**编译器将.java编译成.class文件，然后再用**java**解释器运行


# 对象的创建与初始化

![[6f809c937bc2dc183dbe54c11312f8d.jpg]]**Java对象**类比**C++对象** 很相似，对吧

Dog d=new Dog();


# 创建对象数组

![[Pasted image 20250210111821.png]]
创建对象数组
	new Dog()


# Static vs Non-static 静态成员和非静态成员
## Non-static
通过直接对“狗”这一对象进行操作和创建一个对象再进行操作

- **调用方式**：静态方法使用类名调用，如 “Dog.makeNoise ()”；实例方法使用实例名调用，如 “maya.makeNoise ()”。
- **访问实例变量**：静态方法无法访问实例变量，因为没有特定实例。例如图中静态方法 “makeNoise ()” 不能访问 “weightInPounds” 变量。
- **代码示例**：给出了静态方法和非静态方法的代码示例。静态方法的 “makeNoise ()” 直接输出 “Bark!”；非静态方法的 “makeNoise ()” 根据 “weightInPounds” 的值输出不同内容。同时也展示了两种方法的调用方式。

### 静态方法调用 和 非静态方法调用
![[Pasted image 20250210114253.png]]

## 两种方法实现比较dog大小
```java
public static Dog maxDog(Dog d1, Dog d2)//要用static关键字标记，说明这是一个静态方法  
{  
    if (d1.weightInPounds > d2.weightInPounds)  
    {  
        return d1;  
    }  
    return d2;  
}  
  
public Dog maxDog(Dog d2)  
{  
    if (this.weightInPounds > d2.weightInPounds)  
    {  
        return this;  
    }  
    return d2;  
}
```
- 静态版本 直接使用类名进行调用
- 实例化版本 需要初始化类
## static variable 静态变量
- 静态变量：所有dogs的共有属性，比如狗的数量
- 避免访问**特定对象**的静态变量 
- 访问静态成员时 直接使用类名


# Q&A
	Why does Java force us to use classes?
	Why hava static methods at all?
- **"To take choices away from the programmer." :
	  focus on a singal task
	  fewer ways to do things often means less complexity

# Using Helper Method
	make the question smaller

# Testing 
	Ad-hoc testing VS Junit











