#include <iostream>
#include <stdio.h>

using namespace std;

// 单线程 单例模式 

class Singleton {
private:
	Singleton(){} 
	~Singleton(){} 
	static Singleton* instance;
	 
public:
	static Singleton* getInstance() {
		if (instance == NULL) {
			instance = new Singleton();
		}
		return instance;
	}
};

/*
程序结束时，自动析构单例 
*/

class A {
private:
	A(){}
	static A* a;
	class XigouA {
		~XigouA(){
			if (a != NULL) {
				delete a;
				a = NULL; // delete 之后  把指针设置为NULL
			}
		}
	};
	static XigouA xigouA; 

public:
	static A* getInstance() {
		if (a == NULL) {
			if (a == NULL) {
				a = new A();	
			}
		}
		return a;
	}
	
};

// 不进行初始化，会发生错误   undefined reference to Singleton::instance 
Singleton* Singleton::instance = NULL;
A* A::a = NULL;

//多线程  加锁 

class duoxiancheng {
private:
	duoxiancheng() {
		pthread_mutex_init(&mtx,0);
	}
	~duoxiancheng();
	
	static duoxiancheng* dxc;
	
public:
	static pthread_mutex_t mtx;
	static duoxiancheng* getInstance() {
		if (dxc == NULL) {
			pthread_mutex_lock(&mtx);
			dxc = new duoxiancheng();
			pthread_mutex_unlock(&mtx);
		}
		return dxc;
	}	
}; 

pthread_mutex_t duoxiancheng::mtx;
duoxiancheng* duoxiancheng::dxc = NULL;

// 懒汉式 在需要时才加载，有多线程风险 需要加锁 

class lanhan {
private:
	lanhan() {
		pthread_mutex_init(&mtx,0);
	}
	
public:
	static pthread_mutex_t mtx;
	static lanhan* getInstance(){
		pthread_mutex_lock(&mtx);
		static lanhan lh;
		pthread_mutex_unlock(&mtx);
		return &lh;
	}
}; 

pthread_mutex_t lanhan::mtx;


//饿汉式  创建时，直接初始化，没有多线程风险 

class ehan {
private:
	ehan(){
	}
	static ehan* eh;

public:
	static ehan* getInstance() {
		return eh;
	}
}; 

ehan* ehan::eh = new ehan();



int main()
{
	Singleton* sl = Singleton::getInstance();
	return 0; 
}