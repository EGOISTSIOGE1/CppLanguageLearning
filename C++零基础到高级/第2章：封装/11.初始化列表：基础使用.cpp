/*************************************************************************
	> File Name: 11.初始化列表：基础使用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 14 Jul 2024 01:01:34 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A() : A(1, 1) {}	// 委托构造
	A(int x, int y) : x(x), y(y) {}
	void output() {
		cout << "(" << x << ", " << y << ")" << endl;
		return ;
	}
private:
	int x, y;
};

int main(int argc, char const *argv[]) {
	A a(3, 4), b(101, 202), c;
	a.output();
	b.output();
	c.output();
	return 0;
}
