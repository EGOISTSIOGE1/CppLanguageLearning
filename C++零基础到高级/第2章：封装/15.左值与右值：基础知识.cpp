/*************************************************************************
	> File Name: 15.左值与右值：基础知识.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 04:27:31 PM CST
 ************************************************************************/

/**
 * 值 与 引用
 * 
 * 代码1
 * int a = 123;
 * int b = a;
 * 
 * 代码2
 * int a = 123;
 * int &b = a;
 * 
 * 左值 与 右值
 * 1.左值：持续存在的，可以取地址，可以出现在赋值语句左侧
 * 2.右值：字面量或匿名对象，不能出现在赋值语句左侧
 * 3.学习诀窍1：字面量一定是右值
 * 4.学习诀窍2：是否可以通过单一变量访问，可以通过单一变量进行访问的就是左值
 */

#include<iostream>
using namespace std;

#define TEST(expr) { \
	cout << #expr; \
	f(expr); \
}

void f(int &x) {
	cout << " is left value" << endl;
	return ;
} // 左值引用，优先绑定到左值上

void f(int &&) {
	cout << " is right value" << endl;
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