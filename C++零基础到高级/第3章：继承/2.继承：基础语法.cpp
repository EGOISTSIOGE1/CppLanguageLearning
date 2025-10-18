/*************************************************************************
	> File Name: 2.继承：基础语法.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 06 Oct 2024 08:58:05 PM CST
 ************************************************************************/

/**
 * class A : public Base
 * A类公有继承自Base类
 * A类以Base类作为基础，做功能扩展
 * A类：派生类、子类，Base类：基类、父类
 */

#include<iostream>
using namespace std;

class Animal {
public:
	Animal() {}
	void set(string name) { this->name = name; }
	void say() {
		cout << "My name is " << name << endl;
		return ;
	}

private:
	string name;
};

class Cat : public Animal {};
class Dog : public Animal {};
class Bat : public Animal {};

int main() {
	Cat a1;
	Dog a2;
	Bat a3;
	a1.set("Garfield");
	a2.set("Odie");
	a3.set("Dracula");
	a1.say();
	a2.say();
	a3.say();
	return 0;
}