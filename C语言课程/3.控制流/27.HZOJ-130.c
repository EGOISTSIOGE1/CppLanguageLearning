/*************************************************************************
	> File Name: HZOJ-130.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 04:02:10 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int m, n;
	double yu = 0;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		yu += m;
		yu *= 1.00417;
	}
	printf("$%.2lf\n", yu);
	return 0;
}
