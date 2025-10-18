/*************************************************************************
	> File Name: 25.offset.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 16 Dec 2023 10:57:56 PM CST
 ************************************************************************/

#include<stdio.h>

#ifdef OFFSET1
// 偏移量，要想计算就必须定义一个结构体变量
#define offset(T, d) ({ \
	T t; \
	(void *)(&t.d) - (void *)(&t); \
})

#else
// 如果以零地址开始开辟一个结构体变量，相应字段所存储的位置就是偏移量
#define offset(T, d) ((size_t)(&(((T *)(0))->d)))
#define start(addr, T, d) ((T *)(((void *)addr) - offset(T, d)))

#endif

struct A {
	int a;
	char b;
	double c;
};

int main(int argc, char const *argv[]) {
	printf("offset(A, a) = %lu\n", offset(struct A, a));
	printf("offset(A, b) = %lu\n", offset(struct A, b));
	printf("offset(A, c) = %lu\n", offset(struct A, c));
	struct A a;
	printf("%a = %p\n", &a);
	printf("start(&a.a, struct A, a) = %p\n", start(&a.a, struct A, a));
	printf("start(&a.b, struct A, b) = %p\n", start(&a.b, struct A, b));
	printf("start(&a.c, struct A, c) = %p\n", start(&a.c, struct A, c));

	return 0;
}
