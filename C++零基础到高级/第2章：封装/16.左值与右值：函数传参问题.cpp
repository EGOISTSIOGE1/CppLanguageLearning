/*************************************************************************
	> File Name: 16.左值与右值：函数传参问题.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 04:58:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define TEST(expr) { \
	cout << #expr; \
	f(expr); \
}

void g(int &x) {
	cout << "g : left value" << endl;
	return ;
}

void g(int &&x) {
	cout << "g : right value" << endl;
	return ;
}

void f(int &x) {
	cout << " is left value" << endl;
	g(x);
	return ;
} // 左值引用，优先绑定到左值上

void f(int &&x) {
	cout << " is right value" << endl;
	// 虽然&&x是右值引用，但当单独去写x的时候，x是左值
	g(std::move(x));
	g(std::forward<int &&>(x)); // 使用forward去准确的传递参数
	return ;
} // 右值引用，优先绑定到右值上

int main() {
	int a = 12, b = 13;
	TEST(123);		// 右值
	TEST(12 + 23); // 右值
	TEST(a + b);	// 右值，匿名变量
	TEST(a);		// 左值
	TEST(b);		// 左值
	TEST(a++);		// 右值，a++是返回匿名变量的值
	TEST(++a);		// 左值，++a返回a变量的值，就是左值
	(++a) = 1001;
	cout << a << endl;
	return 0;
}