/*************************************************************************
	> File Name: 11.main_2.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 11:55:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

// argc命令行中参数的个数，argv命令行中各参数的值
int main(int argc, char *argv[]) {
	// strcmp比较两个字符串，相等返回0，大于返回大于1的值，小于返回小于1的值
	if (strcmp(argv[0], "./bilibili") != 0) {
		printf("wrong call, please call : ./bilibili\n");
		return 0;
	} 
	printf("right call\n");
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return 0;
}
