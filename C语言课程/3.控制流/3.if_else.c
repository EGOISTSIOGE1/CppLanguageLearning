/*************************************************************************
	> File Name: 3.if_else.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 11 Nov 2023 04:51:37 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int a, b, c;
	scanf("%d%d", &a, &b);
	if (a < b) printf("YES\n");
	else printf("NO\n");

	if (a < b) {
		c = a * b;
		printf("c = %d\n", c);
	}

	return 0;
}