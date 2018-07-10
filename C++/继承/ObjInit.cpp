#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

class A 
{
public:
	A() 
	{
		a1 = 1;
		printf("A()\n");
//		printf("%d\n", __LINE__);	
	}
	~A() 
	{
		printf("~A()\n");
	}
	void f() 
	{
		printf("A::f()\n");	
	}
	
public:
	int a1;
};

class B {
public:		
	B() 
	{
		a1= 2;
		printf("B()\n");	
//		printf("%d\n", __LINE__);
	}
	~B() 
	{
		printf("~B()\n");
	}
	
	void f() 
	{
		printf("B::f()\n");	
	}
public:
	int a1;
};

class C : public B, public A 
{
public:
	C():A(),B()
	{
		a1 = 3;
		printf("C()\n");
//		printf("%d\n", __LINE__);	
	}
	~C() 
	{
		printf("~C()\n");
	}
	void f() 
	{
		printf("C::f()\n");	
	}
public:
	B b;
	A a;
	A a2;
	int a1;
private:
	A a3;
	
};

class D: public C{
public:
	D():C()
	{
		a1 = 4;
		printf("D()\n");	
	}
	~D() 
	{
		printf("~D()\n");
	}
	
	void f() 
	{
		printf("D::f()\n");	
	}
public:
	int a1;
};


int main() 
{
	C c;
//	printf("%d\n",c.A::a1); // 1
//	printf("%d\n",c.B::a1); // 2
//	printf("%d\n",c.C::a1); // 3
//	printf("%d\n",c.a1); //3
//	c.A::f(); // A::f()
//	c.B::f(); // B::f()
//	c.C::f(); // C::f()
//	c.f();// C::f()
	D d;
//	printf("%d\n",d.a1); // 4
//	d.f(); // D::f()


	return 0;
}
