#include <stdio.h>
#include <iostream>
#include <assert.h>

using namespace std;

class A {
public:		
	virtual void f() {
		printf("A::f()\n");
	}
};

class AA :public A {
public:
	void f() {
		printf("AA::f()\n");
	}
};

class B {
public:		
	virtual void f() {
		printf("B::f()\n");
	}
};

class AB : public A,public B{
public:
	void f() {
		printf("AB::f()\n");
	}
};

class C {
	virtual void f();
};

/*
重载
同一个函数内，方法名相同，参数列表不同，实现重载  静态绑定
 
重写
子父类中，方法名相同。子类重写父类的方法。父类同名方法中有virtual关键字。 

覆盖/隐藏/ 
子父类中，方法名相同。不管有无virtual关键字修饰，父类的同名方法都被隐藏了。 

*/
 
int main ()
{
//	AA* aa = new A();  父类对象赋值给子类指针   类型转换错误 
//	A* a = new AA(); //  子类对象赋值给父类指针
//	动态绑定  在运行时，才知道调用哪个方法 
//	a->f();// A::f() 没有virtual时，A::f  当为virtual时， AA::f 
	
	
	A* a = new A();
	B* b = new B();
	AB* ab = new AB();
	
	// AB::f()
	ab->f(); 
	a = ab;
	// AB::f()
	a->f();
	// AB::f()
	b = ab;
	b->f();
	
	// 虚函数表  当没有虚函数时，sizeof(C)  = 1.  当有虚函数时， sizeof(C) = 8  
	printf("%d\n", sizeof(C));

	return 0;
}
