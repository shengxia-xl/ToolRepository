#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;


int main ()
{	
	//C++��֧��ֱ��ʹ�ö����Ƶ�����ֻ֧��8,10,16���ֽ��Ƶ�ֱ�Ӷ���
	int i_Decimal = 10;
	int i_Octal = 010;
	int i_Hexadecimal = 0X10;
	
	printf("%d\n", i_Decimal);
	// ֻ��Сд 'o' ����д 'O' ��ӡ '%O' 
	printf("i_Octal��ʮ���ƣ� = %d, i_Octal���˽��ƣ� = %o\n", i_Octal, i_Octal);// 8 10
	// ��д Сд 'x'/'X' �����Դ�ӡ��16���� 
	printf("i_Hexadecimal��ʮ���ƣ� = %d, i_Hexadecimal��ʮ�����ƣ� = %X\n", i_Hexadecimal, i_Hexadecimal);// 16 10
	
	// ����printf�Ĳ���  (����ȱʡ)
	printf("i_Octal��ʮ���ƣ� = %d, i_Octal���˽��ƣ� = %o\n", i_Octal);// 8 ���ֵ
	
	// string ��Ҳ����غ���  stringת����ֽ��Ƶ����� ���໥ת�� 
	// bitset ֱ��ת��Ϊ2���Ƶ��ַ��� 
	bitset<8> bit_Decimal(10);// bitset Ϊ8λ�� ��ʼ��Ϊʮ���Ƶ�10 
	bitset<8> bit_Octal(010);//  bitset Ϊ8λ�� ��ʼ��Ϊ�˽��Ƶ�10
	bitset<8> bit_Hexadecimal(0X10); // bitset Ϊ8λ�� ��ʼ��Ϊʮ�����Ƶ�10

	cout<<bit_Decimal.to_string()<<endl; // 00001010 
	cout<<bit_Octal.to_string()<<endl; // 00001000
	cout<<bit_Hexadecimal.to_string()<<endl; // 00001010


	// ��ͬ���� ����ֱ�������� 
	// ע�� bitset����ӡʱ�̶���λ��δ��ֵ��λ��ӡ���� 
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
	
	// λ������ << >> 
	
	return 0;
}
