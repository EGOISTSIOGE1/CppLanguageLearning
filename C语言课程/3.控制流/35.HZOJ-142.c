/*************************************************************************
	> File Name: 35.HZOJ-142.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 07:42:44 PM CST
 ************************************************************************/

/**
 * 回文数
 * 
 * a /= 10;
 * b = b * 10 + a % 10;
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
	int a, b, c = 0;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) {
		int flag = 1; //标记位
		for (int j = 2; j * j <= i && flag; j++) {
			if (i % j) continue;
			flag = 0;
		}
		if (flag == 0) continue;
		int x = i, y = 0;
		while (x) {
			y = y * 10 + x % 10;
			x /= 10;
		}
		if (y != i) continue;
		if (c) printf(" ");
		c += printf("%d", i);
	}
	printf("\n");
	return 0;
}
