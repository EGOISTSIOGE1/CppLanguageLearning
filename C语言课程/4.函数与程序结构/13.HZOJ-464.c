/*************************************************************************
	> File Name: 13.HZOJ-464.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 12:27:36 AM CST
 ************************************************************************/

#include<stdio.h>

int is_leap_year(int x) {
	if (x % 4 == 0 && x % 100 != 0) return 1;
	if (x % 400 == 0) return 1;
	return 0;
}

int main(int argc, char const *argv[]) {
	int x, y, ans = 0;
	scanf("%d%d", &x, &y);
	for (int i = x; i <= y; i++) {
		ans += is_leap_year(i);
	}
	printf("%d\n", ans);
	return 0;
}
