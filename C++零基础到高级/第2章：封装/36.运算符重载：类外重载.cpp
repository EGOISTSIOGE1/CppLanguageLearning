/*************************************************************************
	> File Name: 36.运算符重载：类外重载.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 25 Aug 2024 08:16:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A(int x, int y) : x(x), y(y) {}
	void output() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	int x, y;
};

A operator+(A a, A b) {
	return A(a.x + b.x, a.y + b.y);
}

int main() {
	A a(3, 4), b(7, 10);
	A c = a + b;
	c.output();
	return 0;
}