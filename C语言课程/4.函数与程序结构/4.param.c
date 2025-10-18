/*************************************************************************
	> File Name: 4.param.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 20 Nov 2023 05:36:37 PM CST
 ************************************************************************/

#include<stdio.h>

void test(int a, int b) {
	a += 1;
	b *= 2;
	printf("test: a = %d, b = %d\n", a, b);
	return ;
}

int main(int argc, char const *argv[]) {
	int a = 1, b = 2;
	test(a, b);
	printf("main: a = %d, b = %d\n", a, b);
	test(b, a);
	printf("main: a = %d, b = %d\n", a, b);
	return 0;
}
