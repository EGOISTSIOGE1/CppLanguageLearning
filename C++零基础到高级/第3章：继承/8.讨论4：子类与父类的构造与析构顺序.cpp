/*************************************************************************
	> File Name: 8.讨论4：子类与父类的构造与析构顺序.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Sun 13 Oct 2024 11:49:29 PM CST
 ************************************************************************/

/**
 * 先构造后析构
 * 父类先构造，子类后构造
 * 一定要把父类的析构函数设置成虚函数
 */

#include<iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base constructor" << endl;
	}
	virtual ~Base() {
		cout << "Base destructor" << endl;
	}
};

class A : public Base {
public:
	A() {
		data = new int[10];
		cout << "A constructor, data : " << data << endl;
	}
	~A() {
		if (data != nullptr) delete[] data;
		cout << "A destructor, data done" << endl;
	}
	int *data;
};

class B : public Base {
public:
	B() {
		cout << "B constructor" << endl;
	}
	~B() {
		cout << "B destructor" << endl;
	}
};

class C : public Base {
public:
	C() {
		cout << "C constructor" << endl;
	}
	~C() {
		cout << "C destructor" << endl;
	}
};

void func1() {
	cout << "func1 : " << endl;
	A a;
	return ;
}

void func2() {
	cout << "func2 : " << endl;
	Base *p = new A();
	// delete p;	// Base类型指针，会调用Base类型的析构函数，继承情况下会出现内存泄漏
	delete (A *)p;	// 子类的析构函数会自动调用父类的析构函数
	return ;
}

void func3() {
	cout << "func3 : " << endl;
	Base *p;
	switch (rand() % 3) {
		case 0: p = new A(); break;
		case 1: p = new B(); break;
		case 2: p = new C(); break;
	}
	delete p;	// 指向哪个对象？
	return ;
}

int main() {
	srand(time(NULL));
	func1();
	func2();
	func3();
	return 0;
}