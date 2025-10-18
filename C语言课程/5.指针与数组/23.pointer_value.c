/*************************************************************************
	> File Name: 23.pointer_value.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 28 Nov 2023 12:23:49 AM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int n = 0x61626364; // a b c d
	char *p = (char *)&n; // 指针取值时只取其指向类型的字节大小数据
	printf("*(p + 0) = %c\n", *(p + 0)); // d
	printf("*(p + 1) = %c\n", *(p + 1)); // c
	printf("*(p + 2) = %c\n", *(p + 2)); // b
	printf("*(p + 3) = %c\n", *(p + 3)); // a

	// 为什么是反向输出的
	// 大端系统和小端系统，我们现在一般是小端系统
	// 小端系统中数字的低位存储在内存的低位，大端系统中数字的低位存储在内存的高位

	// a[b] = *(a + b)
	printf("p[0] = %c\n", p[0]); // d
	printf("p[1] = %c\n", p[1]); // c
	printf("p[2] = %c\n", p[2]); // b
	printf("p[3] = %c\n", p[3]); // a

	return 0;
}
