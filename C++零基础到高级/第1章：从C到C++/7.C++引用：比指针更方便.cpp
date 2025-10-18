/*************************************************************************
	> File Name: 7.C++引用：比指针更方便.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 23 Jun 2024 11:44:05 PM CST
 ************************************************************************/

/**
 * 1.区分三个概念：实参、形参、引用参数，引用参数是实参的一个别名，形参是实参的一个拷贝
 * 2.引用需要在定义时，完成【绑定】
 * 3.左值、右值、左值引用、右值引用
 */

#include<iostream>
using namespace std;

void c_swap(int *pa, int *pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
	return ;
}

// 引用参数就代表他所对应的实际参数
void cpp_swap(int &pa, int &pb) {
	int c = pa;
	pa = pb;
	pb =c;
	return ;
}

#define P(msg) { \
	printf("%s = %d\n", #msg, msg); \
}

void inc(int &x) {
	x += 1;
	return ;
}

int main() {
	int a = 3, b = 6;
	int &c = a;
	// P(a);
	// P(b);
	// c_swap(&a, &b);
	// P(a);
	// P(b);

	P(a);P(b);
	cpp_swap(a, b);
	P(a);P(b);
	inc(a), inc(a);
	inc(b);
	P(a);P(b);
	c += 100;
	P(a);P(b);P(c);

	return 0;
}
