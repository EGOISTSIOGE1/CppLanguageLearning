/*************************************************************************
	> File Name: test2.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 05 Dec 2023 11:54:57 PM CST
 ************************************************************************/

#include<stdio.h>

int add(int a, int b) {
	return a + b;
}

int main(int argc, char const *argv[]) {
	int a = 123, b = 456;
	printf("a + b = %d\n", a + b);
	printf("add(%d, %d) = %d\n", a, b, add(a, b));
	return 0;
}