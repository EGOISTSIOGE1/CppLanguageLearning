/*************************************************************************
	> File Name: 8.1.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 06:34:00 PM CST
 ************************************************************************/

/**
 * 贝祖等式
 * ax + by = gcd(a,b) = c a，b均为整数，一定存在整数解x，y
 * 
 * GCD过程
 * a, b -> b, a%b -> c, 0
 * y, x-ky <- x, y <- 1,0 
*/

#include<stdio.h>

int x, y, nx, ny;

int ex_gcd(int a, int b) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int c = ex_gcd(b, a % b);
	nx = y;
	ny = x - a / b * y;
	x = nx, y = ny;
	return c;
}

int main(int argc, char const *argv[]) {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		int c = ex_gcd(a, b);
		printf("%d * %d + %d * %d = %d\n", a, x, b, y, c);
	}
	return 0;
}
