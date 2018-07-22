#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

struct A;

// 联合体大小就是成员中最大类型的大小
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
// struct 没有任何类型时，为1
// static 类型不会计算在对象大小中

struct A {
//    static char a1;
//    int fun();
    char a1;
    short a3;
    int a2;
    char a4[10];
};

// 成员包含结构体的结构体
// 把结构体拆开来计算
// 结构体A 拆成 int char short 4 1 2  
struct B
{
    A b2; // 1 4 2 = 12
    int b1;
    short b3;
};


int main ()
{
    // 基本数据类型的sizeof
    // long double 等价于 double long
    // 不同环境 long的长度可能不同 4/8
    // 指针大小  32位：4       64位：8  
//    printf("sizeof(bool) = %d\n", sizeof(bool));// 1
//    printf("sizeof(char) = %d\n", sizeof(char));// 1
//    printf("sizeof(short) = %d\n", sizeof(short));// 2
//    printf("sizeof(int) = %d\n", sizeof(int));// 4
//    printf("sizeof(long) = %d\n", sizeof(long));// 4
//    printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));// 4
//    printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));// 4
//    printf("sizeof(long long) = %d\n", sizeof(long long));// 8
//    printf("sizeof(float) = %d\n", sizeof(float));// 4
//    printf("sizeof(double) = %d\n", sizeof(double));// 8
//    printf("sizeof(long double) = %d\n", sizeof(long double));// 16
//    printf("sizeof(double long) = %d\n", sizeof(double long));// 16

    printf("%d\n", sizeof(A)); // 20
    printf("%d\n", sizeof(B)); // 28
    
//    基本类型的打印
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
    
    // %c 单个字符  %05c  无法打印多的字符0
    printf("%5c\n", char1);// [    a]
    printf("%-5c\n", char1);// [a    ]
    printf("%2.5c\n", char1);// [ a   ]
    printf("%-2.5c\n", char1);// [a   ]
    
    // bool 使用 %d 打印   false = 0  true = 1
    printf("%d\n", b1);
    
    // short   使用 %d 打印
    printf("%d\n", short1);
    
    //int
    printf ("\n");
    printf("%d\n", int1); //  %u %d %ld 打印都可以
    printf("%u\n", uint1); // %u %d 打印都可以  uint1 = -1时候,编译不会出错，输出4294967295
    printf("%05d\n", int1);  // 00001
    printf("%02.5d\n", int1);  // 00001 还是按照最大的占位补齐0
    
    //long
    printf("%ld\n", long1);  // %u %d %ld 打印都可以
    
    // unsigned long
    printf("%lu\n", ulong1);  // %u %d %ld 打印都可以
    
    //long long
    printf("%lld\n", llong1);  // %u %d %ld %lld 打印都可以
    
    //float
    printf("%1.2f\n", float1);
    
    //double
    printf("%1.2f\n", double1);
    
    // long double
    printf("%1.2Lf\n", ldouble1);
    
    
    
    return 0;
}