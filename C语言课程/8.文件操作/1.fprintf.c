/*************************************************************************
	> File Name: 1.fprintf.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 23 Dec 2023 11:42:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
	FILE *fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("failed to open file\n");
		exit(1);
	}
	fprintf(fp, "hello world\n");
	int a = 123, b = 456;
	fprintf(fp, "a = %d, b = %d\n", a, b);
	fclose(fp); //关闭文件
	return 0;
}
