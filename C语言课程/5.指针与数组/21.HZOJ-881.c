/*************************************************************************
	> File Name: 21.HZOJ-881.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 27 Nov 2023 11:28:37 PM CST
 ************************************************************************/

#include<stdio.h>

void swap(int *a, int *b) {
	// *a ^= *b;
	// *b ^= *a;
	// *a ^= *b;
	int tmp = *a;
    *a = *b;
    *b = tmp;
	return ;
}

int main(int argc, char const *argv[]) {	
	int a, b;
	scanf("%d%d", &a, &b); // 3 6
	swap(&a, &b); 
	printf("%d %d\n", a, b); // 6 3
	swap(&a, &a);
	printf("%d %d\n", a, b); // 0 3
	return 0;
}
