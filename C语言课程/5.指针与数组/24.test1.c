/*************************************************************************
	> File Name: 24.test1.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 28 Nov 2023 11:55:19 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int a, b, c, d;
	scanf("%d.%d.%d.%d", &a, &b, &c, &d);
	unsigned int n;
	char *p = (char *)&n;
	p[3] = a;
	p[2] = b;
	p[1] = c;
	p[0] = d;
	printf("n = %u\n", n);
	return 0;
}
