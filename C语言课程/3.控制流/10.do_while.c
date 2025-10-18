/*************************************************************************
	> File Name: 10.do_while.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 12 Nov 2023 07:27:34 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int n, m = 0;
	scanf("%d", &n);
	do {
		n /= 10;
		m += 1;
	} while (n);
	printf("digits: %d\n", m);

	return 0;
}