#include <iostream>
#include <stdio.h>

using namespace std;

class A {
public:
	int f();
	int f() const; // 属于重载 
	
	int g();
	int g(const int a); //属于重载 
	
	int t();
//	const int t();  // 不算重写 
};

int main()
{
	// 对于const 函数重载可看做是对隐含的指针this的参数重载
	return 0; 
}