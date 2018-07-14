#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

struct A;

// �������С���ǳ�Ա��������͵Ĵ�С
union C{
	char ch1;
	int j;
};

/*
 1 2 4 = 8
 1 4 2 = 12
 2 1 4 = 8
 2 4 1 = 12 
 4 1 2 = 8
 4 2 1 = 8
*/
// struct û���κ�����ʱ��Ϊ1
// static ���Ͳ�������ڶ����С�� 

struct A {
//	static char a1;
//	int fun(); 
	char a1;
	short a3;
	int a2;
	char a4[10];
};

// ��Ա�����ṹ��Ľṹ��
// �ѽṹ���������
// �ṹ��A ��� int char short 4 1 2  
struct B 
{
	A b2; // 1 4 2 = 12 
	int b1;
	short b3;
}; 


int main ()
{
	// �����������͵�sizeof
	// long double �ȼ��� double long
	// ��ͬ���� long�ĳ��ȿ��ܲ�ͬ 4/8
	// ָ���С  32λ��4       64λ��8  
//	printf("sizeof(bool) = %d\n", sizeof(bool));// 1
//	printf("sizeof(char) = %d\n", sizeof(char));// 1
//	printf("sizeof(short) = %d\n", sizeof(short));// 2
//	printf("sizeof(int) = %d\n", sizeof(int));// 4
//	printf("sizeof(long) = %d\n", sizeof(long));// 4
//	printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));// 4
//	printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));// 4
//	printf("sizeof(long long) = %d\n", sizeof(long long));// 8
//	printf("sizeof(float) = %d\n", sizeof(float));// 4
//	printf("sizeof(double) = %d\n", sizeof(double));// 8
//	printf("sizeof(long double) = %d\n", sizeof(long double));// 16
//	printf("sizeof(double long) = %d\n", sizeof(double long));// 16

	printf("%d\n", sizeof(A)); // 20
	printf("%d\n", sizeof(B)); // 28
	
//	�������͵Ĵ�ӡ
	char char1 = 'a';
	bool b1 = true;
	short short1 = 1;
	int int1 = 1;
	unsigned int uint1 = 1;
	long long1 = 1;
	unsigned long ulong1 = 1;
	long long llong1 = 1;
	float float1 = 1.111;
	double  double1 = 1.1111;
	long double ldouble1 = 1.111;
	
	// %c �����ַ�  %05c  �޷���ӡ����ַ�0 
	printf("%5c\n", char1);// [    a]
	printf("%-5c\n", char1);// [a    ]
	printf("%2.5c\n", char1);// [ a   ]
	printf("%-2.5c\n", char1);// [a   ]
	
	// bool ʹ�� %d ��ӡ   false = 0  true = 1
	printf("%d\n", b1);
	
	// short   ʹ�� %d ��ӡ
	printf("%d\n", short1);
	
	//int 
	printf ("\n");
	printf("%d\n", int1); //  %u %d %ld ��ӡ������
	printf("%u\n", uint1); // %u %d ��ӡ������  uint1 = -1ʱ��,���벻��������4294967295 
	printf("%05d\n", int1);  // 00001
	printf("%02.5d\n", int1);  // 00001 ���ǰ�������ռλ����0 
	
	//long 
	printf("%ld\n", long1);  // %u %d %ld ��ӡ������ 
	
	// unsigned long 
	printf("%lu\n", ulong1);  // %u %d %ld ��ӡ������
	
	//long long 
	printf("%lld\n", llong1);  // %u %d %ld %lld ��ӡ������
	
	//float
	printf("%1.2f\n", float1);
	
	//double
	printf("%1.2f\n", double1);
	
	// long double
	printf("%1.2Lf\n", ldouble1);
	
	
	
	return 0; 
}

