/*************************************************************************
	> File Name: 2.stdout.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 05:19:23 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	printf("alskdjfliemzi121313");
	fflush(stdout); // 刷新文件 stdout本身就是文件
	*((int *)(0)) = 5;
	return 0;
}
