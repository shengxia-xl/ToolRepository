#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
using namespace std;


/*
传入一个char*的字符指针

字符串为空，直接退出（assert断言退出）

声明int值，记录字符串的长度

char* tstr，保存一份临时的指针，用来做后移操作
（不需要，当传入的为字符指针时，已经有一份拷贝了）

while循环，用来判断指针的下一位是否是结束字符 '\0'
-不为空 长度加一
-为空 结束循环，返回长度
*/
int Mystrlen(char* str)
{
    assert(str != NULL);
    
    int str_len = 0;
    char* tstr = str;
    while (*tstr++ != '\0') {
        str_len++;
    }
    return str_len;    
}


int main() {
	
	string str = "abc";
	char astr[] = "123";
	char* pstr = "abc123";//warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
	
	cout<< str << endl;// abc
	// string不是c语言的内置数据 printf无法直接打印string  需要转换为char*
	str[0] = 'd';
	printf("%s\n", str.c_str());// dbc  
	str[4] = 'd';
	printf("%s\n", str.data());// dbc

	astr[0] = 'd';
	printf("%s\n", astr);// d23
	printf("%d\n",Mystrlen(astr)); // 3
	
	printf("%s\n", pstr);// abc123
	printf("%d",Mystrlen(pstr));// 6

	return 0;
}