/*************************************************************************
	> File Name: 17.HZOJ_468.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 12:56:22 AM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a, b));
	return 0;
}
