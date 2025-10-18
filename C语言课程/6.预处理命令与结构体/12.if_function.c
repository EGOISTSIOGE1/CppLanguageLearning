/*************************************************************************
	> File Name: 12.if_function.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 10 Dec 2023 04:05:31 PM CST
 ************************************************************************/

#include<stdio.h>

#ifdef CLOCK
void test1() {
	printf("this is test1\n");
	return ;
}
#endif

#ifdef PHONE
void test2() {
	printf("this is test2\n");
	return ;
}
#endif

int main(int argc, char const *argv[]) {
#ifdef CLOCK
	test1();
#endif

#ifdef PHONE
	test2();
#endif
	return 0;
}
