/*************************************************************************
	> File Name: 14.有参构造的特殊用法：转换构造.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 03:23:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A(int z) : x(z), y(z) {
		cout << this << " : convert constructor" << endl;
	}
	void operator=(const A &a) {
		this->x = a.x;
		this->y = a.y;
		cout << this << "operator=" << endl;
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
	A a(3), b{4}, c = 5;		// 在类中只有一个参数的构造函数，这就叫做转换构造
	a.output();
	b.output();
	c.output();
	a = 4;		// 整型能转换成A类对象，就是由于转换构造
	a.output();
	return 0;
}