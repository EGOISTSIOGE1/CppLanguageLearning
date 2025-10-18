/*************************************************************************
	> File Name: 3.调用父类的构造函数.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 06 Oct 2024 09:51:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public:
	Animal() = delete;
	Animal(string name) : name(name) {}
	void say() {
		cout << "My name is " << name << endl;
		return ;
	}

private:
	string name;
};

class Cat : public Animal {
public:
	Cat(string name) : Animal(name) {}
};

class Dog : public Animal {
public:
	Dog(string name) : Animal(name) {}
};

class Bat : public Animal {
public:
	Bat(string name) : Animal(name) {}
};

int main() {
	Cat a1("Garfield");
	Dog a2("Odie");
	Bat a3("Dracula");
	a1.say();
	a2.say();
	a3.say();
	return 0;
}