#include <iostream>

using namespace std;

class B     
{  
    char ch;   
//	int a;  
    virtual void func0()  {  }   
};   

class C    
{  
    char ch1;  
    char ch2;  
//    int b;
    virtual void func()  {  }    
//    virtual void func1()  {  }   
};

class E: public B, virtual public C  
{     
    int e;     
    virtual void func0()  {  }   
//    virtual void func1()  {  }  
}; 


int main()
{
	cout<< sizeof(B) <<endl; //  16
	cout<< sizeof(C) <<endl; //  16
	cout<< sizeof(E) <<endl; // 32

	return 0;	
}
