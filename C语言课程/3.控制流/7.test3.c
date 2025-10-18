/*************************************************************************
	> File Name: 7.test3.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 11 Nov 2023 05:33:22 PM CST
 ************************************************************************/

#include<stdio.h>

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	switch (n) {
		case 1: printf("one ");
		case 2: printf("two ");
		case 3: printf("three\n"); break;
		default: printf("error\n"); break;
	}

	return 0;
}