/*************************************************************************
	> File Name: 23.对象之间的【构造】与【析构】顺序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 21 Jul 2024 10:52:21 PM CST
 ************************************************************************/

/**
 * 1.对象之间：先构造的，后析构
 * 2.对象属性：先于对象构造，晚于对象析构
 */

#include<iostream>
using namespace std;

class A {
public:
	A(string name) : name(name) {
		cout << name << " constructor" << endl;
	}
	~A() {
		cout << name << " destructor" << endl;
	}
	string name;
};

class B {
public:
	B(A &a, string name) : a(a), name(name) {
		cout << name << " constructor" << endl;
		if (a.name == "c") {
			data = new int[10];
		} else {
			data = new int();
		}
	}
	~B() {
		if (a.name == "c") {
			cout << name << " destructor int[]" << endl;
			delete[] data;
		} else {
			cout << name << " destructor int" << endl;
			delete data;
		}
	}
private:
	string name; 
	A &a;
	int *data;
};

A c{"c"}, d{"d"};

int main() {
	B a{c, "a"}, b{d, "b"};
	return 0;
}