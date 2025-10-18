/*************************************************************************
	> File Name: 11.main_2.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 11:55:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

// argc命令行中参数的个数，argv命令行中各参数的值，env为环境变量（为二维数组）
int main(int argc, char *argv[], char **env) {
	int flag = 0;
	for (char **p = env; p[0]; p += 1) {
		if (strcmp(p[0], "LOGNAME=tjy") == 0) {
			flag = 1;
            break;
		}
	}
	if (flag == 0) {
		printf("error log name, please use tjy\n");
		return 0;
	}
	printf("right call\n");
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return 0;
}
