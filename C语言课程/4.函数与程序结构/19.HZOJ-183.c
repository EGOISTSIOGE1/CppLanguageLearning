/*************************************************************************
	> File Name: 19.HZOJ-183.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 01:01:04 AM CST
 ************************************************************************/

#include<stdio.h>

int f(int x) {
	if (x <= 0) return 0;
	if (x == 1) return 1;
	if (x % 2 == 0) return 3 * f(x / 2) - 1;
	return 3 * f((x + 1) / 2) - 1;
}

int main(int argc, char const *argv[]) {
	int x;
	scanf("%d", &x);
	printf("%d\n", f(x));
	return 0;
}