/*************************************************************************
	> File Name: 9.讨论5：显示调用父类的构造函数.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Mon 14 Oct 2024 12:17:21 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public:
	Base() : x(3){
		cout << "Base default constructor" << endl;
	}
	Base(int x) : x(x) {
		cout << "Base(int x) constructor" << endl;
	}
	int x;
};

class A : public Base {
public:
	A() : y(4) {	// 在子类中调用父类的有参构造
		cout << "A default constructor" << endl;
	}
	A(const A &obj) {
		this->y = obj.y;
	}
	int y;
};

ostream &operator<<(ostream &out, const A &a) {
	out << "class A (" << a.x << ", " << a.y << ")";
	return out;
}


int main() {
	A a;
	cout << a << endl;
	a.x = 1000, a.y = 999;
	A b = a;
	cout << b << endl;
	return 0;
}