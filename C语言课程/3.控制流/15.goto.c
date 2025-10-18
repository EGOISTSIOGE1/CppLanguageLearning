/*************************************************************************
	> File Name: 15.goto.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 17 Nov 2023 10:49:44 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
	goto lab_1; 
	printf("hello world\n");
lab_1:
	printf("hello hangzhou\n");
//---------------------------------//
	goto lab_2;
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
lab_2:
	printf("%d\n", a * b);
	return 0;
}