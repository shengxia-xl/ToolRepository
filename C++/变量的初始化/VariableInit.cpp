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

/*------------------------------------------------------------------------*/
/*
class Test
{
private :
      int var1;
// int var11= 4; 错误的初始化方法
      const int var2 ;
// const int var22 =22222; 错误的初始化方法
      static int var3;
// static int var3333=33333; 错误，只有静态常量成员才能直接赋值来初始化
      static const int var4=4444; //正确，静态常量成员可以直接初始化
      static const int var44;
public:
      Test(void);
       ~Test(void);
};

int Test::var3 = 3333333; //静态成员的 正确的初始化方法

// int Test::var1 = 11111;; 错误 静态成员才能初始化
// int Test::var2 = 22222; 错误
// int Test::var44 = 44444; // 错误的方法，提示重定义

Test::Test(void) :var1(11111),var2(22222) //正确的初始化方法 ， var3(33333) 不能在这里初始化
{
    var1 =11111; //正确, 普通变量也可以在这里初始化
    //var2 = 222222; 错误，因为常量不能赋值，只能在 “constructor initializer （构造函数的初始化列表）” 那里初始化
          
    var3 =44444; //这个赋值时正确的，不过因为所有对象一个静态成员，所以会影响到其他的，这不能叫做初始化了吧
}


对于常量型成员变量和引用型成员变量的初始化，必须通过构造函数初始化列表的方式进行。
在构造函数体内给常量型成员变量和引用型成员变量赋值的方式是行不通的。


class BClass
{
public:
    BClass() : i(1), ci(2), ri(i) // 对于常量型成员变量和引用型成员变量，必须通过
    { // 参数化列表的方式进行初始化。在构造函数体内进
    } // 行赋值的方式，是行不通的。

private:
    int i; // 普通成员变量
    const int ci; // 常量成员变量
    int &ri; // 引用成员变量
    static int si; // 静态成员变量
    //static int si2 = 100; // error: 只有静态常量成员变量，才可以这样初始化
    static const int csi; // 静态常量成员变量
    static const int csi2 = 100; // 静态常量成员变量的初始化(Integral type) (1)
    static const double csd; // 静态常量成员变量(non-Integral type)
    //static const double csd2 = 99.9; // error: 只有静态常量整型数据成员才可以在类中初始化
};

    // 静态成员变量的初始化(Integral type)
    int BClass::si = 0;
    // 静态常量成员变量的初始化(Integral type)
    const int BClass::csi = 1;
    // 静态常量成员变量的初始化(non-Integral type)
    const double BClass::csd = 99.9;
    // 在初始化(1)中的csi2时，根据Stanley B. Lippman的说法下面这行是必须的。
    // 但在VC2003中如果有下面一行将会产生错误，而在VC2005中，下面这行则可有可无，这个和编译器有关。
    const int BClass::csi2;
*/
/*------------------------------------------------------------------------*/


int main() 
{
    return 0;
}
