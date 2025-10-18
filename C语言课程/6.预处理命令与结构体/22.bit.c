/*************************************************************************
	> File Name: 22.bit.c
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 16 Dec 2023 06:01:36 PM CST
 ************************************************************************/

#include<stdio.h>

#define P(a, format) { \
	printf("%s = " format "\n", #a, a); \
}

struct A {	 // 结构体a每次开4个字节
	unsigned int a:1; // a变量只用二进制1位
	unsigned int b:2;
	unsigned int c:3;
};

int main(int argc, char const *argv[]) {
	P(sizeof(struct A), "%lu");
	struct A obj;
	obj.a = 15;
	obj.b = 15;
	obj.c = 13;
	P(obj.a, "%d");
	P(obj.b, "%d");
	P(obj.c, "%d");

	return 0;
}
