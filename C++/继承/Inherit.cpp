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
����
ͬһ�������ڣ���������ͬ�������б�ͬ��ʵ������  ��̬��
 
��д
�Ӹ����У���������ͬ��������д����ķ���������ͬ����������virtual�ؼ��֡� 

����/����/ 
�Ӹ����У���������ͬ����������virtual�ؼ������Σ������ͬ���������������ˡ� 

*/
 
int main ()
{
//	AA* aa = new A();  �������ֵ������ָ��   ����ת������ 
//	A* a = new AA(); //  �������ֵ������ָ��
//	��̬��  ������ʱ����֪�������ĸ����� 
//	a->f();// A::f() û��virtualʱ��A::f  ��Ϊvirtualʱ�� AA::f 
	
	
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
	
	// �麯����  ��û���麯��ʱ��sizeof(C)  = 1.  �����麯��ʱ�� sizeof(C) = 8  
	printf("%d\n", sizeof(C));

	return 0;
}
