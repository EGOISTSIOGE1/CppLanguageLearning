/*************************************************************************
	> File Name: 6.名称空间：作用总结.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 23 Jun 2024 12:04:36 AM CST
 ************************************************************************/

/**
 * 名称空间：总结
 * 1.避免程序中，不同代码段中相同变量名的冲突
 * 2.提高程序的【可读性】、【可维护性】与【可拓展性】
 * 3.匿名的名称空间，可以取代【静态全局变量】
 * 4.类是一种特殊的名称空间
 */

#include<iostream>
// using namespace std;

namespace apple {
	int cnt = 0;
	void inc() {
		cnt += 1;
		return ;
	}
}

namespace banana {
	int cnt = 0;
	void inc() {
		cnt += 1;
		return ;
	}
}

namespace apple {
	void dec() {
		cnt -= 1;
		return ;
	}
}

namespace {
	int a = 1; // 静态全局变量 同static
}

#define P(msg) { \
	printf("%s = %d\n", #msg, msg); \
}

int main(int argc, const char** argv) {
	P(a);

	std::cout << "hello world" << std::endl;

	apple::cnt += 2;
	P(apple::cnt);
	apple::dec();
	P(apple::cnt);

	using banana::cnt;
	// using banana::inc;
	cnt += 100;
	P(apple::cnt);
	P(banana::cnt);

	using namespace banana;
	inc();

	P(apple::cnt);
	P(banana::cnt);

	return 0;
}