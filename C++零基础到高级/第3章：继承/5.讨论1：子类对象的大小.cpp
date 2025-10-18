/*************************************************************************
	> File Name: 5.讨论1：子类对象的大小.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 13 Oct 2024 10:35:40 PM CST
 ************************************************************************/

/**
 * 1.子类中存储了子类独有的数据以及从父类中继承来的数据
 * 2.子类的对齐值受父类对齐值影响
 * 3.简单继承场景中：父类的数据在前，子类数据在后
 */

#include<iostream>
using namespace std;

#define P(class_name) { \
	printf("class %s : %lu\n", #class_name, sizeof(class_name)); \
}

class Base {
public:
	Base() : x(0x1111111111111111LL) {}
	long long x;
};

class A : public Base {
public:
	A() : y(0x22222222) {}
	int y;
};

void output_address(void *_p, size_t n) {
	unsigned char *p = (unsigned char *)(_p);
	printf("%p : ", p);
	for (int i = 0; i < n; i++) {
		if (i % 8 == 0) printf("\n");
		printf("%02X ", p[i]);
	}
	printf("\n");
	return ;
}

int main() {
	P(Base);
	P(A);
	A a;
	output_address(&a, sizeof(a));
	return 0;
}