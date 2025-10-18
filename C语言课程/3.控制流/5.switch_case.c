/*************************************************************************
	> File Name: 5.switch_case.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 11 Nov 2023 05:23:39 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	switch (a) {
		case 1: 
			printf("case a = 1\n");
			break;
		case 2: 
			printf("case a = 2\n");
			break;
		case 3: 
			printf("case a = 3\n");
			break;
		case 4: 
			printf("case a = 4\n");
			break;
		default: 
			printf("default value\n");
			break;
	}

	return 0;
}