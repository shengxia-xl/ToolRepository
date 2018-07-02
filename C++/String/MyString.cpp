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

3.有时需要使用一个临时的指针，来记录起始位置（具体参考Mystrcat，Mystrcpy）

4.两个char类型的运算，结果为int型

*/

/**************************************************************************************/


/*
返回字符串长度

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
/*
测试代码
string str = "|str|";
string str_null = "";
string str_char0 = "\0";
char astr[] = "|astr|";
const char* pstr = "|pstr|";
char archar[20] ={'s', 't', 'r'}; 

printf("%zu\n", Mystrlen(str.data()));// 5
printf("%zu\n", Mystrlen(str_null.data()));// 0 ""长度为0
printf("%zu\n", Mystrlen(str_char0.data()));// 0 "\0"长度为0
printf("%zu\n", Mystrlen(astr)); // 6
printf("%zu\n", Mystrlen(pstr)); // 6
printf("%zu\n", Mystrlen(archar)); // 6

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

/**************************************************************************************/
/*
字符串src附加到dest后，返回的是dest
    
使用一个临时的指针，用循环来指向dest的末尾，再把src中的指针接续

while (*cp++ = *src++)
等价于
while(*cp)
{
    *cp = *src;
    cp++;
    src++;
}

解析：
while( *cp++ = *src++ )
首先*cp = *src 赋值
然后判断表达式的值while(*cp)
然后自增cp++, src++
所以，整个表达式的结束判断就在于while(*cp)
如果*cp=='\0'，因为'\0'对应的ascii码就是0，所以判断就为假，也就退出循环了
    
*/
/*
测试代码
string str = "|str|";
string str_null = "";
string str_char0 = "\0";
char astr[] = "|astr|";
const char* pstr = "|pstr|";
char archar[5] ={'s', 't', 'r'}; 

printf("%s\n", Mystrcat(astr, str.c_str()));// |astr||str|
printf("%s\n", Mystrcat(astr, pstr));// |astr||str||pstr|
printf("%s\n", Mystrcat(archar, str.c_str()));// str|str|   *** 不会造成数组越界

*/
char* Mystrcat(char* dest, const char* src)
{
    assert((dest != NULL) && (src != NULL));
    printf("%d\n", __LINE__);
    
    char* cp = dest;
    while (*cp) {
        cp++;
    }
    
    while (*cp++ = *src++) {
    }
    
    return dest;
}

/**************************************************************************************/

/*
字符串src拷贝到dest

直接复制

考虑dst和src内存重叠的情况，strcpy该怎么实现

char s[10]="hello";

strcpy(s, s+1); //应返回ello，

//strcpy(s+1, s); //应返回hhello，但实际会报错，因为dst与src重叠了，把'\0'覆盖了

所谓重叠，就是src未处理的部分已经被dst给覆盖了，只有一种情况：src<=dst<=src+strlen(src)

char * strcpy(char *dst,const char *src)
{
    assert(dst != NULL && src != NULL);

    char *ret = dst;

    my_memcpy(dst, src, strlen(src)+1);

    return ret;
}

char *my_memcpy(char *dst, const char* src, int cnt)
{
    assert(dst != NULL && src != NULL);

    char *ret = dst; 

    if (dst >= src && dst <= src+cnt-1) //内存重叠，从高地址开始复制
    {
        dst = dst+cnt-1;
        src = src+cnt-1;
        while (cnt--)
            *dst-- = *src--;
    }
    else    //正常情况，从低地址开始复制
    {
        while (cnt--)
            *dst++ = *src++;
    }
    
    return ret;
}

*/

/*
测试代码
string str = "|str|";
string str_null = "";
string str_char0 = "\0";
char astr[] = "|astr|";
const char* pstr = "|pstr|";

printf("%s\n", Mystrcpy(astr, str.c_str()));// |str|
printf("%s\n", Mystrcpy(astr, str_null.c_str()));// 为空
printf("%s\n", Mystrcpy(astr, pstr));// |pstr|
*/
char* Mystrcpy(char* dest, const char* src)
{
    assert((dest != NULL)&&(src != NULL));
    // https://www.cnblogs.com/yangsisi99/p/5903128.html
    // 关于为何改方法返回的是局部指针
    char* tchar = dest; // 记录起始位置
    while (*dest++ = *src++) {
        
    }
    return tchar;
}

/**************************************************************************************/

/*
比较字符串str1，str2
返回值：返回整数值，如果dest > source,则返回值大于0;
如果dest = source,则返回值等于0;
如果dest < source ,则返回值小于0;
字符大小是按照字符的字典序列进行排列的。

当str1 不为空  且 str2 不为空  str1 等于 str2 时，指针才++
最后做减法运算
*/

/*
string str_cmp1 = "|cmp1|";
string str_cmp2 = "|cmp2|";
string str_cmp12 = "|cmp1||cmp2|";
const char* c_cmp1 = "|cmp1|";
char ar_cmp1[6] ={'|', 'c', 'm', 'p', '1', '|'};
char ar_cmp2[7] ={'|', 'c', 'm', 'p', '2', '|'};
	
printf("%d\n", '|'); // 124
printf("%d\n", Mystrcmp(str_cmp1.c_str(), str_cmp2.c_str()));// -1
printf("%d\n", Mystrcmp(str_cmp1.c_str(), str_cmp12.c_str()));// -124
printf("%d\n", Mystrcmp(str_cmp1.c_str(), c_cmp1));// 0
printf("%d\n", Mystrcmp(str_cmp1.c_str(), ar_cmp1));// 0 *** string 最后没有比较'/0'
printf("%d\n", Mystrcmp(str_cmp2.c_str(), ar_cmp2));// 0 *** 指针，数组 在什么情况下会自动初始化？
*/
int Mystrcmp( const char* str1, const char* str2 )
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	
	while (*str1 && *str2 && (*str1 == *str2)) {
		str1 ++;
		str2 ++;
	}
	
	return *str1 - *str2;
}


int main() {
    
    string str = "abc";
    string str_null = "";
    string str_char0 = "\0";
    char astr[] = "123";
    char* pstr = "abc123";//warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
    const char* pstr_c = "abc123";// 不会有警告

    // string不是c语言的内置数据 printf无法直接打印string  需要转换为char*
    cout<< str << endl;// abc
    printf("%s\n", str.c_str());
    printf("%s\n", str.data());// dbc

    // 下标引用
    str[0] = 'd';
    printf("%s\n", str.c_str());// dbc  
    str[3] = 'd';
    printf("%s\n", str.data());// dbcd
    astr[0] = 'd';
    printf("%s\n", astr);// d23
    astr[3] = 'd';
    printf("%s\n", astr);// d23d
    arstr[0] = 'd';
    printf("%s\n", arstr);// d23
    arstr[3] = 'd';
    printf("%s\n", arstr);// d23d


    return 0;
}
