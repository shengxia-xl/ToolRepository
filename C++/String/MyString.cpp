#include "iostream"
#include "assert.h"
#include "string.h"

using namespace std;

int main()
{
    /*当一个字符串常量出现于表达式中时，它的值是个指针常量。编译器把这个指定字符的一份copy存储在内存的某个位置，
    并存储一个指向第一个字符的指针。*/
    cout << *"xyz" << endl;//x
    cout << *"xyz"+1 << endl;//y的ascll码
    cout << "xyz"[2] << endl;//z
    //cout << *("xyz"+4) << endl;
    cout << "xyz"+1<< endl;//yz

    /*======等价于======*/
    cout << "/*======等价于======*/"<< endl;

    char *p="xyz";
    cout << *p << endl;//x
    cout << *p+1 << endl;//y的ascll码
    cout << char(*p+1) << endl;//y
    cout << p[2] << endl;//z
    cout << p+1<< endl;//yz
    return 0;
    
    cout<<""<<; 
}
