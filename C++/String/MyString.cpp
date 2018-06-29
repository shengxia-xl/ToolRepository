#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
using namespace std;

/*
方法中的注意点：

1.C风格字符串中的方法，参数为const char*
str.c_str()  返回 const char*
str.data()  返回 const char*

2.返回值长度值时，变量类型为size_t 打印时使用'%ud' '%ux'

*/

/*
传入一个char*的字符指针
(修改为：传入一个const char*)

字符串为空，直接退出（assert断言退出）

声明int值，记录字符串的长度
(修改为：使用size_t)

char* tstr，保存一份临时的指针，用来做后移操作
（不需要，当传入的为字符指针时，已经有一份拷贝了）

while循环，用来判断指针的下一位是否是结束字符 '\0'
-不为空 长度加一
-为空 结束循环，返回长度
*/
size_t Mystrlen(const char* str)
{
    assert(str != NULL);
    
    size_t str_len = 0;
    while (*str++ != '\0') {
        str_len++;
    }
    return str_len;    
}

int main() {
    
    string str = "abc";
    string str_null = "";
    string str_char0 = "\0";
    char astr[] = "123";
    char* pstr = "abc123";//warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
    const char* pstr_c = "abc123";// 不会有警告

    cout<< str << endl;// abc
    // string不是c语言的内置数据 printf无法直接打印string  需要转换为char*
    str[0] = 'd';
    printf("%s\n", str.c_str());// dbc  
    str[4] = 'd';
    printf("%s\n", str.data());// dbc

    printf("%zu\n", Mystrlen(str.data()));// 3 
    printf("%zu\n", Mystrlen(str_null.data()));// 0 ""长度为0
    printf("%zu\n", Mystrlen(str_char0.data()));// 0 "\0"长度为0
    
    astr[0] = 'd';
    printf("%s\n", astr);// d23
    printf("%zu\n",Mystrlen(astr)); // 3
    
    printf("%s\n", pstr);// abc123
    printf("%zu",Mystrlen(pstr));// 6

    return 0;
}
