/*************************************************************************
	> File Name: 1.decl_def.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 06 Dec 2023 11:59:40 PM CST
 ************************************************************************/

#include<stdio.h>

int add(int, int);

extern int c, d; //声明变量

int main(int argc, char const *argv[]) {
	int a = 1, b = 2; //定义了两个变量
	printf("a + b + c + d = %d\n", a + b + c + d);
	return 0;
}

int add(int a, int b) {
	return a + b;
}