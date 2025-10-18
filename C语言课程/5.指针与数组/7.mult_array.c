/*************************************************************************
	> File Name: 7.mult_array.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 25 Nov 2023 10:00:40 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int b[3][4], cnt = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			b[i][j] = (cnt++);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d ", b[i][j]);
		}
		printf("\n");
	}
	printf("-----------------\n");
	cnt = 1;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			b[i][j] = (cnt++);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
