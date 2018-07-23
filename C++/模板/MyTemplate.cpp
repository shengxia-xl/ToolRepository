#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
void show(T t) {
	cout<<t<<endl;
}

template <typename T1, typename T2>
class A {
public:
	A(T1 t1, T2 t2);
	void myPrint();
private:
	T1 a;
	T2 b;
};

template <typename T1, typename T2>
A<T1, T2>::A(T1 t1, T2 t2):a(t1), b(t2) 
{
	cout<<"A()"<<endl;
}

template <typename T1, typename T2>
void A<T1, T2>::myPrint()
{
	cout<<a<<endl;
	cout<<b<<endl;
}

template <typename T1, typename T2, typename T3>
class AA: public A<T1, T2> {
public:
	AA(T1 t1, T2 t2, T3 t3);
	void myShow();
private:
	T1 a;
	T2 b;
	T3 c;
};

template <typename T1, typename T2, typename T3>
AA<T1,T2,T3>::AA(T1 t1, T2 t2, T3 t3):A<T1, T2>(t1-1,t2-1),a(t1),b(t2),c(t3)
{
	
}

template <typename T1, typename T2, typename T3>
void AA<T1, T2, T3>::myShow()
{
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
}

int main ()
{
//	int a = 5;
//	double b = 3.0;
//	bool c = false;
//	char d = 'a';
//	show(a); // 5
//	show(b); // 3
//	show(c); // 0
//	show(d); // a
	
	
//	A<int, bool> a1(1, true);
//	A<double, char> a2(2, 'a');
//	
//	a1.myPrint(); // 1 1
//	a2.myPrint(); // 2 a
	
	AA<int, int , char> aa1(1, 2, 't');
	aa1.myPrint();// 0 1    ≥ı ºªØ ±£¨ A<T1, T2>(t1-1,t2-1)    
	aa1.myShow();// 1 2 t
	
	return 0;
}
