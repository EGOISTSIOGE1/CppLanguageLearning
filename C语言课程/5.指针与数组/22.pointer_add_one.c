/*************************************************************************
	> File Name: 22.pointer_add_one.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 27 Nov 2023 11:45:44 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char const *argv[]) {
	int a, *p1 = &a;
	double b, *p2 = &b;
	printf("&a = %p\n", &a);
	printf("p1 + 0 = %p\n", p1 + 0);
	printf("p1 + 1 = %p\n", p1 + 1);
	printf("p1 + 2 = %p\n", p1 + 2);
	printf("p1 + 3 = %p\n", p1 + 3);

	printf("&b = %p\n", &b);
	printf("p2 + 0 = %p\n", p2 + 0);
	printf("p2 + 1 = %p\n", p2 + 1);

	int arr[4] = {1,2,3,4};
	int *p3 = arr;
	for (int i = 0; i < 4; i++) {
		printf("p3 + %d = %p\n", i, p3 + i);
		printf("&arr[%d] = %p\n", i, &arr[i]);
	}

	int (*p4)[10] = 0x0; // 表示p4指针指向一个存储10个元素的整型数组类型 p4+1 => sizeof(int[10])
	int arr2[30][10];
	p4 = arr2;
	printf("p4 + 0 = %p\n", p4 + 0);
	printf("p4 + 1 = %p\n", p4 + 1);
	printf("p4 + 2 = %p\n", p4 + 2);

	int *p5[10]; // p5此时是个数组，变量名后面紧接着方括号，每个元素中存储一个整型变量地址
	int *(*p6[10])[20]; // 内部p6是一个指针数组，存储的部分是int *[20]变量的地址;
	return 0;
}
