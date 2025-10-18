/*************************************************************************
	> File Name: 8.纯虚函数：设计对象的功能接口.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 30 Dec 2024 05:38:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Flyable {
public:
	virtual void fly() = 0;		// 接口类，抽象类
};

class Animal {
public:
	virtual void run() = 0;	// 纯虚函数，继承的类都需要强制重写该方法，用来定义接口
};

class Cat : public Animal {
public:
	void run() override {
		cout << "I can run with four legs" << endl;
		return ;
	}
};

// 菱形继承，尽量是一个实体+多个接口
class Bat : public Animal, public Flyable {
public:
	void run() override {
		cout << "I can run with two legs" << endl;
		return ;
	}
	void fly() override {
		cout << "I can fly, in the sky" << endl;
		return ;
	}
};

void f1(Flyable &obj) {
	cout << "this is obj : ";
	obj.fly();
	return ;
}

int main() {
	Cat c;
	Bat b;
	f1(b);
	c.run();
	return 0;
}