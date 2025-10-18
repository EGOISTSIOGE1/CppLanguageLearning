/*************************************************************************
	> File Name: 2.hex.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 23 Nov 2023 11:50:32 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int a = 0x6a;
	printf("a(10) = %d\n", a);
	printf("a(16) = %x\n", a);
	printf("a(16) = %X\n", a);
	int max_int = 0x7fffffff;
	printf("MAX_INT : %d\n", max_int);
	int min_int = 0x80000000;
	printf("MIN_INT : %d\n", min_int);
	printf("input hex : ");
	scanf("%x", &a);
	printf("a(10) = %d\n", a);
	printf("a(16) = %x\n", a);
	printf("a(16) = %X\n", a);
	return 0;
}
