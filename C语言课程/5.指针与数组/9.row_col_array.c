/*************************************************************************
	> File Name: 9.row_col_array.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 05:09:31 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int a[10][10]; // 数据存储方式为行序优先
	printf("&a[0][0] = %p\n", &a[0][0]);
	printf("&a[0][1] = %p\n", &a[0][1]);
	printf("&a[1][0] = %p\n", &a[1][0]);
	return 0;
}
