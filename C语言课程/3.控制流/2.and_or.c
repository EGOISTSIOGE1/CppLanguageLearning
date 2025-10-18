/*************************************************************************
	> File Name: 2.and_or.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 11 Nov 2023 04:06:36 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	a < b && printf("YES\n"); // 短路原则，&&只有第一个为真就会直接返回真
	!(a < b) && printf("NO\n");
	return 0;
}