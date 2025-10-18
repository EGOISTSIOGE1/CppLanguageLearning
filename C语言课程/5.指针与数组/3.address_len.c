/*************************************************************************
	> File Name: 3.address_len.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 24 Nov 2023 12:05:06 AM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int a;
	double b;
	char c;
	printf("sizeof(int &) = %lu\n", sizeof(&a));
	printf("sizeof(double &) = %lu\n", sizeof(&b));
	printf("sizeof(char &) = %lu\n", sizeof(&c));
	return 0;
}
