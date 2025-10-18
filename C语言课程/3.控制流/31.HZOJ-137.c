/*************************************************************************
	> File Name: 31.HZOJ-137.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 19 Nov 2023 04:54:55 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int n; 
	char ch = 'A';
	scanf("%d", &n);
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			printf("%c", ch);
			ch += 1;
		}
		printf("\n");
	}
	return 0;
}
