#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
using namespace std;


/*
����һ��char*���ַ�ָ��

�ַ���Ϊ�գ�ֱ���˳���assert�����˳���

����intֵ����¼�ַ����ĳ���

char* tstr������һ����ʱ��ָ�룬���������Ʋ���
������Ҫ���������Ϊ�ַ�ָ��ʱ���Ѿ���һ�ݿ����ˣ�

whileѭ���������ж�ָ�����һλ�Ƿ��ǽ����ַ� '\0'
-��Ϊ�� ���ȼ�һ
-Ϊ�� ����ѭ�������س���
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
	char* pstr = "abc123";//warning: deprecated conversion from string constant to ��char*�� [-Wwrite-strings]
	
	cout<< str << endl;// abc
	// string����c���Ե��������� printf�޷�ֱ�Ӵ�ӡstring  ��Ҫת��Ϊchar*
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