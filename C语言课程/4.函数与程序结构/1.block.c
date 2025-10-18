/*************************************************************************
	> File Name: 1.block.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 20 Nov 2023 11:43:45 AM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int a = 1, b = 2;
	for (int i = 0; i < 10; i++) {
		int a = 3, b = 4;
		printf("line 14: a = %d, b = %d\n", a, b);
	}
	printf("line 16: a = %d, b = %d\n", a, b);
	return 0;
}
