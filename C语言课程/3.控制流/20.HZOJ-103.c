/*************************************************************************
	> File Name: 20.HZOJ-103.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 06:06:55 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%s\n", a % b == 0 ? "YES" : "NO");

	return 0;
}