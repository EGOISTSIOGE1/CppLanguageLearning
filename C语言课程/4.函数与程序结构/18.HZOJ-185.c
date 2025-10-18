/*************************************************************************
	> File Name: 18.HZOJ-185.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 12:59:22 AM CST
 ************************************************************************/

#include<stdio.h>

int f(int n) {
	if (n <= 2) return 1;
	return f(n - 1) + f(n - 2);
}

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}
