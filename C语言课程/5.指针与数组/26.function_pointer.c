/*************************************************************************
	> File Name: 26.function_pointer.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 29 Nov 2023 12:23:39 AM CST
 ************************************************************************/

/**
 * C语言本质写在最后
 * 指针数组本质是数组
 * 数组指针本质是指针 int[10]*
 * 数组指针数组本质是数组，每个位置存储的是数组指针 int[10]* * n
 * 函数指针数组本质是数组，每个位置存储的是函数指针 (*p)() * n
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void test1() {
	printf("function test1\n");
	return ;
}

void test2() {
	printf("function test2\n");
	return ;
}

void test3() {
	printf("function test3\n");
	return ;
}

void (*p)(); // 函数指针p，表示p指针指向返回值为void，传入值为空的函数

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	p = test1;
	p();
	p = test2;
	p();
	p = test3;
	p();
	void (*arr[3])() = {test1, test2, test3}; // arr是函数指针数组，arr[0] ~ arr[2]
	for (int i = 0; i < 10; i++) {
		arr[rand() % 3]();
	}
	return 0;
}
