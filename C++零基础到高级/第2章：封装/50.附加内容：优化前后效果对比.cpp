/*************************************************************************
	> File Name: 50.附加内容：优化前后效果对比.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 07 Sep 2024 06:51:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A() {
		cout << this << " : default constructor" << endl;
	}
	A(const A &a) {
		cout << this << " : copy constructor" << endl;
	}
};

A f() {
	A temp;
	cout << "temp : " << &temp << endl;
	return temp;
}

int main() {
	A a = f();
	cout << "a : " << &a << endl;
	return 0;
}