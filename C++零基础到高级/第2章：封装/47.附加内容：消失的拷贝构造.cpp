/*************************************************************************
	> File Name: 47.附加内容：消失的拷贝构造.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sat 07 Sep 2024 06:29:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
	A() {
		cout << "default constructor" << endl;
	}
	A(const A &a) {
		cout << "copy constructor" << endl;
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