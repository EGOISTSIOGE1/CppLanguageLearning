/*************************************************************************
	> File Name: 18.初探：拷贝构造函数.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 11:41:12 PM CST
 ************************************************************************/

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