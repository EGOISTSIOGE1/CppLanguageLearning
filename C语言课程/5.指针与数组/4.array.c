/*************************************************************************
	> File Name: 4.array.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 25 Nov 2023 04:28:43 PM CST
 ************************************************************************/

#include<stdio.h>

void test1() {
	int a[10]; // 0 ~ n-1 a[0] ~ a[9]
	for (int i = 0; i < 10; i++) {
        a[i] = 2 * i;
    }
	for (int i = 0; i < 10; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return ;
}

void test2() {
	int n;
	printf("input n :");
	scanf("%d", &n);
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++) {
        a[i] = 3 * i;
    }
	for (int i = 0; i < 2 * n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return ;
}

void test3() {
	int a[5] = {0};
	for (int i = 0; i < 5; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return ;
}

void test4() {
	int a[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return ;
}

void test5() {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	size_t size = sizeof(a) / sizeof(int);
	printf("sizeof(a) / sizeof(int) = %lu\n", size); // 总字节 / 整形字节 = 包含几个变量
	printf("a = %p\n", a);
	for (size_t i = 0; i < size; i++) {
		printf("&a[%ld] = %p\n", i, &a[i]);
	} 
	return ;
}

int main(int argc, char const *argv[]) {
	// test1();
	// test2();
	// test3();
	// test4();
	test5();
	return 0;
}
