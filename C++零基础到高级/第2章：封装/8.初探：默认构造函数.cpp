/*************************************************************************
	> File Name: 8.初探：默认构造函数.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Fri 12 Jul 2024 12:42:39 AM CST
 ************************************************************************/

/**
 * 	构造/析构函数					使用方式
 * 	默认构造函数					 People a;
 * 	People(string name);		   	People a("hug");
 * 	People(const People &a);		拷贝构造，与=不等价
 * 	People(People &&a);				移动构造，C++重回神坛的关键
 *  ~People();						无
 */

#include<iostream>
using namespace std;

class A {
public:
	A() {
		cout << "default constructor" << endl;
		x = 10, y = 100;
	}
	void output() {
		cout << "(" << x << ", " << y << ")" << endl;
		return ;
	}
private:
	int x, y;
};

int main() {
	A a;		// 隐式调用
	a.output();
	// A b();	// 没有参数，引起的语法歧义，编译器会认为是函数声明。
	A b{};		// 显示调用使用大括号
	b.output();
	// b();
	return 0;
}

// A b() {
// 	cout << "hello function b" << endl;
// 	return A();
// }