/*************************************************************************
	> File Name: 21.HZOJ-107.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 11:44:09 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n % 7 == 0 && n % 2 != 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}