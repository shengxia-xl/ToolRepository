#include "iostream"
#include "assert.h"
#include "string.h"

using namespace std;

int main()
{
    /*��һ���ַ������������ڱ��ʽ��ʱ������ֵ�Ǹ�ָ�볣���������������ָ���ַ���һ��copy�洢���ڴ��ĳ��λ�ã�
    ���洢һ��ָ���һ���ַ���ָ�롣*/
    cout << *"xyz" << endl;//x
    cout << *"xyz"+1 << endl;//y��ascll��
    cout << "xyz"[2] << endl;//z
    //cout << *("xyz"+4) << endl;
    cout << "xyz"+1<< endl;//yz

    /*======�ȼ���======*/
    cout << "/*======�ȼ���======*/"<< endl;

    char *p="xyz";
    cout << *p << endl;//x
    cout << *p+1 << endl;//y��ascll��
    cout << char(*p+1) << endl;//y
    cout << p[2] << endl;//z
    cout << p+1<< endl;//yz
    return 0;
    
    cout<<""<<; 
}
