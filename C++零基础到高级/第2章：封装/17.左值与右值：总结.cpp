/*************************************************************************
	> File Name: 17.左值与右值：总结.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 05:11:36 PM CST
 ************************************************************************/

/**
 * C++引用：总结
 * 1.区分三个概念：实参、形参、引用参数
 * 2.引用需要再定义时，完成【绑定】
 * 3.左值、右值、左值引用、右值引用
 * 
 * 左值引用和右值引用如果继续向下进行传递时，他们值得类型都会变成左值，如果想准确传递需要对右值引用做特殊处理，std::move和std::forward<int &&>
 * 优先绑定并不是说只能绑定
 */

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

void test(const int &x) {
	cout << "test function" << endl;
	return ;
} // 如果不把右值当作一个普通变量去修改的话，比如当作一个常量，就可以将右值绑定到左值引用上

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
	test(12 + 23);
	return 0;
}