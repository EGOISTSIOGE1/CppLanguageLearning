/*************************************************************************
	> File Name: 10.初探：this指针.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 13 Jul 2024 04:13:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A() : A(0, 0) {
		cout << this << " : default constructor" << endl;
	}
	A(int x, int y) {
		cout << this << " : param constructor" << endl;
		this->x = x, this->y = y;
	}
	void output() {
		cout << this << " : call function" << endl;
		cout << this->x << ", " << this->y << endl;
		return ;
	}
private:
	int x, y;
};

int main(int argc, const char** argv) {
	A a{10, 101}, b;
	cout << "a : " << &a << endl;
	cout << "b : " << &b << endl;
	a.output();
	b.output();
	a.output();
	return 0;
}