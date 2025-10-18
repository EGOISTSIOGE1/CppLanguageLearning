/*************************************************************************
	> File Name: 28.HZOJ-136.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 04:26:24 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 7; i <= n; i += 7) { 
		printf("%d\n", i);
	}
	return 0;
}
