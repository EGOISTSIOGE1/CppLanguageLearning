/*************************************************************************
	> File Name: 3.fprintf.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 17 Dec 2023 05:37:49 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	fprintf(stdout, "hello world\n");
	int n;
	fscanf(stdin, "%d", &n);
	fprintf(stderr, "n = %d\n", n);
	return 0;
}
