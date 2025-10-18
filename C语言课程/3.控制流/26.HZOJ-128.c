/*************************************************************************
	> File Name: 26.HZOJ-128.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 03:54:46 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0, a; i < n; i++) {
		scanf("%d", &a);
		sum += a;
	}
	printf("%.2lf\n", 1.0 * sum / n);
	return 0;
}
