/*************************************************************************
	> File Name: 6.test2.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 11 Nov 2023 05:28:39 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	switch (n) {
		case 1: printf("one\n"); break;
		case 2: printf("two\n"); break;
		case 3: printf("three\n"); break;
		default: printf("error\n"); break;
	}

	return 0;
}