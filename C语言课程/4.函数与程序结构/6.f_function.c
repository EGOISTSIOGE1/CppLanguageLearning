/*************************************************************************
	> File Name: 6.f_function.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Tue 21 Nov 2023 10:59:23 AM CST
 ************************************************************************/

#include<stdio.h>

int f(int n) {
	printf("in f(%d)\n", n);
	if (n == 1) return 1;
	int ret = n * f(n - 1);
	printf("out f(%d)\n", n);
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	while (~scanf("%d", &n)) { // ~表示输入取反，控制while循环，与scanf() != EOF相同
		printf("f(%d) = %d\n", n, f(n));
	}
	return 0;
}
