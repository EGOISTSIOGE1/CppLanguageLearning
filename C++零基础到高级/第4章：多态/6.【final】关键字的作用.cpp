/*************************************************************************
	> File Name: 6.【final】关键字的作用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 12 Dec 2024 01:04:16 AM CST
 ************************************************************************/

/**
 * final 定义最后一个被重写的虚函数版本，不希望用户修改定义的方法类型
 */

#include<iostream>
using namespace std;

struct Base {
	virtual void test() {
		cout << "Base" << endl;
		return ;
	}
};

struct A : Base {
	void test() final {
		cout << "A" << endl;
	}
};

struct B : A {
	// void test() override {
	// 	cout << "B" << endl;
	// }
};

int main() {
	Base *p = new B();
	p->test();

	return 0;
}