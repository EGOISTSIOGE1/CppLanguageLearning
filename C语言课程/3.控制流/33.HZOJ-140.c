/*************************************************************************
	> File Name: 33.HZOJ-140.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 05:50:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; i++) {
		int a_num = 2 * n - 2 * abs(i - n + 1) - 1;
		int b_num = abs(i - n + 1);
		char ch = 'A' + n - 1 - b_num;
		for (int j = 0; j < b_num; j++) printf(" ");
		for (int k = 0; k < a_num; k++) printf("%c", ch);
		printf("\n");
	}

	return 0;
}
