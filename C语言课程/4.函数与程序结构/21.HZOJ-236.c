/*************************************************************************
	> File Name: 21.HZOJ-236.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 22 Nov 2023 11:39:18 AM CST
 ************************************************************************/

#include<stdio.h>

int arr[10];

void print_one_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
	return ;
}

void f(int i, int j, int n, int m) {
	if (i == m) {
		print_one_result(m);
		return ;
	}
	for (int k = j; k <= n && m - i - 1 <= n - k; k++) {
        arr[i] = k;
		f(i + 1, k + 1, n, m);
    }
	return ;
}

int main(int argc, char const *argv[]) {
	int n, m;
	scanf("%d %d", &n, &m);
	f(0, 1, n, m);

	return 0;
}
