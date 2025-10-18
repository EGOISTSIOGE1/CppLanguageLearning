/*************************************************************************
	> File Name: 22.HZOJ-108.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 11:48:16 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	char s[10];
	double n, m;
	scanf("%s", s);
	scanf("%lf%lf", &n, &m);
	printf("%.2lf\n", s[0] == 'r' ? m * n : m * n / 2.0);
	return 0;
}