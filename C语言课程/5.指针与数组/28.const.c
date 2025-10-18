/*************************************************************************
	> File Name: 28.const.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 30 Nov 2023 11:54:29 PM CST
 ************************************************************************/

/**
 * 1.const int *p; -> p是一个 指针，指向 整型 常量
 * 2.int const *p; -> p是一个 指针，指向 常量 整型
 * 3.int *const p; -> p是一个 常量 指针，指向 整型
 * 4.float (*p[5])[10]; -> p是一个 指针数组，指向 浮点型数组 （p是数组有5个空间的指针，每个空间中存放一个float[10]）
 * 
 * 从后往前读，翻译如下：
 * p就读【p是一个】
 * *就读【指针，指向】或【指针数组，指向】
 * const就读【常量】
 * 类型正常读
*/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	const int a = 123; 
	const int b = 456;
	const int *p1 = &a; // p(&a) -> a(123)<-cosnt 常量指向a，p中的值可以改变
	printf("*p1 = %d\n", *p1);
	p1 = &b;
	printf("*p1 = %d\n", *p1);

	int const *p2 = &a; // 与const int一样
	int n = 789, m = 1000;
	int *const p3 = &n; // const->p(&n) -> n(789) 指针指向的值不能变
	// p3  = &m;
	return 0;
}
