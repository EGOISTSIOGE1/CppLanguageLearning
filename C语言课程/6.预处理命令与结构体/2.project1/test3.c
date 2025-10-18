/*************************************************************************
	> File Name: test3.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 05 Dec 2023 11:33:18 PM CST
 ************************************************************************/

// nm -C test3.o

/*
                 U add
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U printf
*/

#include<stdio.h>

int add(int, int);

int main(int argc, char const *argv[]) {
	int a = 123, b = 456;
	printf("a + b = %d", a + b);
	printf("add(%d, %d) = %d\n", a, b, add(a, b));
	return 0;
}
