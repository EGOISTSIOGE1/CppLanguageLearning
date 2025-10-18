/*************************************************************************
	> File Name: 16.虚函数的对象模型（下）.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Wed 08 Jan 2025 12:12:46 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	virtual void test() {
		cout << "test : Class Base" << endl;
		return ;
	}
	virtual void test2(int x) {
		cout << "test2 : Class Base, " << x << endl;
		return ;
	}
};

class A : public Base {
public:
	void test() override {
		cout << "test : Class A" << endl;
		return ;
	}
	void test2(int x) override {
		cout << "test2 : Class A, " << x << endl;
		return ;
	}
};

typedef void (*funcT)();
typedef void (*funcT2)(int);

int main() {
	A a;
	cout << "virtual table address : " << ((funcT**)(&a))[0] << endl;
	((funcT **)(&a))[0][0]();

	a.test2(100);
	((funcT2 **)(&a))[0][1](100);
	return 0;
}