/*************************************************************************
	> File Name: 10.max_int.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 11:37:53 PM CST
 ************************************************************************/

/**
 * 如何获取a往后的参数列表？ va_list 类型的变量
 * 如何定位a后面第一个参数的位置？ va_start 函数
 * 如何获取下一个可变参数列表中的参数？ va_arg 函数
 * 如何结束整个获取可变参数列表的动作？ va_end 函数 
 */

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>

//第一个参数为取的个数，后面为变参数字
int max_int(int n, ...) {
	va_list args;
	va_start(args, n);
	int ans = INT32_MIN;
	for (int i = 0; i < n; i++) {
		int a = va_arg(args, int);
		if (a > ans) ans = a;
	}
	va_end(args);
	return ans;
}

int main(int argc, char const *argv[]) {
	printf("max_int(3, 8, 7, 9) = %d\n", max_int(3, 8, 7, 9));
	printf("max_int(2, 8, 7, 9) = %d\n", max_int(2, 8, 7, 9));

	return 0;
}
