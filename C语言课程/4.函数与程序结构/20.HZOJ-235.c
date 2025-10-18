/*************************************************************************
	> File Name: 20.HZOJ-235.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 11:24:18 AM CST
 ************************************************************************/

#include<stdio.h>

int arr[10];

void print_one_result(int n) {
	for (int i = 0; i <= n; i++) {
		if (i) printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
	return ;
}

void f(int i, int j, int n) {
	if (j > n) return ;
	for (int k = j; k <= n; k++) {
		arr[i] = k;
		print_one_result(i);
		f(i + 1, k + 1, n);
	}
	return ;
}

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	f(0, 1, n);
	return 0;
}
