/*************************************************************************
	> File Name: 5.名称空间：基本使用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 22 Jun 2024 11:51:40 PM CST
 ************************************************************************/

/**
 * 1.通过域限定符::访问
 * 2.通过using引入
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

#define P(msg) { \
	printf("%s = %d\n", #msg, msg); \
}

int main(int argc, const char** argv) {
	std::cout << "hello world" << std::endl;

	apple::cnt += 2;
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