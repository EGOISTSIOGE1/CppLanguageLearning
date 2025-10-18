/*************************************************************************
	> File Name: 16.HZOJ-467.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 12:52:40 AM CST
 ************************************************************************/

#include<stdio.h>

long long f(int n) {
	if (n == 1) return 1;
	return n * f(n - 1);
}

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	printf("%lld\n", f(n));
	return 0;
}
