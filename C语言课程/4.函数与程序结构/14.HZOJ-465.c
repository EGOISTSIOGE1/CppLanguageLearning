/*************************************************************************
	> File Name: 14.HZOJ-465.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 12:39:14 AM CST
 ************************************************************************/

#include<stdio.h>

int digit(long long n, long long k) {
	if (k == 1) return n % 10;
	return digit(n / 10, k - 1);
}

int main(int argc, char const *argv[]) {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	printf("%d\n", digit(n, k));

	return 0;
}
