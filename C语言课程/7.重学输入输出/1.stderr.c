/*************************************************************************
	> File Name: 1.stderr.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 05:12:27 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	printf("hello world\n"); // stdout
	int n;
	scanf("%d", &n); // stdin
	perror("out of range\n"); // stderr
	return 0;
}
