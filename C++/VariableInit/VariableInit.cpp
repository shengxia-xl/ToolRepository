#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
using namespace std;

/*
基本类型：

全局变量：
#define CONST 100  // 100
int *p1; // 输出化为NULL 无法打印(如果试图打印*p1则会发生段错误，因为p1指向的是一个NULL地址。)
int a[2]; // a[0] = 0 a[1] = 0
int b; // 0
static int c; // 0

main方法中的变量
int d; // 随机值
static int e; // 0 
int f[2];// f[0] f[1] 都为随机值
int *p2; // 随机分配地址，可以打印


结论：
全局变量、常量、静态变量(包括全局和局部的)，未显式初始化被默认地初始化时0或NULL。

而局部的非静态变量未显式初始化时是一个随机的数，一般是个很大的数。
*/

/*
class A{
public:
    int value;
    A(){
        cout<<"Intitialize A"<<endl;
        value=3;
    }
};

A a1;

int main(){
    A a2;
    static A a3;
    cout<<a1.value<<endl;
    cout<<a2.value<<endl;
    cout<<a3.value<<endl;
    return 0;
}

Intitialize A // a1初始化
Intitialize A // a2初始化
Intitialize A // a3初始化
3 // a1.value
3 // a2.value
3 // a3.value

结论：
不论是在全局还是局部作用域，类类型变量都会调用“默认构造函数”进行初始化。
所谓“默认构造函数”就是指空参数的构造函数。

1.对象在全局作用域或为静态局部对象时，则类的内置成员变量被初始化为0.
2.对象在局部作用域定义时，则类的内置成员变量不被初始化为0.
3.对于类类型成员按照其自身的（合成）默认构造函数进行初始化。——重要
*/

/*
class A{
public:
    int value;
};

class B{
public:
    int value;
    A a;
};

B b1;

int main(){
    B b2;
    cout<<b1.value<<"\t"<<b1.a.value<<endl;// 0 0
    cout<<b2.value<<"\t"<<b2.a.value<<endl;// 随机值 随机值
    return 0;
}

b2.a.value 的值：b2为局部作用域中，b2.a则也在对应的局部作用域中，则b2.value和b2.a.value都为随机值。
*/

/*
class A{
public:
    int value;
    A(){
        value=5;
    }
};

class B{
public:
    int value;
    A a;
};

B b1;

int main(){
    B b2;
    cout<<b1.value<<"\t"<<b1.a.value<<endl;// 0 5
    cout<<b2.value<<"\t"<<b2.a.value<<endl;// 随机值 5
    return 0;
}

与上面的例子对应，但是b2中会调用了A中的空参数的构造函数。A.value被赋值为5。
*/

int main() 
{
    
    return 0;
}
