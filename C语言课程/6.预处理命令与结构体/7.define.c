/*************************************************************************
	> File Name: 7.define.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 08 Dec 2023 12:11:39 AM CST
 ************************************************************************/

/**
 * #define 用于最简单的替换
 * 宏只占一行
 * 
 * 定义符号常量：
 * 		#define PI 3.1415926
 * 		#define MAX_N 10000
 * 
 * 定义傻瓜表达式：
 * 		#define MAX(a, b) (a) > (b) ? (a) : (b)
 * 		#define S(a, b) a * b
 * 
 * 定义代码段：
 * 		#define P(a) { \ <- 续航符号
 * 			printf("%d\n", a); \
 * 		}
*/

#include<stdio.h>

#define PI 3.1415926
#define S(a, b) a * b
#define P(a) { \
	printf("define P : %d\n", a); \
}

int main(int argc, char const *argv[]) {
	printf("PI = %lf\n", PI);
	printf("S(3, 4) = %d\n", S(3, 4));
	printf("S(3 + 7, 4) = %d\n", S(3 + 7, 4));
	S(int, p);
	int n = 123;
	p = &n;
	P(*p);
	return 0;
}
