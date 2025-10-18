/*************************************************************************
	> File Name: 7.scanf_c.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 18 Dec 2023 11:10:41 PM CST
 ************************************************************************/

/**
 * %d 读取整型
 * %c 直接读入当前字符
*/
#include<stdio.h>

int main(int argc, char const *argv[]) {
	char c1, c2;
	int a, b;
	scanf("%d", &a);
	scanf("%c%c", &c1, &c2);
	scanf("%d", &b);                      // 123 456
	printf("a = %d, b = %d\n", a, b);	  // a = 123  b = 56
	printf("c1 = %d, c2 = %d\n", c1, c2); // c1 = 32(" ") c2 = 52("4")

	return 0;
}
