/*************************************************************************
	> File Name: 20.function_with_pointer.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 26 Nov 2023 08:04:09 PM CST
 ************************************************************************/

#include<stdio.h>

void add_once(int *p) {
	*p += 1;
	return ;
}

void f(int n, int *sum_addr) {
	*sum_addr = (1 + n) * n / 2;
	return ;
}

void output(int *p, int n) {
	for (int i = 0; i < n; i++) {
		printf("p[%d] = %d\n", i, p[i]); //[]也是运算符，等价于 p[i] = *(p + i)
	}
	return ;
}

int main(int argc, char const *argv[]) {
	int a = 123;
	printf("a = %d\n", a);
	add_once(&a);
	printf("a = %d\n", a);
	int n = 10, sum;
	f(n, &sum); // sum是传出参数，与scanf同理
	printf("sum = %d\n", sum);
	int arr[10] = {9, 8, 5, 3, 6, 2, 1, 0, 4, 7};
	output(arr, 10);
	return 0;
}
