/*************************************************************************
	> File Name: 5.【override】关键字的作用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 12 Dec 2024 12:53:26 AM CST
 ************************************************************************/

/**
 * override用作代码检查
 */

#include<iostream>
using namespace std;

struct Base {
	virtual void test() {
		cout << "Base class test" << endl;
		return ;
	}

	virtual void foo() {
		cout << "Base class foo" << endl;
		return ;
	}
};

struct A : Base {
	void test() override {
		cout << "A class test" << endl;
		return ;
	}
	void foo() override {
		cout << "A class foo" << endl;
		return ;
	}
};

int main() {
	Base *p = new A();
	p->test();
	p->foo();
	return 0;
}