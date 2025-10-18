/*************************************************************************
	> File Name: 2.function.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 20 Nov 2023 04:56:04 PM CST
 ************************************************************************/

/* gcc 2.function.c -lm gcc编译的时候可以直接加上-lm选项，-l为指定库，m为math库*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum(int a, int b) {
	return a + b;
}

double select_function(int flag, double x) {
	switch (flag) {
		case 1: return sqrt(x);
		case 2: return x * x;
		default: printf("error flag\n"); break;
	}
	return 0;
}

void print_hello_world(int n) {
	for (int i = 0; i < n; i++) {
		printf("hello world\n");
	}
	return ;
}

int main(int argc, char const *argv[]) {
	printf("3 + 4 = %d\n", sum(3, 4));
	printf("sqrt(3) = %lf\n", select_function(1, 3));
	printf("4 * 4= %lf\n", select_function(2, 4));
	print_hello_world(3);
	printf("-----------------------\n");
	print_hello_world(5);
	return 0;
}
