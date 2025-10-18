/*************************************************************************
	> File Name: 29.typedef.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 01 Dec 2023 12:16:37 AM CST
 ************************************************************************/
/**
 * typedef 是将某类型变量名变成某类型别名
*/

#include<stdio.h>
#include<stdlib.h>

typedef long long LL; // 长整型变量名 -> 长整型类型名
typedef int (*Arr2Dim10)[10]; // 数组指针变量名 -> 指针数组类型名
typedef void (*Func)(); // 函数指针变量名 -> 函数指针类型名

void test() {
	printf("hello function pointer\n");
	return ;
}

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	rand();
	LL a;
	printf("sizeof(a) = %lu\n", sizeof(a));
	int arr[5][10];
	Arr2Dim10 p = arr; //数组指针类型
	Func p2 = test;
	p2();
	return 0;
}
