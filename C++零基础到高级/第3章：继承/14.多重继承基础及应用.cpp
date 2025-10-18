/*************************************************************************
	> File Name: 14.多重继承基础及应用.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 14 Nov 2024 12:08:29 AM CST
 ************************************************************************/

/**
 * 二、多重继承
 * 1.多重继承的基础知识
 * 2.菱形继承：困扰与解决方案
 * 3.初始：对象模型
 */

#include<iostream>
using namespace std;

class Base1 {};
class Base2 {};
class A : public Base1, protected Base2 {};

class Flyable {
public :
	void fly() {
		cout << "flying in the sky" << endl;
		return ;
	}
};

class Swimmable {
public :
	void swim() {
		cout << "swimming in the water" << endl;
		return ;
	}
};

// 	功能的拼装
class Duck : public Flyable, public Swimmable {
public :
	void quack() {
		cout << "Quack, Ga Ga Ga" << endl;
		return ;
	}
};

int main() {
	Duck d;
	d.fly();
	d.swim();
	d.quack();

	return 0;
}