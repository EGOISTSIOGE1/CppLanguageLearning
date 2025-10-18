/*************************************************************************
	> File Name: 7.1.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 05:32:58 PM CST
 ************************************************************************/

/**
 * 欧几里得算法
 * 整数a,b的最大公约数一般表示为gcd(a, b), gcd(a, b) = gcd(b, a%b)
 * 证明: b和a%b的最大公约数，是a和b的公约数
*/

#include<stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
	int a , b;
	while (scanf("%d%d", &a, &b) != EOF) {
		printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
	}
	return 0;
}
