#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

/*
 1 2 4 = 8
 1 4 2 = 12
 2 1 4 = 8
 2 4 1 = 12 
 4 1 2 = 8
 4 2 1 = 8
*/
// struct û���κ�����ʱ��Ϊ1
// static ���Ͳ�������ڶ����� 
struct A {
//	char a1;
//	int fun(); 
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
	
	
	printf("%d", sizeof(A));
	return 0; 
}

