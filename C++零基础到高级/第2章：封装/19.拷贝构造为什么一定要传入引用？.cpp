/*************************************************************************
	> File Name: 19.拷贝构造为什么一定要传入引用？.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 15 Jul 2024 12:14:51 AM CST
 ************************************************************************/

/**
 * 为什么引用？如果不是引用，就会一直构造下去，无穷尽
 * 为什么一定要加const？程序可能出现漏洞，去修改const类型的值，const只能绑定到const类型的引用上
 */

#include<iostream>
using namespace std;

class A {
public:
	A() : x(0), y(1) {
		cout << this << " default constructor" << endl;
	}
	A(const A &a) : x(a.x), y(a.y) {
		cout << this << " copy constructor" << endl;
	} // 拷贝构造，两个同类型的变量
	void operator=(const A &a) {
		cout << this << " operator=" << endl;
		return ;
	}
	void output() {
		cout << "(" << x << ", " << y << ")" << endl;
		return ;
	}
private:
	int x, y;
};

int main() {
	A a, b = a;		// 拷贝构造，两个同类型的变量
	b = a;			// 赋值语句
	cout << "a : " << &a << endl;
	cout << "b : " << &b << endl;
	a.output();
	b.output();
	return 0;
}