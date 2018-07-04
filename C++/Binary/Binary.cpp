#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;


int main ()
{	
	//C++不支持直接使用二进制的数，只支持8,10,16三种进制的直接定义
	int i_Decimal = 10;
	int i_Octal = 010;
	int i_Hexadecimal = 0X10;
	
	printf("%d\n", i_Decimal);
	// 只能小写 'o' ，大写 'O' 打印 '%O' 
	printf("i_Octal（十进制） = %d, i_Octal（八进制） = %o\n", i_Octal, i_Octal);// 8 10
	// 大写 小写 'x'/'X' 都可以打印出16进制 
	printf("i_Hexadecimal（十进制） = %d, i_Hexadecimal（十六进制） = %X\n", i_Hexadecimal, i_Hexadecimal);// 16 10
	
	// 关于printf的测试  (参数缺省)
	printf("i_Octal（十进制） = %d, i_Octal（八进制） = %o\n", i_Octal);// 8 随机值
	
	// string 中也有相关函数  string转与各种进制的整数 的相互转换 
	// bitset 直接转换为2进制的字符串 
	bitset<8> bit_Decimal(10);// bitset 为8位， 初始化为十进制的10 
	bitset<8> bit_Octal(010);//  bitset 为8位， 初始化为八进制的10
	bitset<8> bit_Hexadecimal(0X10); // bitset 为8位， 初始化为十六进制的10

	cout<<bit_Decimal.to_string()<<endl; // 00001010 
	cout<<bit_Octal.to_string()<<endl; // 00001000
	cout<<bit_Hexadecimal.to_string()<<endl; // 00001010


	// 不同进制 可以直接做运算 
	// 注意 bitset　打印时固定８位　未赋值的位打印０　 
	// & | ~ ^ 
	cout<< bitset<8> (10 & 13)<<endl;// 1010 & 1101 1000 
	cout<< bitset<8> (10 & 013)<<endl;// 1010 & 1011 1010
	cout<< bitset<8> (10 & 0x13)<<endl;// 1010 & 10011 10
	
	cout<< bitset<8> (10 | 13)<<endl;// 1010 | 1101 1111 
	cout<< bitset<8> (10 | 013)<<endl;// 1010 | 1011 1011
	cout<< bitset<8> (10 | 0x13)<<endl;// 1010 | 10011 11011
	
	cout<< bitset<8> (10 ^ 13)<<endl;// 1010 ^ 1101 0001 
	cout<< bitset<8> (10 ^ 013)<<endl;// 1010 ^ 1011 0001
	cout<< bitset<8> (10 ^ 0x13)<<endl;// 1010 ^ 10011 11001
	
	cout<< bitset<8> (~13)<<endl;// ~1101 0010
	cout<< bitset<8> (~013)<<endl;// ~1011 0100
	cout<< bitset<8> (~0x13)<<endl;// ~10011 01100
	
	// 位移运算 << >> 
	
	return 0;
}
