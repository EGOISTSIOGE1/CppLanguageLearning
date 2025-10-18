/*************************************************************************
	> File Name: 3.虚函数：让对象准确执行动作.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 12 Dec 2024 12:31:32 AM CST
 ************************************************************************/

/**
 * 虚函数是跟着对象走的
 */

#include<iostream>
using namespace std;

class Animal {
public:
	virtual void run() {
		cout << "I don't know how to run" << endl;
		return ;
	}
};

class Cat : public Animal {
public:
	void run() override {
		cout << "I can run with four legs" << endl;
		return ; 
	}
};

int main() {
	Cat c;
	Animal *p = &c;
	c.run();
	p->run();
	return 0;
}